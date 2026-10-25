# AGENTS.md

## Project overview

CoffeeShop is a C++17 learning project for managing drink orders. It is laid out
as Clean Architecture and uses classic GoF patterns:

| Layer | Headers | Sources | Notes |
|---|---|---|---|
| Domain | `include/Domain/` | `src/Domain/` | `Beverages` (`IBeverage`, `Coffee`, `Tea`, ...), `Ingredients` (decorators over `IBeverage`: `Sugar`, `Milk`, ...), `BeverageFactories` (singleton factories), `BeverageBuilder` (`IBeverageBuilder` interface, `BeverageBuilderBase` with the shared state, concrete builders, `BeverageBuildDirector`) |
| Application | `include/Application/UseCases/` | `src/Application/UseCases/` | Use cases and their ports (`IOrderRepository`, `IUseCaseInputPort`, ...) |
| InterfaceAdapters | `include/InterfaceAdapters/` | `src/InterfaceAdapters/` | Controller, presenters, `OrderRepository`, `Gateways/OrderDiskDataSource` |
| Infrastructure | `include/Infrastructure/UI/` | `src/Infrastructure/UI/` | `ConsoleMenu`: console menus that read the user's choices from a stream (library `ConsoleUi`, grouped in the `Infrastructure` interface target) |
| App | n/a | `apps/ConsoleApp/main.cpp` | `CoffeeShopApp` executable: wires `ConsoleMenu`, `BeverageController` and `OrderRepository` |

Dependencies point inward: Domain must not include Application, InterfaceAdapters or Infrastructure
headers. Infrastructure (UI) is the outermost layer; menu texts belong there, not in the Domain.

### Beverages and ingredient rules

Each `BeverageVariety` has a builder, created by `BeverageBuilderSimpleFactory`.
`BeverageBuildDirector::buildBeverage(ingredients)` adds the requested ingredients in a fixed order
(sugar, milk, honey, lemon, water) and returns `false` as soon as the builder refuses one, or if two
kinds of milk (milk, soy milk, cream) are requested together. A refused ingredient rejects the order.

| Family | Varieties (builder) | Sugar | Milk / soy milk / cream | Honey | Lemon | Water |
|---|---|---|---|---|---|---|
| Coffee | espresso, decaf (`CoffeeBuilder`) | yes | one kind | no | no | no |
| Coffee | latte (`CoffeeLatteBuilder`) | yes | no (it already has milk) | no | no | no |
| Tea | black, green (`TeaBuilder`) | yes | one kind, not with lemon | yes | not with milk | no |
| Cocoa | cocoa (`CocoaBuilder`) | yes | milk or soy milk (no cream) | yes | no | no |

Names in descriptions come from `inline constexpr std::string_view` constants next to each class
(`CoffeeEspressoName`, `SugarName`, ...). Ingredients build their part with
`IngredientDecorator::describeWith(XName)`, e.g. `"CoffeeEspresso, Sugar"`.

The tools are CMake (≥3.25; the presets file uses format v9, which needs ≥3.30), Ninja, MSVC (Visual Studio 2022), Conan **1.x**
(GoogleTest 1.8.1), clang-tidy, and pre-commit. `docs/README_development.md` shows the target folder
layout. Of its `Infrastructure` folders only `UI` exists; others it lists (`Infrastructure/DB`,
`libs`, `scripts`, ...) don't exist yet.

## Setup

- **Windows + MSVC only.** `src/CMakeLists.txt` stops with `FATAL_ERROR` for any compiler
  other than MSVC, so the `linux-default` preset does not work.
- Run from an **x64** Developer environment (x64 Native Tools prompt, or call
  `vcvars64.bat`). The presets use `architecture.strategy: external`, so CMake picks up whatever
  `cl` is on `PATH`. With the x86 `cl` the build fails at link time with
  `LNK4272: library machine type 'x64' conflicts with target machine type 'x86'` against the
  Conan gtest libs. In PowerShell, use
  `& "<VS>\Common7\Tools\Launch-VsDevShell.ps1" -Arch amd64 -HostArch amd64 -SkipAutomaticLocation`
  (the VS "Developer PowerShell" defaults to x86).
