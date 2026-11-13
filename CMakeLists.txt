# CoffeeShop Project (console app and others pending to build: qt, fxtui, sciter)
cmake_minimum_required(VERSION 3.25)

project(
  CoffeeShop
  VERSION 0.5.0
  LANGUAGES CXX
  DESCRIPTION "C++/CMake project for a modern development approach: CMake, Conan, GTest..."
  HOMEPAGE_URL https://github.com/joset15/CoffeeShop
)

# Options and Settings
option(BUILD_USING_PCH "Build using pre-compile header support" OFF) # PCH support (support for PCH in CMake was added in 3.16)
option(TESTS "Build GTest Unit Tests" ON)
option(ITESTS "Build GTest Integration Tests" ON)
option(BUILD_DOC "Build Doxygen documentation" OFF)
option(ASAN_ENABLED "Build this target with AddressSanitizer" OFF)
option(UBSAN_ENABLED "Build with UndefinedBehaviorSanitizer (gcc and clang)" OFF)
option(CLANG_TIDY_ENABLED "Build this target with Static Analysis" ON) # STATIC_ANALISYS
option(CPPCHECK_ENABLED "Run CppCheck static code analysis" OFF) # STATIC_ANALISYS
option(COVERAGE_ENABLED "Add a 'coverage' target that measures the tests' code coverage" OFF)

if(BUILD_USING_PCH AND CLANG_TIDY_ENABLED)
  message(FATAL_ERROR "Using PCH incompatible with clang-tidy (MSVC). ")
endif()

# Including Files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Conan's files: build/generators with MSVC, build/<build type>/generators with gcc. Only one of
# them, because a folder shared by Windows and WSL can have both.
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/generators")
else()
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/generators")
endif()

include(cpp_warnings)

# Preventing in-tree build
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree build. ")
endif()

# Use CCache
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  message(STATUS "CCACHE is found")
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CUDA_COMPILER_LAUNCHER "${CCACHE_PROGRAM}") # CMake 3.9+
else()
  message(STATUS "CCACHE is NOT found")
endif()

# Doxygen docs.
if(BUILD_DOC) # AND CMAKE_BUILD_TYPE STREQUAL "Release")
  # check if Doxygen is installed
  find_package(Doxygen)
  if(DOXYGEN_FOUND)
    message(STATUS "DOXYGEN is found")

    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message(STATUS "Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(
      doc_doxygen
      ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
      VERBATIM
    )
  else()
    message(STATUS "Doxygen need to be installed to generate the doxygen documentation")
  endif(DOXYGEN_FOUND)
endif(BUILD_DOC)

# C++ standard (the only place where it is set)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enabled folders for VS projects.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

# Compiler options
set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)
add_compile_options(${PROJECT_WARNING_FLAGS})

# Static analysis
# clang-tidy can't be combined with precompiled headers (BUILD_USING_PCH).
include(clang_tidy) # Finds clang-tidy (LLVM_TOOLS_DIR) and checks its version.

if(CPPCHECK_ENABLED)
  set(CMAKE_CXX_CPPCHECK "cppcheck") # v3.10
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # MATCHES
  message(STATUS "Setting MSVC flags")

  if(ASAN_ENABLED)
    message(STATUS "ASAN ENABLED")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /D_DEBUG /fsanitize=address")
    # GoogleTest comes from Conan without AddressSanitizer. Its std::vector and std::string are not
    # annotated, so the instrumented code reports false "container-overflow" errors on them. These
    # macros turn the annotations off; every other AddressSanitizer check still runs.
    add_compile_definitions(_DISABLE_VECTOR_ANNOTATION _DISABLE_STRING_ANNOTATION)
  else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /D_DEBUG") # /MTd
  endif()
  if(UBSAN_ENABLED)
    message(WARNING "UBSAN_ENABLED: MSVC has no UndefinedBehaviorSanitizer, so it is ignored.")
  endif()

  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /DNDEBUG") # /MT

  # Embedded debug info (/Z7) instead of a shared PDB (/Zi): ccache can only cache /Z7, and
  # parallel compilations no longer write to the same PDB. The linker still produces .pdb files.
  # The Visual Studio solution (CoffeeShop.sln) is not affected and keeps /Zi.
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  message(STATUS "Setting GCC/GNU flags")

  # The warnings come from cmake/cpp_warnings.cmake, as with MSVC.
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

  # Sanitizers, on every target (also the tests), so before add_subdirectory(). AddressSanitizer
  # includes LeakSanitizer. libstdc++ doesn't annotate its containers by default, so GoogleTest
  # from Conan, without sanitizers, gives no false "container-overflow" here (unlike MSVC).
  set(SANITIZERS)
  if(ASAN_ENABLED)
    list(APPEND SANITIZERS address)
  endif()
  if(UBSAN_ENABLED)
    list(APPEND SANITIZERS undefined)
    # By default UBSan only prints the error and the test still passes: stop instead.
    add_compile_options(-fno-sanitize-recover=all)
  endif()
  if(SANITIZERS)
    list(JOIN SANITIZERS "," SANITIZERS)
    message(STATUS "Sanitizers: ${SANITIZERS}")
    add_compile_options(-fsanitize=${SANITIZERS} -fno-omit-frame-pointer)
    add_link_options(-fsanitize=${SANITIZERS})
  endif()

  # Coverage (cmake/coverage.cmake) needs every target instrumented, so before add_subdirectory().
  if(COVERAGE_ENABLED)
    add_compile_options(--coverage)
    add_link_options(--coverage)
  endif()
else()
  message(FATAL_ERROR "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

if(TESTS OR ITESTS)
  find_package(GTest REQUIRED)
  enable_testing()
endif()

add_subdirectory(src) # AllLayers
add_subdirectory(apps) # CoffeeShopApp

add_dependencies(CoffeeShopApp AllLayers)

if(TESTS)
  message(STATUS "Compiling Unit Tests")

  add_subdirectory(tests/UnitTests)
  add_dependencies(UnitTests AllLayers)
endif()

if(ITESTS)
  message(STATUS "Compiling Integration Tests")

  add_subdirectory(tests/IntegrationTests)
  add_dependencies(IntegrationTests AllLayers)
  add_subdirectory(tests/AppScenarios) # The console app run end to end.
endif()

include(coverage) # The "coverage" target, after the test targets it runs.

# Sets the startup project in a Visual Studio solution.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT apps)
