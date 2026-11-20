[![CI](https://github.com/joset15/CoffeeShop/actions/workflows/ci.yml/badge.svg?branch=develop)](https://github.com/joset15/CoffeeShop/actions/workflows/ci.yml?query=branch%3Adevelop)
[![Coverage Windows](https://img.shields.io/codecov/c/github/joset15/CoffeeShop/develop?flag=windows&label=coverage%20windows&logo=codecov)](https://app.codecov.io/gh/joset15/CoffeeShop/tree/develop?flags%5B0%5D=windows)
[![Coverage Linux](https://img.shields.io/codecov/c/github/joset15/CoffeeShop/develop?flag=linux&label=coverage%20linux&logo=codecov)](https://app.codecov.io/gh/joset15/CoffeeShop/tree/develop?flags%5B0%5D=linux)
[![Release](https://img.shields.io/github/v/release/joset15/CoffeeShop)](https://github.com/joset15/CoffeeShop/releases/latest)
[![License: MIT](https://img.shields.io/github/license/joset15/CoffeeShop)](./LICENSE)
[![pre-commit](https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit)](https://github.com/pre-commit/pre-commit)

[![CodeQL](https://github.com/joset15/CoffeeShop/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/joset15/CoffeeShop/actions/workflows/github-code-scanning/codeql)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=joset15_CoffeeShop&metric=alert_status)](https://sonarcloud.io/summary/overall?id=joset15_CoffeeShop)
[![OpenSSF Scorecard](https://api.scorecard.dev/projects/github.com/joset15/CoffeeShop/badge)](https://scorecard.dev/viewer/?uri=github.com/joset15/CoffeeShop)

# CoffeeShop
Management of drink orders.

## Developer documents

Documents for the [developers](./docs/README_development.md).

## Quality tools

| Tool | Status |
|---|---|
| clang-tidy 23 (about 490 checks, on every build) | In use |
| Compiler warnings (MSVC and gcc) | In use |
| AddressSanitizer and UndefinedBehaviorSanitizer, in the tests | In use |
| cppcheck 2.10 | Tried and discarded: nothing relevant that clang-tidy misses |
| DeepSource | On trial: nothing found in the project's code so far |
| Codecov | In use: the coverage of both systems, in the badges above |
| CodeQL (GitHub code scanning, default setup with the Extended suite) | In use: C++, Python and the GitHub Actions workflows |
| Dependency graph and Dependabot alerts | In use: the workflows' actions (GitHub doesn't read Conan's files) |
| Semgrep (Community) | Discarded for now: no C++ rules; to review with the JavaScript frontends |
| SonarQube Cloud (automatic analysis) | On trial: nothing in C++ or Python; findings in the workflows, fixed |
| OpenSSF Scorecard | To evaluate |

How each one was measured, and why it was kept or discarded:
[docs/analysis/quality-tools.md](./docs/analysis/quality-tools.md).

## License

[MIT](./LICENSE).