- The x86 environment also puts the **32-bit clang-tidy** (`VC\Tools\Llvm\bin`) first on `PATH`.
  It crashes (`0xC0000005`) on this project. The 64-bit one (`VC\Tools\Llvm\x64\bin`) works.
  Check with `where.exe clang-tidy`.
- GoogleTest comes from Conan. CMake finds it through `build/generators/` (added to
  `CMAKE_MODULE_PATH`), so that folder must exist. To regenerate it (Conan 1.x, `cmake_layout`):
  `conan install . -s build_type=Debug --build=missing`
- `ccache` is used automatically if it is on `PATH`. It can only cache MSVC builds with embedded
  debug info, so the CMake build uses `/Z7` (`CMAKE_MSVC_DEBUG_INFORMATION_FORMAT`) instead of
  `/Zi`; the linker still produces `.pdb` files. Check it with `ccache -s` (a second clean build
  should be all hits). clang-tidy still runs on every compile and is not cached. The VS solution
  (`CoffeeShop.sln`) is separate and keeps `/Zi`.
- Doxygen is needed only when `BUILD_DOC=ON`.

## Build

```bat
cmake --preset "Windows x64 Debug"          :: binary dir: build/Windows x64 Debug
cmake --build "build/Windows x64 Debug"
```

- Outputs: `build/<preset>/Debug/bin/{CoffeeShopApp,UnitTests,IntegrationTests}.exe`, libs in `.../lib`.
- The `Windows x64 Release` preset builds into `out/build/Windows x64 Release`. Conan generated
  only Debug gtest packages, so Release needs another `conan install` with `-s build_type=Release`.
- The `default` preset in `CMakeUserPresets.json` (from `build/generators/CMakePresets.json`)
  is a stale Conan preset (VS 2019 generator). Use the `Windows x64 *` presets instead.
- In-source builds are blocked.

CMake options (top-level `CMakeLists.txt`):

| Option | Default | Effect |
|---|---|---|
| `TESTS` / `ITESTS` | ON | Build unit / integration test executables |
| `CLANG_TIDY_ENABLED` | ON | Runs clang-tidy on every `.cpp` during the build, including the project headers under `include/` and `tests/` (`HeaderFilterRegex`). `.clang-tidy` has `WarningsAsErrors: '*'`, so tidy findings **break the build** |
| `BUILD_USING_PCH` | OFF | Precompiled headers. Can't be combined with `CLANG_TIDY_ENABLED` (configure stops with an error) |
| `ASAN_ENABLED` | OFF | MSVC `/fsanitize=address` in Debug |
| `CPPCHECK_ENABLED` | OFF | Runs cppcheck during the build |
| `BUILD_DOC` | OFF | Doxygen target `doc_doxygen` from `docs/doxygen/Doxyfile.in` |

## Testing

```bat
ctest --test-dir "build/Windows x64 Debug" --output-on-failure
ctest --test-dir "build/Windows x64 Debug" -R GivenSomeSugar     :: filter by regex
"build/Windows x64 Debug/Debug/bin/UnitTests.exe" --gtest_filter=GivenACoffee.*
```

- Framework: GoogleTest 1.8.1, linked with `GTest::gtest_main` (no hand-written `main`).
  Tests are registered with `gtest_discover_tests`.
- Layout (mirrors the domain folders):
  - `tests/UnitTests/<Area>/src/<Class>_Test.cpp` and `tests/UnitTests/<Area>/include/<Class>_TestFixtures.hpp`
  - `tests/IntegrationTests/<Area>/src/...` and `.../include/...` (parameterized tests use `*Parameterized_Test.cpp`)
- **New test files must be added by hand** to `SOURCES` in `tests/UnitTests/CMakeLists.txt` or
  `tests/IntegrationTests/CMakeLists.txt`. There is no globbing. If the test needs another library,
  add it to `target_link_libraries`.
