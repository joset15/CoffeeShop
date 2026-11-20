# Analysis: quality and security tools

Every static analysis or quality tool that was tried on the project, with how it would be
integrated, what it costs, what it found compared with clang-tidy, and the decision. A tool that is
discarded stays here, so it isn't tried again without a reason.

The reference depends on the code:

- **C++:** clang-tidy (LLVM 23, about 490 checks, see "Code style" in `AGENTS.md`), which runs on
  every build and breaks it on any finding. A new tool stays only if it finds something relevant
  that clang-tidy doesn't.
- **Everything else** (Python in `scripts/`, the GitHub Actions workflows, and later the JavaScript
  and HTML of the Qt and Sciter frontends): clang-tidy doesn't analyze it, so a tool stays if it
  finds something relevant there.

| Tool | Kind | Status | Decision |
|---|---|---|---|
| clang-tidy 23 | Static analysis, at build time | In use | The reference |
| Compiler warnings | MSVC `/W4`, gcc `-Wall -Wextra` and more | In use | See `cmake/cpp_warnings.cmake` |
| AddressSanitizer, UndefinedBehaviorSanitizer | Dynamic analysis, in the tests | In use | ASan on Windows, ASan and UBSan on Linux |
| cppcheck 2.10 | Static analysis | **Discarded** (2026-11) | Nothing relevant that clang-tidy misses |
| DeepSource | External service, on every pull request | **On trial** (2026-11) | Nothing in the project's code; review it when `v0.7.0` is closed |
| CodeQL | Security, GitHub code scanning (default setup, Extended) | **In use** (2026-11) | Nothing in C++ or Python; two real findings in the workflows; it will also cover JavaScript |
| SonarQube Cloud | External service, automatic analysis | **On trial** (2026-11) | Nothing in C++ or Python; four findings in the workflows that CodeQL missed. Compare with DeepSource when `v0.7.0` is closed |
| Semgrep (Community) | Pattern-based rules | **Discarded for now** (2026-11) | No C++ rules in the Community edition; review it with the first frontend that has JavaScript |
| OpenSSF Scorecard | Repository security practices, a workflow | **In use** (2026-11) | Pinned dependencies and a security policy fixed; see its section |
| MSVC Code Analysis, native rules | Static analysis, in the Visual Studio project | **In use** (it already ran, silently) | Nothing found; a finding fails the MSBuild job |
| MSVC C++ Core Check | Static analysis (C++ Core Guidelines) | **Discarded** (2026-11) | Noise from GoogleTest's macros, `noexcept` suggestions and GSL rules; no real bug |
| Lizard 1.26.1 | Complexity metrics | **Discarded** (2026-11) | Low complexity; clang-tidy's cognitive complexity is enforced instead (threshold 15) |
| Dependency graph and Dependabot alerts | Known vulnerabilities in the dependencies GitHub can read | **In use** (2026-11) | Today it only sees the actions; more useful with JavaScript dependencies |
| Codecov | Coverage service, with badges | In use (2026-11) | Both systems' reports, one flag each; see "Scripts and CI" in `AGENTS.md` |

## cppcheck 2.10

**Discarded.** The `CPPCHECK_ENABLED` option, which had never run, was removed.

- **Integration:** CMake runs it on every file with `CMAKE_CXX_CPPCHECK`, or by hand with the
  compile commands of a build. It has to be installed on every machine and in the CI (Debian 12 has
  2.10 in `apt`).
- **How it was measured:** on Debian 12, over the 45 files of the `Linux GCC Debug` build
  (`--project=compile_commands.json --std=c++20`).

  | Mode | Findings |
  |---|---|
  | As `CPPCHECK_ENABLED` ran it: no options, errors only | No real ones. Without `--library=googletest` it reports a false `syntaxError` in each of the 17 test files, because it doesn't expand GoogleTest's macros |
  | `--enable=warning,style,performance,portability --library=googletest` | 2 `useStlAlgorithm`: use `std::transform` instead of the loop in `OrderRepository::describeOrders()` and in its test double |

