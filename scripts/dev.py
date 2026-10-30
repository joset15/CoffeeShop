"""Usual tasks of the CoffeeShop project: build, tests, AddressSanitizer, coverage and MSBuild.

Run it from any folder and any terminal: on Windows it sets up the x64 Visual Studio environment
by itself (no "x64 Native Tools" prompt needed) and runs `conan install` when the GoogleTest
package for the configuration is missing. The same commands run locally and in the CI.

    python scripts/dev.py help
"""

import argparse
import os
import platform
import shutil
import subprocess
import sys
import xml.etree.ElementTree as ElementTree
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD_DIR = ROOT / "build"
GENERATORS_DIR = BUILD_DIR / "generators"
CONFIGS = ("Debug", "Release")


class DevError(Exception):
    """A step failed; the message says which one and how to fix it."""


# ------------------------------------------------------------------------------------------------
# Environment


def preset_name(config, asan=False):
    """Returns the CMake preset for a configuration (see CMakePresets.json)."""
    if platform.system() != "Windows":
        raise DevError("Only Windows is supported for now (the Linux build is planned).")
    return "Windows x64 Debug ASan" if asan else f"Windows x64 {config}"


def visual_studio_environment():
    """Returns the environment of the x64 Visual Studio developer prompt (vcvars64.bat)."""
    if os.environ.get("VSCMD_ARG_TGT_ARCH") == "x64":
        return dict(os.environ)  # Already an x64 developer environment.

    program_files = os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")
    vswhere = Path(program_files) / "Microsoft Visual Studio" / "Installer" / "vswhere.exe"
    if not vswhere.exists():
        raise DevError(f"Visual Studio not found ({vswhere} is missing).")
    installation = subprocess.run(
        [str(vswhere), "-latest", "-products", "*", "-requires",
         "Microsoft.VisualStudio.Component.VC.Tools.x86.x64", "-property", "installationPath"],
        capture_output=True, text=True, check=False,
    ).stdout.strip()
    vcvars = Path(installation) / "VC" / "Auxiliary" / "Build" / "vcvars64.bat"
    if not installation or not vcvars.exists():
        raise DevError("No Visual Studio with the C++ x64 tools was found.")

    result = subprocess.run(
        f'"{vcvars}" >nul && set', shell=True, capture_output=True, text=True, check=False,
    )
    if result.returncode != 0:
        raise DevError(f"{vcvars} failed.")
    return dict(line.split("=", 1) for line in result.stdout.splitlines() if "=" in line)


def user_llvm_tools_dir():
    """Returns LLVM_TOOLS_DIR from the user's environment variables in the registry.

    A terminal opened before the variable was set doesn't have it yet.
    """
    try:
        import winreg  # Windows only.

        with winreg.OpenKey(winreg.HKEY_CURRENT_USER, "Environment") as key:
            return winreg.QueryValueEx(key, "LLVM_TOOLS_DIR")[0]
    except (ImportError, OSError):
        return None


def build_environment():
    """Returns the environment to run CMake, CTest and MSBuild in."""
    env = visual_studio_environment()
    if "LLVM_TOOLS_DIR" not in env:
        llvm_tools_dir = user_llvm_tools_dir()
        if llvm_tools_dir:
            env["LLVM_TOOLS_DIR"] = llvm_tools_dir
    return env


def run(command, env, cwd=ROOT):
    """Runs a command, showing it first, and fails if it fails."""
    print(f"\n>>> {subprocess.list2cmdline(command)}", flush=True)
    executable = shutil.which(command[0], path=env.get("PATH", env.get("Path")))
    if executable is None:
        raise DevError(f"'{command[0]}' not found on PATH.")
    if subprocess.run([executable, *command[1:]], env=env, cwd=cwd, check=False).returncode != 0:
        raise DevError(f"'{subprocess.list2cmdline(command)}' failed.")


def conan_install(config, env):
    """Installs GoogleTest with Conan for a configuration, if it isn't installed yet."""
    if (GENERATORS_DIR / f"GTest-{config.lower()}-x86_64-data.cmake").exists():
        return
    if shutil.which("conan", path=env.get("PATH", env.get("Path"))) is None:
        raise DevError("Conan not found. Install Conan 1.x: python -m pip install \"conan<2\".")
    run(["conan", "install", ".", "-s", f"build_type={config}", "--build=missing"], env)


# ------------------------------------------------------------------------------------------------
# Commands


def command_build(args, env):
    """Configures and builds (with clang-tidy)."""
    conan_install(args.config, env)
    preset = preset_name(args.config)
    run(["cmake", "--preset", preset, *(["--fresh"] if args.fresh else [])], env)
    run(["cmake", "--build", "--preset", preset], env)


def command_test(args, env):
    """Configures, builds and runs the tests (CMake workflow preset)."""
    conan_install(args.config, env)
    fresh = ["--fresh"] if args.fresh else []
    run(["cmake", "--workflow", "--preset", preset_name(args.config), *fresh], env)


def command_asan(args, env):
    """Builds and runs the tests with AddressSanitizer (Debug, without clang-tidy)."""
    conan_install("Debug", env)
    fresh = ["--fresh"] if args.fresh else []
    run(["cmake", "--workflow", "--preset", preset_name("Debug", asan=True), *fresh], env)


