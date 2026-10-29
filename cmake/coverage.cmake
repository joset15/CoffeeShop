# Code coverage of the tests (COVERAGE_ENABLED).
#
# Adds a "coverage" target that runs UnitTests and IntegrationTests and writes, for the code
# under include/ and src/:
#   <build dir>/coverage/html/index.html  report to read
#   <build dir>/coverage/cobertura.xml    Cobertura XML, for CI tools
#
# MSVC: OpenCppCoverage instruments the Debug executables through their PDB files, so the build
# itself doesn't change. Other compilers are not supported yet (gcc + gcovr will come with the
# Linux build).

if(NOT COVERAGE_ENABLED)
  return()
endif()

if(NOT (TESTS AND ITESTS))
  message(FATAL_ERROR "COVERAGE_ENABLED needs the unit and integration tests (TESTS and ITESTS).")
endif()

if(NOT MSVC)
  message(WARNING "COVERAGE_ENABLED: the coverage target is only available with MSVC for now.")
  return()
endif()

find_program(
  OPENCPPCOVERAGE_EXECUTABLE
  NAMES OpenCppCoverage
  HINTS "$ENV{ProgramFiles}/OpenCppCoverage"
  DOC "OpenCppCoverage, used by the coverage target"
  REQUIRED
)

set(COVERAGE_DIR ${CMAKE_BINARY_DIR}/coverage)

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