- **Decision:** the only finding is a style suggestion that isn't clearer with C++20's
  `std::ranges::transform`. With C++23 (`std::ranges::to`) it is, so it is noted in
  `docs/ROADMAP.md`. Keeping the tool would mean installing it and keeping its options on three
  systems, for nothing that clang-tidy misses.
- **Reconsider it** with a newer cppcheck, or if clang-tidy is ever dropped.

## DeepSource

**On trial:** kept for now as a second opinion, although it finds nothing that clang-tidy misses.
Review it when the `v0.7.0` milestone is closed.

- **Integration:** a GitHub app with access to the repository, and `.deepsource.toml` (the C++
  analyzer only). It analyzes every pull request and the default branch, and shows the result as a
  status (`DeepSource: C & C++`) on the pull request. It is not a required check.
- **Configuration:** `exclude_patterns` skips the same legacy files as pre-commit's global
  `exclude` (the old Qt project and the old Visual Studio test project). Its default branch, in
  its own settings, must be `develop`: with `main` it had no baseline for the pull requests, and
  warned that the comparison might not be accurate.
- **How it was measured:** the open issues on the repository, before the exclusions.

  | Finding | File | Status |
  |---|---|---|
  | `<stdio.h>` instead of `<cstdio>` | `tests/pch.h` (legacy Visual Studio test project) | Fixed |
  | `MainWindow` can be a pointer to const | `ui_mainwindow.h` (generated by Qt's uic 5.12) | Excluded |

  Both were minor, and in files outside the build. **In the project's code (`include/`, `src/`,
  `apps/` and `tests/`) it found nothing.**
- **Cost:** none in the CI (it runs on DeepSource's side), and almost no maintenance. One more
  check on every pull request.
- **To remove it:** delete `.deepsource.toml`; deactivate the repository in DeepSource's dashboard;
  remove the repository from the app's access (GitHub > Settings > Applications > Installed GitHub
  Apps > DeepSource > Configure), which is what stops the analysis of every pull request; and update
  the tables here, in `AGENTS.md` and in the README.

## Semgrep (Community Edition) 1.185.0

**Discarded for now:** it has no rules for C++ in its free edition. **Review it when the first
frontend with JavaScript arrives** (QML's JavaScript with Qt, or Sciter's HTML and JavaScript), where
its community rules are many.

- **Integration:** a local tool (`pipx install semgrep`) or a CI job; no account needed for
  `semgrep scan`. The registry rulesets are downloaded at each run.
- **How it was measured:** on Debian 12, `semgrep scan --metrics=off --config <ruleset>` over
  `include/`, `src/`, `apps/` and `tests/`.

  | Ruleset | Rules that ran | Files | Findings |
  |---|---|---|---|
  | `p/c` | 2 C rules, only on `include/pch.h` | 1 | 0 |
  | `p/cpp` | Doesn't exist (HTTP 404 from the registry) | | |
  | `p/default` (1074 rules) | 47 "multilang" (generic patterns, e.g. secrets) and 5 C rules on `pch.h` | 89 | 0 |
  | `p/security-audit` (225 rules) | 2 "multilang" and 9 C rules on `pch.h` | 89 | 0 |

  No rule for C++ ran on the `.cpp` and `.hpp` files: its C/C++ support, "generally available" in
  its documentation, refers to the Pro rules, which need an account. Its default `.semgrepignore`
  also skips `tests/` (61 files).
- **Not tried:** the extra free registry rules that `semgrep login` offers, with an account.

## CodeQL (GitHub code scanning)

**In use**, with GitHub's default setup and the **Extended** query suite.

- **Integration:** enabled in the repository's settings (Settings > Code security > CodeQL
  analysis > Default); no file in the repository. It analyzes `develop` and every pull request, and
  shows its alerts in the Security tab and on the pull request. It detects the languages by itself:
  C/C++, Python and GitHub Actions today, JavaScript when a frontend adds it.