- Conventions: fixtures are named `Given...` (e.g. `GivenSomeSugar`), test names are
  `When...Then...`, test code lives in `namespace coffee_shop`, and test bodies use
  `// Arrange`, `// Act`, `// Assert` comments.
- `tests/CoffeeShop_gtest.vcxproj`, `tests/test.cpp`, `tests/pch.*` belong to the legacy VS
  solution and are not part of the CMake build.
- All tests should pass. Add or update tests for any behavior you change.
- Expected descriptions use `describe({CoffeeLatteName, SugarName})` from
  `tests/Common/include/BeverageDescription_TestHelpers.hpp` (both test targets have that folder
  on their include path), because C++17 can't concatenate `std::string_view`s with `+`.
- `ConsoleMenu` takes a `std::istream`/`std::ostream`, so menu tests feed it a
  `std::istringstream` (see `tests/UnitTests/Infrastructure/`).
- To try the whole app without typing, redirect its input. Each line is one answer, `Enter`
  lines answer "Press Enter to continue", and the app exits on `0` or at the end of the input:
  ```bat
  :: menu_input.txt: 1, 6, "1 2", (empty), 2, (empty), 0  ->  order a cocoa with sugar and milk, list, exit
  "build\Windows x64 Debug\Debug\bin\CoffeeShopApp.exe" < menu_input.txt
  ```

## Code style

- clang-format (`.clang-format`): 2-space indent, **Allman braces**, 80 columns, `PointerAlignment: Right`
  (`const std::shared_ptr<IBeverage> &beverage`), sorted includes.
- clang-tidy checks (`.clang-tidy`): `clang-diagnostic-*`, `clang-analyzer-*`, `cppcoreguidelines-*`,
  `modernize-*` (except `modernize-use-trailing-return-type`), and `readability-identifier-naming`.
  Project choices: interfaces may declare only `virtual ~X() = default;` (`AllowSoleDefaultDtor`);
  `tests/.clang-tidy` inherits everything but allows `protected` members in GoogleTest fixtures.
  In practice: `override` (not `virtual`) on overrides, `[[nodiscard]]` on `const` getters,
  `= default`/`= delete` instead of empty bodies, and no `protected`, `const` or reference data
  members (store an injected dependency as a private pointer set from a reference).
  To see findings without building: `clang-tidy -p "build/Windows x64 Debug" <file.cpp>`.
- clang-tidy naming (`.clang-tidy`). It is enforced at build time:
  - Classes/structs: `CamelCase`. Interfaces are prefixed `I` (`IBeverage`, `IIngredientFactory`)
    and contain only pure virtual functions. Shared implementation goes in a `...Base` class
    (e.g. `BeverageBuilderBase`).
  - Functions/methods and local variables: `camelBack` (`getDescription`, `coffeeWithSugar`).
  - Private/protected data members: `m_` + `CamelCase` (`m_Beverage`, `m_Coffee`). Static
    variables are also `m_`. Public members (plain `struct`s) are `CamelCase` without prefix:
    the `MemberCasePrefix` key in `.clang-tidy` is not a real option, so no prefix is enforced.
  - Constants, constexpr, and enum constants: `CamelCase` (`SugarName`, `BeverageVariety::Cocoa`).
  - Macros: `UPPER_CASE`. Namespaces: `lower_case`.
- Headers are `.hpp`, sources `.cpp`. Use `#ifndef NAME_HPP` include guards. Include project
  headers relative to `include/`, e.g. `#include "Domain/Ingredients/Sugar.hpp"`.
- Use Doxygen comments (`/// @brief`, `/// @param`, `/// @return`) on public APIs.
- Use smart pointers (`std::shared_ptr`/`std::make_shared`, `std::unique_ptr`). Don't use raw `new`/`delete`.
- `.editorconfig`: UTF-8, final newline, trim trailing whitespace, native line endings.
- CMake files: 2-space indent, 100 columns, formatted by **gersemi** (`.gersemirc`) and linted by
  **cmake-lint** (`.cmakelintrc`). New targets follow the existing pattern: call
  `resolve_project_paths(...)` from `cmake/files_helper.cmake`, list `SOURCES` explicitly,
  `target_include_directories(<tgt> PRIVATE ${PUBLIC_INCLUDE_PATH})`, set the VS `FOLDER` property,
  and add the `BUILD_USING_PCH` `REUSE_FROM AllLayers` block.

