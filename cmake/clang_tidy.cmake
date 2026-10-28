# clang-tidy for the build (CLANG_TIDY_ENABLED).
#
# The project uses one LLVM version for clang-tidy and clang-format on every machine, in CMake, in
# the Visual Studio project and in pre-commit. Point the environment variable LLVM_TOOLS_DIR at the
# bin folder of that version (on Windows e.g. D:\LLVM\23.1.4\bin); without it, clang-tidy is looked
# up on PATH. Configuring stops if the clang-tidy found is not that version.

set(CLANG_TIDY_REQUIRED_VERSION 23)

if(NOT CLANG_TIDY_ENABLED)
  return()
endif()

find_program(
  CLANG_TIDY_EXE
  NAMES clang-tidy
  HINTS "$ENV{LLVM_TOOLS_DIR}"
  DOC "clang-tidy, LLVM ${CLANG_TIDY_REQUIRED_VERSION}"
)
if(NOT CLANG_TIDY_EXE)
  message(
    FATAL_ERROR
    "clang-tidy not found. Install LLVM ${CLANG_TIDY_REQUIRED_VERSION} and set LLVM_TOOLS_DIR to "
    "its bin folder (see AGENTS.md), or configure with -DCLANG_TIDY_ENABLED=OFF."
  )
endif()

execute_process(
  COMMAND "${CLANG_TIDY_EXE}" --version
  OUTPUT_VARIABLE CLANG_TIDY_VERSION_OUTPUT
  ERROR_QUIET
)
string(
  REGEX MATCH
  "version ([0-9]+)\\.[0-9.]+"
  CLANG_TIDY_VERSION_TEXT
  "${CLANG_TIDY_VERSION_OUTPUT}"
)
if(NOT CMAKE_MATCH_1 STREQUAL CLANG_TIDY_REQUIRED_VERSION)
  message(
    FATAL_ERROR
    "${CLANG_TIDY_EXE} is not LLVM ${CLANG_TIDY_REQUIRED_VERSION} ('${CLANG_TIDY_VERSION_TEXT}'). "
    "Set LLVM_TOOLS_DIR to the bin folder of LLVM ${CLANG_TIDY_REQUIRED_VERSION} (see AGENTS.md) "
    "and reconfigure with --fresh."
  )
endif()
message(STATUS "clang-tidy: ${CLANG_TIDY_EXE} (${CLANG_TIDY_VERSION_TEXT})")

# The .clang-tidy files hold the checks.
set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
if(MSVC)
  # CMake adds --extra-arg-before=--driver-mode=cl, which makes clang-tidy ignore /EHsc.
  list(APPEND CMAKE_CXX_CLANG_TIDY "--extra-arg=/EHsc")
endif()