- **C/C++ without a build:** the default setup uses `build-mode: none`, which doesn't analyze
  generated code and can be less precise than a build. A build would need an advanced setup (a
  workflow of its own); not worth it while it finds nothing in C++.
- **How it was measured:** CodeQL 2.27.4 on `develop`, with both query suites.

  | Language | Default | Extended |
  |---|---|---|
  | C/C++ | 58 rules, 0 alerts | 95 rules, 0 alerts |
  | Python (`scripts/dev.py`) | 43 rules, 0 alerts | 50 rules, 0 alerts |
  | GitHub Actions | 17 rules, 0 alerts | 23 rules, **2 alerts** |

  The two alerts were `actions/unpinned-tag` (medium): `codecov/codecov-action@v7`, a third-party
  action used by a mutable tag in a job that has the `CODECOV_TOKEN` secret. Fixed by pinning it by
  commit SHA, with the version in a comment; Dependabot keeps updating it. GitHub's own actions
  (`actions/*`) are published immutable, so it doesn't report them.
- **Cost:** its runs are GitHub Actions jobs that GitHub manages, free for public repositories
  (with a private repository it needs GitHub Code Security, which is paid). No maintenance.
- **Decision:** kept. In C++ it agrees with clang-tidy, but it analyzes what clang-tidy can't: the
  Python script, the workflows (where it found something real), and the future JavaScript.

## Dependency graph and Dependabot alerts

**In use**, enabled in the repository's settings (Settings > Code security): no file in the
repository. Dependabot alerts were already on; the dependency graph was enabled on 2026-11-20.

- **What it sees** (no open alerts when enabled):

  | Dependency | From |
  |---|---|
  | `actions/checkout`, `actions/cache`, `actions/setup-python`, `actions/upload-artifact`, `codecov/codecov-action` | The workflows. Codecov's version is read from the comment next to its SHA |
  | `Microsoft.googletest...` 1.8.1.4 (NuGet) | `tests/packages.config`, of the legacy Visual Studio test project, outside the build |

- **What it doesn't see:** GoogleTest 1.14.0 from Conan, which the build uses (GitHub doesn't read
  `conanfile.txt`), and the tools that the CI installs with `pip` inside the workflows (no
  dependency file). So an alert about GoogleTest 1.8.1 would be about a legacy file; it goes away
  when the Qt frontend replaces the legacy files (`v0.9.0`).
- **Decision:** kept, as it costs nothing. Today it adds little next to Dependabot's monthly updates
  of the actions; it will matter with the frontends' JavaScript dependencies (`package.json`). The
  automatic security updates (a pull request per alert) are left off until then.

## SonarQube Cloud

**On trial:** kept until the `v0.7.0` milestone is closed, and then compared with DeepSource, which
plays the same role and found nothing that SonarQube Cloud doesn't.