### Adding a source file

1. Add the header under `include/<Layer>/...` and the source under `src/<Layer>/...`.
2. Add the `.cpp` to `SOURCES` in that folder's `CMakeLists.txt`.
3. The repo also contains a hand-maintained VS solution (`CoffeeShop.sln`, `CoffeeShop.vcxproj(.filters)`)
   and Qt files (`CoffeeShop.pro`, `CoffeeShopQt.vcxproj`, `mainQt.cpp`, `mainwindow.*`). These are
   separate from the CMake build. Ask before updating them.

## Lint / pre-commit

```bat
pre-commit run --all-files
```

- pre-commit is **run by hand** before committing. It is not installed as a git hook (don't run
  `pre-commit install`). The first run downloads the hook environments.
- The hooks are standard hygiene checks (trailing whitespace, YAML/JSON validity,
  `pretty-format-json --no-sort-keys`, large files, merge conflicts, mixed line endings,
  Windows-illegal names), cmake-lint, and gersemi. Some hooks (trailing whitespace, gersemi)
  fix files in place: review and stage those changes.
- `no-commit-to-branch` fails when the current branch is `main` or `staging`. Since the hooks are
  not installed, it only warns when you run them; it doesn't block the commit.
- There is no clang-tidy hook on purpose: the build already runs clang-tidy with
  `compile_commands.json` and fails on any finding.
- `CMakePresets.json` must be strict JSON (no `//` comments). Put notes in `"$comment"` fields.

## Git / PR guidelines

- Work on a feature branch created from `develop` (e.g. `feature/unique-ptr-decorator`).
  PRs target `develop`. `main` only receives merges from `develop`.
- Commit messages are one short sentence in past tense, ending with a period. Prefixes like
  `Improvement:` are optional, e.g. `Fixed "resolve_project_paths" cmake function.`
- Before committing, make sure the Debug preset builds (this also runs clang-tidy), `ctest` passes,
  and `pre-commit run --all-files` is clean.
- Don't commit build output (`build/`, `out/`, `Debug/`, `x64/`, `.vs/`), Conan artifacts
  (`conan.lock`, `conaninfo.txt`, `graph_info.json`, ...), or `CMakeUserPresets.json`. All of these are gitignored.
- Untracked scratch files at the root (`CMakePresets_01.json`, `CMakeSettings_OK.json`,
  `ClassDiagram.cd`, `req.txt`, ...) belong to the owner. Leave them alone.

## Gotchas

- Ninja only rebuilds changed `.cpp` files, so a new finding in a header shows up when a `.cpp`
  that includes it is recompiled. Use `--clean-first` to re-check everything.
- `apps/ConsoleApp/main.cpp` uses MSVC-specific `_CrtSetDbgFlag` (CRT leak checking).
- `CancelExistingOrderUC` is a compiled skeleton: `execute()` always returns `false` until
  `IOrderRepository` gets a way to cancel orders.
- An order the director can't fulfil completely is rejected, not partly served: see the rules
  table in "Beverages and ingredient rules". The menu then shows
  "Error: Order could not be added.".
- An existing build folder keeps old compiler flags in `CMakeCache.txt` after changes to CMake
  policies or debug-info settings. Reconfigure with `cmake --preset "Windows x64 Debug" --fresh`,
  or in Visual Studio use **Project > Delete Cache and Reconfigure**.
- Corrupt object files at link time (`LNK1163`, `LNK1236`) have appeared after incremental builds.
  A clean rebuild fixes them. Don't build the same folder from Visual Studio and the command line
  at the same time (both use `build/Windows x64 Debug`).
- On GCC/Clang the top-level file adds coverage flags when `TESTS=ON`. On Windows, coverage is
  collected with OpenCppCoverage (`.opencppcov/`).