def command_coverage(args, env):
    """Measures the tests' line coverage (Debug, OpenCppCoverage) and prints a summary."""
    conan_install("Debug", env)
    preset = preset_name("Debug")
    fresh = ["--fresh"] if args.fresh else []
    run(["cmake", "--preset", preset, "-DCOVERAGE_ENABLED=ON", *fresh], env)
    run(["cmake", "--build", "--preset", preset, "--target", "coverage"], env)
    print_coverage_summary(BUILD_DIR / preset / "coverage")


def print_coverage_summary(coverage_dir):
    """Prints the total line coverage, and adds it to the GitHub Actions job summary."""
    report = ElementTree.parse(coverage_dir / "cobertura.xml").getroot()
    covered = int(report.get("lines-covered"))
    valid = int(report.get("lines-valid"))
    percent = 100.0 * covered / valid if valid else 100.0
    print(f"\nCoverage: {percent:.1f}% of lines ({covered} of {valid}).")
    print(f"Report: {coverage_dir / 'html' / 'index.html'}")

    summary = os.environ.get("GITHUB_STEP_SUMMARY")
    if summary:
        with open(summary, "a", encoding="utf-8") as file:
            file.write("### Coverage\n\n| Lines | Covered | Total |\n|---|---|---|\n")
            file.write(f"| **{percent:.1f}%** | {covered} | {valid} |\n")


def command_msbuild(args, env):
    """Rebuilds the Visual Studio project CoffeeShop.vcxproj (warnings are errors)."""
    configs = CONFIGS if args.config is None else (args.config,)
    for config in configs:
        run(["msbuild", "CoffeeShop.vcxproj", "/t:Rebuild", f"/p:Configuration={config}",
             "/p:Platform=x64", "/m", "/nologo", "/v:minimal", "/warnaserror"], env)


def command_all(args, env):
    """What the CI checks: tests, AddressSanitizer, coverage and MSBuild (Debug and Release)."""
    args.config = "Debug"
    command_test(args, env)
    command_asan(args, env)
    command_coverage(args, env)
    args.config = None
    command_msbuild(args, env)


COMMANDS = {
    "build": command_build,
    "test": command_test,
    "asan": command_asan,
    "coverage": command_coverage,
    "msbuild": command_msbuild,
    "all": command_all,
}


# ------------------------------------------------------------------------------------------------
# Command line


class HelpOnErrorParser(argparse.ArgumentParser):
    """Shows the full help, with every command, when the command line is wrong."""

    main_parser = None  # Set on the parsers of the commands.

    def error(self, message):
        main = self.main_parser or self
        main.print_help(sys.stderr)
        if main is not self:
            sys.stderr.write(f"\n{self.format_usage()}")
        self.exit(2, f"\nerror: {message}\n")


def make_parser():
    """Builds the command line parser: one subcommand per task, plus `help`."""
    parser = HelpOnErrorParser(
        prog="python scripts/dev.py",
        description="Usual tasks of the CoffeeShop project. Every command sets up the x64 Visual\n"
        "Studio environment, and runs `conan install` first if GoogleTest is missing.",
        epilog="Examples:\n"
        "  python scripts/dev.py test                     build and run the tests (Debug)\n"
        "  python scripts/dev.py build --config Release   build Release\n"
        "  python scripts/dev.py all                      everything the CI checks\n\n"
        "python scripts/dev.py <command> -h shows the options of a command.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    commands = parser.add_subparsers(
        dest="command", metavar="<command>", parser_class=HelpOnErrorParser
    )
    commands.add_parser("help", help="show this help").main_parser = parser

    def add(name, help_text, config=True, config_default="Debug"):
        command = commands.add_parser(name, help=help_text, description=help_text)
        command.main_parser = parser
        if config:
            command.add_argument("--config", choices=CONFIGS, default=config_default,
                                 help=f"build configuration (default: {config_default or 'both'})")
        if name != "msbuild":
            command.add_argument("--fresh", action="store_true",
                                 help="configure from scratch (cmake --fresh)")

    add("build", "configure and build, with clang-tidy")
    add("test", "configure, build and run the tests (CMake workflow preset)")
    add("asan", "build and run the tests with AddressSanitizer (Debug)", config=False)
    add("coverage", "measure the tests' line coverage (Debug, OpenCppCoverage)", config=False)
    add("msbuild", "rebuild CoffeeShop.vcxproj with MSBuild, warnings as errors",
        config_default=None)
    add("all", "tests, AddressSanitizer, coverage and MSBuild Debug and Release (as the CI)",
        config=False)
    return parser


def main():
    """Runs the command given on the command line."""
    parser = make_parser()
    args = parser.parse_args()
    if args.command in (None, "help"):
        parser.print_help()
        return 0

    try:
        COMMANDS[args.command](args, build_environment())
    except DevError as error:
        print(f"\nerror: {error}\nRun 'python scripts/dev.py help' to see the commands.",
              file=sys.stderr)
        return 1
    print(f"\n'{args.command}' finished successfully.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