- **Integration:** the organization `joset15` on sonarcloud.io, with the free plan for open source,
  and the project `joset15_CoffeeShop` with **automatic analysis**: no file, secret or CI job in the
  repository. It analyzes `develop` and every pull request, which it decorates. Its results are
  public (https://sonarcloud.io/project/overview?id=joset15_CoffeeShop) and can be read through its
  API. Automatic analysis doesn't take coverage (Codecov has it) and can't be combined with a
  CI-based analysis.
- **How it was measured:** the first analysis of `develop`, 4051 lines (C++ 3529, C 89 for the
  `.h` files, YAML 218, Python 211, XML 4).

  | Code | Findings |
  |---|---|
  | C++, C and Python | None: no bugs, code smells, vulnerabilities or security hotspots, and 0% duplication |
  | GitHub Actions workflows | 6 "major" vulnerabilities (security rating C) |

  | Rule | Where | Finding | What was done |
  |---|---|---|---|
  | `githubactions:S7637` (2) | `ci.yml`, the two uses of `codecov/codecov-action@v7` | Use the full commit SHA | The same as CodeQL's two alerts; fixed by pinning the SHA |
  | `githubactions:S8544` (2) | `setup-linux/action.yml` and the pre-commit job in `ci.yml` | `pip install` without exact versions (`cmake>=3.30,<4`, `ninja`, `pre-commit`) | Exact versions: `cmake==3.31.10`, `ninja==1.13.2`, `pre-commit==4.7.0` |
  | `githubactions:S8541` (2) | The same two lines | Without `--only-binary :all:`, pip may run a package's setup scripts | `--only-binary :all:` for every tool, **except Conan 1**: it is only published as source (1.61.0 and 1.66.0, the last 1.x, have no wheel), so pip builds it, and also two of its dependencies (`patch-ng`, `pluginbase`). Accepted in SonarQube Cloud until the migration to Conan 2, which publishes wheels. As it was a new line, the pull request's quality gate ("Sonar way") failed until it was accepted |

  The Windows setup wasn't reported: its `pip install`s already use exact versions.
- **Compared with the other tools:** in C++ it agrees with clang-tidy. In the workflows it found
  four things that CodeQL didn't (how the tools are installed with pip), next to the two they both
  found.
- **Cost:** none in the CI (it runs on SonarQube Cloud's side), and one more check on every pull
  request. It also covers JavaScript and HTML, for the frontends.

## OpenSSF Scorecard

**In use**, with `.github/workflows/scorecard.yml`. It scores the repository's security practices,
not the code.

- **Integration:** `ossf/scorecard-action` on every push to `develop`, on pull requests (an
  experimental trigger: it analyzes but doesn't publish) and every Monday. The results go to the
  Security tab (as CodeQL's) and to an artifact; from `develop` they are also published, for its
  public API and badge (https://scorecard.dev/viewer/?uri=github.com/joset15/CoffeeShop).
  Publishing has rules: no workflow-level write permissions, an Ubuntu runner and only a few
  allowed actions. The workflow has `contents: read` at its level, not `read-all`, as SonarQube
  Cloud asked (`githubactions:S8234`).
- **How it was measured:** its first analysis, on pull request #44.

  | Check | Before | After | What was done |
  |---|---|---|---|
  | Pinned-Dependencies | 5/10 | 8/10 | Every action pinned by commit SHA, with its version in a comment (Dependabot updates them). What is left: `pip install` without hashes, accepted: the versions are exact and come from wheels only |
  | Security-Policy | 0/10 | Fixed | `SECURITY.md`, with GitHub's private vulnerability reporting (enabled in the repository's settings) |
  | SAST | 0/10 | | It looks at merged pull requests: it grows with CodeQL on the next ones |
  | Fuzzing | 0/10 | | Planned for `v0.8.0` |
  | Binary-Artifacts, Dangerous-Workflow, Dependency-Update-Tool, License, Packaging, Token-Permissions, Vulnerabilities | No findings | | |

- **Published score:** **7/10** after the first run on `develop` (2026-11-20). Some checks only show
  up there:

  | Check | Score | Why, and what could be done |
  |---|---|---|
  | Maintained, Security-Policy, Token-Permissions, Dangerous-Workflow, Dependency-Update-Tool, Binary-Artifacts, Vulnerabilities, License, CI-Tests | 10 | |
  | Pinned-Dependencies | 8 | `pip install` without hashes, accepted (see above) |
  | Branch-Protection | 3 | `develop` and `main` aren't fully protected. A ruleset could require a pull request and the CI jobs, and block force pushes: it also protects the owner from mistakes. An idea in the roadmap |
  | SAST | 2 | Not every merged pull request was analyzed yet; it grows with CodeQL |
  | Code-Review | 0 | No pull request has an approval: the only developer can't approve their own. Accepted |
  | CII-Best-Practices | 0 | The project isn't registered at https://www.bestpractices.dev (free, a self-assessment with its own badge). An idea in the roadmap |
  | Fuzzing | 0 | Planned for `v0.8.0` |
  | Contributors | 0 | Counts contributors from other organizations. Doesn't apply |
  | Packaging, Signed-Releases | No score | No workflow publishes packages; Signed-Releases says "no releases found" although there are releases (not looked into) |

  Each check below 10 is an open alert in the Security tab; it closes by itself when the check
  reaches 10.
- **Cost:** a job of about 20 seconds on Linux. The actions it uses are pinned by SHA.

## MSVC Code Analysis (`/analyze`)

The analyzer of Visual Studio's compiler, with two kinds of rules. Measured on 2026-11-20 in build
folders of their own, with clang-tidy and ccache off, leaving out external headers
(`/analyze:external-`, `/external:anglebrackets`).

| Rules | Findings | Decision |
|---|---|---|
| Native (`NativeRecommendedRules`, `C6xxx`: null pointers, buffer overruns, uninitialized memory...) | 0 | **In use**, in the Visual Studio project |
| C++ Core Check (`CppCoreCheckRules`, `C26xxx`) | 397, none a real bug | **Discarded** |

- **The native rules already ran** in the Visual Studio project: its Debug configuration has
  `RunCodeAnalysis`, which compiles with `/analyze` and `NativeRecommendedRules`. MSBuild passes
  `/analyze:quiet`, so nothing showed in the console, but a finding is reported as a warning, and
  `dev.py msbuild` builds with `/warnaserror`: a deliberate null pointer dereference (`C6011`) in
  `src/` made the MSBuild job fail. It analyzes the app's 25 files, without the tests; no extra cost.
  It may find more in the future than today, with more complex or Windows-specific code: it is a
  different engine from clang-tidy's `clang-analyzer-*`.
- **C++ Core Check** found 397 warnings: 367 in the tests, from GoogleTest's macros (globals that
  `TEST` creates, `new` inside them, a hidden `operator=`, `switch`es without `default`); and 30 in
  the project's code: 25 "can be declared `noexcept`" (F.6) and one default constructor; 2 arithmetic
  overflows in `ConsoleMenu.cpp` that are false positives (the number is checked to be at least 1);
  and 2 that ask for `gsl::narrow` (the project doesn't use the GSL). The `noexcept` suggestions are
  noted as an idea in the roadmap.
- **Cost:** a clean build took 25 s without analysis, 51 s with the native rules and 49 s with Core
  Check.
- **Pitfall when measuring it again:** `/analyze` writes its warnings as `file(line) : warning`, with
  a space before the colon. A pattern for `file(line): warning` found none, which looked like a
  clean result; a deliberate defect showed the mistake.

## Lizard 1.26.1

**Discarded:** the code's complexity is low, and clang-tidy already enforces a limit.

- **Integration:** a Python tool (`pip install lizard`); a pre-commit hook or a GitHub Action would
  have to come from third parties.
- **How it was measured:** `lizard -l cpp include src apps tests` on Windows, 209 functions.

  | Metric | Result |
  |---|---|
  | Default thresholds (cyclomatic complexity 15, length, parameters) | None exceeded |
  | Cyclomatic complexity | 178 functions with 1; the highest is 10 (`TeaBuilder::addMilk`) |
  | Longest function | 38 lines (`run`, in `main.cpp`) |
  | Most parameters | 4 |

  The three `addMilk` are the "most complex" because Lizard counts each `case`, and their `switch`es
  list every value of the enum (see "Code style" in `AGENTS.md`). Cognitive complexity counts a
  `switch` once.
- **Instead:** clang-tidy's `readability-function-cognitive-complexity`, which breaks the build,
  went from its default threshold (25) to **15** in `.clang-tidy`. The highest today is 6 (`run`, in
  `main.cpp`). SonarQube Cloud also shows the complexity of each function.
