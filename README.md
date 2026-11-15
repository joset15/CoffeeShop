[![CI](https://github.com/joset15/CoffeeShop/actions/workflows/ci.yml/badge.svg)](https://github.com/joset15/CoffeeShop/actions/workflows/ci.yml)
[![pre-commit](https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit)](https://github.com/pre-commit/pre-commit)

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
| DeepSource | Being measured |
| CodeQL, SonarQube Cloud, Semgrep, OpenSSF Scorecard | To evaluate |

How each one was measured, and why it was kept or discarded:
[docs/analysis/quality-tools.md](./docs/analysis/quality-tools.md).

## License

[MIT](./LICENSE).
