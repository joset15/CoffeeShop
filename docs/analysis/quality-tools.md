# Analysis: quality and security tools

Every static analysis or quality tool that was tried on the project, with how it would be
integrated, what it costs, what it found compared with clang-tidy, and the decision. A tool that is
discarded stays here, so it isn't tried again without a reason.

The reference is clang-tidy (LLVM 23, about 490 checks, see "Code style" in `AGENTS.md`), which
runs on every build and breaks it on any finding. A new tool stays only if it finds something
relevant that clang-tidy doesn't.

| Tool | Kind | Status | Decision |
|---|---|---|---|
| clang-tidy 23 | Static analysis, at build time | In use | The reference |
| Compiler warnings | MSVC `/W4`, gcc `-Wall -Wextra` and more | In use | See `cmake/cpp_warnings.cmake` |
| AddressSanitizer, UndefinedBehaviorSanitizer | Dynamic analysis, in the tests | In use | ASan on Windows, ASan and UBSan on Linux |
| cppcheck 2.10 | Static analysis | **Discarded** (2026-11) | Nothing relevant that clang-tidy misses |
| DeepSource | External service | Being measured (#30) | |
| CodeQL | Security, GitHub code scanning | To evaluate (#41) | |
| SonarQube Cloud | External service | To evaluate (#41) | |
| Semgrep (Community) | Pattern-based rules | To evaluate (#41) | |
| OpenSSF Scorecard | Repository security practices | To evaluate (#41) | |

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
