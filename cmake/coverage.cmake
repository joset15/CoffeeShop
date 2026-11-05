# Code coverage of the tests (COVERAGE_ENABLED).
#
# Adds a "coverage" target that runs UnitTests and IntegrationTests and writes, for the code
# under include/ and src/:
#   <build dir>/coverage/html/index.html  report to read
#   <build dir>/coverage/cobertura.xml    Cobertura XML, which scripts/dev.py reads
#
# MSVC: OpenCppCoverage instruments the Debug executables through their PDB files, so the build
# itself doesn't change.
# gcc: the top-level CMakeLists.txt compiles every target with --coverage, the tests write their
# counters (.gcda files) next to the objects, and gcovr turns them into the reports.

if(NOT COVERAGE_ENABLED)
  return()
endif()

if(NOT (TESTS AND ITESTS))
  message(FATAL_ERROR "COVERAGE_ENABLED needs the unit and integration tests (TESTS and ITESTS).")
endif()

set(COVERAGE_DIR ${CMAKE_BINARY_DIR}/coverage)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  find_program(GCOVR_EXECUTABLE NAMES gcovr DOC "gcovr, used by the coverage target" REQUIRED)
  # The gcov of the same gcc version: another version can't read the counters.
  string(REGEX MATCH "^[0-9]+" GCC_MAJOR_VERSION "${CMAKE_CXX_COMPILER_VERSION}")
  find_program(
    GCOV_EXECUTABLE
    NAMES gcov-${GCC_MAJOR_VERSION} gcov
    DOC "gcov of the gcc that builds the project"
    REQUIRED
  )

  # Only the project's production code is measured: no tests, GoogleTest or standard library.
  # gcovr resolves relative filters from the current folder, so it runs from the source folder.
  # Files that no test runs are shown at 0%. --exclude-noncode-lines leaves out lines with only a
  # brace: gcc puts on the closing brace of a function that returns a local object the cleanup for
  # an exception, which no test throws there.
  add_custom_target(
    coverage
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${COVERAGE_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${COVERAGE_DIR}/html
    # The counters add up from run to run: start from zero.
    COMMAND find ${CMAKE_BINARY_DIR} -name "*.gcda" -delete
    COMMAND $<TARGET_FILE:UnitTests>
    COMMAND $<TARGET_FILE:IntegrationTests>
    COMMAND
      ${CMAKE_COMMAND} -E chdir ${PROJECT_SOURCE_DIR} ${GCOVR_EXECUTABLE} --root
      ${PROJECT_SOURCE_DIR} --filter include/ --filter src/ --exclude-noncode-lines
      --gcov-executable ${GCOV_EXECUTABLE} --html-details ${COVERAGE_DIR}/html/index.html
      --cobertura ${COVERAGE_DIR}/cobertura.xml --print-summary ${CMAKE_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Measuring test coverage (report: ${COVERAGE_DIR}/html/index.html)"
    VERBATIM
  )
  add_dependencies(coverage UnitTests IntegrationTests)
  set_target_properties(coverage PROPERTIES FOLDER "tests")
  return()
endif()

if(NOT MSVC)
  message(WARNING "COVERAGE_ENABLED: the coverage target is only available with MSVC and gcc.")
  return()
endif()

find_program(
  OPENCPPCOVERAGE_EXECUTABLE
  NAMES OpenCppCoverage
  HINTS "$ENV{ProgramFiles}/OpenCppCoverage"
  DOC "OpenCppCoverage, used by the coverage target"
  REQUIRED
)

# Only the project's production code is measured: no tests, GoogleTest or standard library.
# No trailing backslash: it would escape the ";" between the elements of the list below.
file(TO_NATIVE_PATH ${PROJECT_SOURCE_DIR}/include COVERAGE_INCLUDE_SOURCES)
file(TO_NATIVE_PATH ${PROJECT_SOURCE_DIR}/src COVERAGE_SRC_SOURCES)
set(
  COVERAGE_OPTIONS
  --quiet
  --sources
  ${COVERAGE_INCLUDE_SOURCES}
  --sources
  ${COVERAGE_SRC_SOURCES}
)

# The unit tests are saved in binary form and merged into the integration tests' report.
add_custom_target(
  coverage
  COMMAND ${CMAKE_COMMAND} -E rm -rf ${COVERAGE_DIR}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${COVERAGE_DIR}
  COMMAND
    ${OPENCPPCOVERAGE_EXECUTABLE} ${COVERAGE_OPTIONS} --export_type
    binary:${COVERAGE_DIR}/UnitTests.cov -- $<TARGET_FILE:UnitTests>
  COMMAND
    ${OPENCPPCOVERAGE_EXECUTABLE} ${COVERAGE_OPTIONS} --input_coverage ${COVERAGE_DIR}/UnitTests.cov
    --export_type html:${COVERAGE_DIR}/html --export_type cobertura:${COVERAGE_DIR}/cobertura.xml --
    $<TARGET_FILE:IntegrationTests>
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Measuring test coverage (report: ${COVERAGE_DIR}/html/index.html)"
  VERBATIM
)
add_dependencies(coverage UnitTests IntegrationTests)
set_target_properties(coverage PROPERTIES FOLDER "tests")
