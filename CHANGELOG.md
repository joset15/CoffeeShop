# Changelog

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- MIT license. The repository is public.
- Codecov: the CI uploads the coverage of both systems, each with its own flag.
- README badges: coverage per system, last release and license. The CI badge shows `develop`.
- The CI also runs after every merge into `develop`, for the coverage badges and the caches.
- Quality and security tools: CodeQL (GitHub code scanning), SonarQube Cloud, OpenSSF Scorecard (a
  workflow), and the dependency graph with Dependabot alerts. Their badges in the README.
- `SECURITY.md`: how to report a vulnerability privately.
- `docs/analysis/quality-tools.md`: every tool tried, how it was measured and why it was kept or
  discarded.

### Changed

- The Windows coverage report (`cobertura.xml`) has paths relative to the repository, as on Linux.
- Every GitHub action is pinned by commit SHA. The tools the CI installs with pip have exact
  versions, and come from wheels only (except Conan 1, only published as source).
- clang-tidy's cognitive complexity threshold is 15 (it was the default, 25).

### Removed

- Option `CPPCHECK_ENABLED`: it had never run, and measured against clang-tidy, cppcheck 2.10 only
  suggested two `std::transform` loops.

## [0.6.0] - 2026-11-13

### Added

- Linux build with gcc 12 or later: `Linux GCC Debug` and `Linux GCC Release` presets. The tests, the
  coverage (gcovr) and the sanitizers also run on Linux.
- `scripts/dev.py` for the usual tasks on Windows and Linux: build, tests, sanitizers, coverage and,
  on Windows, MSBuild. It runs `conan install` when the package is missing, without letting Conan
  rewrite `CMakeUserPresets.json`.
- GitHub Actions workflow: tests and coverage, AddressSanitizer and the Visual Studio project on
  Windows; tests, sanitizers and coverage on Linux; and pre-commit. Dependabot keeps its actions up
  to date.
- CMake build, test and workflow presets, including `Windows x64 Debug ASan`,
  `Linux GCC Debug Sanitizers` (AddressSanitizer and UndefinedBehaviorSanitizer) and a `Coverage`
  preset per system.
- Option `UBSAN_ENABLED` (gcc and clang). A UBSan error makes the test fail.
- The console app run end to end as CTest tests (`tests/AppScenarios`).

### Changed

- The `Windows x64 Release` preset builds in `build/` instead of `out/build/`.
- The libraries declare the libraries they use, which gcc's linker needs.
- Compiler warnings: gcc no longer uses `-Weffc++`, `-Wswitch-default`, `-Wmultiple-inheritance`,
  `-Wsuggest-final-*` or `-fno-rtti`, and MSVC adds C4061. A `switch` over an enum lists every
  value, without `default`.

### Fixed

- The tests stopped with a false `container-overflow` error under AddressSanitizer on Windows.

## [0.5.0] - 2026-10-29

### Added

- Console menu to order a beverage with ingredients, list the orders on screen, print them to
  `orders.txt` and cancel all orders.
- Builders for latte, decaf and green tea. The director builds cocoa and enforces the ingredient
  rules of each beverage (see the rules table in `AGENTS.md`); a refused ingredient rejects the order.
- `ListOrdersUC` and `CancelOrdersUC` use cases.
- One output port per use case and `TextPresenter`, which writes to any `std::ostream`.
- `coverage` target (OpenCppCoverage, `COVERAGE_ENABLED`): 99.9% of lines covered by 107 tests.
- Static analysis: clang-tidy with about 490 checks as errors, also on the project headers;
  optional cppcheck (`CPPCHECK_ENABLED`) and Doxygen (`BUILD_DOC`).
- pre-commit hooks: clang-format, gersemi, cmake-lint and file hygiene checks.
- `AGENTS.md`: architecture, conventions, build, testing and workflow.

### Changed

- C++17 to C++20.
- The code lives in one namespace per layer (`coffee_shop::domain`, `coffee_shop::application`, ...).
- Ownership with `std::unique_ptr` (decorators, factories, builders, repository), and dependency
  injection with `main()` as the composition root instead of singletons.
- GoogleTest 1.14.0 from Conan; tests split into `UnitTests` and `IntegrationTests`, with shared test
  doubles in `tests/Common`.
- clang-tidy and clang-format from LLVM 23; CMake and the Visual Studio project check the version.
- CMake 3.25 or later, with presets, and embedded debug info (`/Z7`) so ccache can cache MSVC builds.
- Includes grouped by layer, and every file includes what it uses (`misc-include-cleaner`).

### Removed

- The singleton factories, the `UseCase` base class, `IRequest`, `IBeverage::BeverageType` and the
  `CancelExistingOrderUC` skeleton.
- Dead and commented-out code.

### Fixed

- New orders were not saved to the repository.
- `BeverageController` always reported success.
- Crashes on unsupported beverages and invalid ingredients.
- The Visual Studio project (`CoffeeShop.vcxproj`) did not compile.
- The black tea test used the espresso builder.
- Building with AddressSanitizer (`ASAN_ENABLED`) and the `resolve_project_paths` CMake function.

## [0.4.0] - 2024-12-26

### Added

- CMake build, with Visual Studio folders.
- pre-commit configuration with gersemi, cmake-lint and the standard hooks.

### Fixed

- Precompiled headers in the GoogleTest project.

## [0.3.0] - 2024-12-06

### Added

- First console menu to add new orders, and `NewOrderReq`.
- Parameterized tests for `TeaBlackBuilder`.
- Precompiled headers.
- StarUML model (`docs/CoffeShop.mdj`, tracked with Git LFS) and `README_development.md`.

### Changed

- Folders follow the Clean Architecture layers: `include/` and `src/` with `Domain`,
  `Application/UseCases` and `InterfaceAdapters` (`Gateways`), and the console app in
  `apps/ConsoleApp`.
- `BeverageBuilderFactory` renamed to `BeverageBuilderSimpleFactory`.
- Smart pointers passed more efficiently as parameters.

## [0.2.0] - 2024-03-24

### Added

- Ingredients as decorators (Decorator pattern) and beverage varieties.
- Beverage builders (Builder pattern) for cocoa, espresso and black tea, with `BeverageBuildDirector`.
- `BeverageFactory`, `IngredientFactory` and `BeverageBuilderFactory` (Simple Factory).
- `UseCase` base class.
- GoogleTest from Conan, with unit, integration and parameterized tests.
- DeepSource configuration.

### Changed

- The Qt project became a plain C++ Visual Studio 2019 project.
- The build methods return `bool`.
- clang-tidy naming conventions.

### Fixed

- clang-tidy, Cppcheck and MSVC warnings, and the memory leak report.

## [0.1.0] - 2023-12-31

### Added

- First version: a Qt Widgets application (qmake) to manage drink orders, with `Model`, `UseCase`,
  `Adapter` and `Data` folders.

[Unreleased]: https://github.com/joset15/CoffeeShop/compare/v0.6.0...HEAD
[0.6.0]: https://github.com/joset15/CoffeeShop/compare/v0.5.0...v0.6.0
[0.5.0]: https://github.com/joset15/CoffeeShop/compare/v0.4.0...v0.5.0
[0.4.0]: https://github.com/joset15/CoffeeShop/compare/v0.3.0...v0.4.0
[0.3.0]: https://github.com/joset15/CoffeeShop/compare/v0.2.0...v0.3.0
[0.2.0]: https://github.com/joset15/CoffeeShop/compare/v0.1.0...v0.2.0
[0.1.0]: https://github.com/joset15/CoffeeShop/releases/tag/v0.1.0
