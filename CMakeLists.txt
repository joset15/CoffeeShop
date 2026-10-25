# CoffeeShop Project (console app and others pending to build: qt, fxtui, sciter)
cmake_minimum_required(VERSION 3.25)

project(
  CoffeeShop
  VERSION 0.1.0
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
option(CLANG_TIDY_ENABLED "Build this target with Static Analysis" ON) # STATIC_ANALISYS
option(CPPCHECK_ENABLED "Run CppCheck static code analysis" OFF) # STATIC_ANALISYS

if(BUILD_USING_PCH AND CLANG_TIDY_ENABLED)
  message(FATAL_ERROR "Using PCH incompatible with clang-tidy (MSVC). ")
endif()

# Including Files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/generators") # Conan

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
set(CMAKE_CXX_STANDARD 17)
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
if(CLANG_TIDY_ENABLED)
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy") # v3.6, will search for file .clang-tidy
  if(MSVC)
    # CMake adds --extra-arg-before=--driver-mode=cl, which makes clang-tidy ignore /EHsc.
    list(APPEND CMAKE_CXX_CLANG_TIDY "--extra-arg=/EHsc")
  endif()
endif()

if(CPPCHECK_ENABLED)
  set(CMAKE_CXX_CPPCHECK "cppcheck") # v3.10
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # MATCHES
  message(STATUS "Setting MSVC flags")

  if(ASAN_ENABLED)
    message(STATUS "ASAN ENABLED")
    set(ENV{ASAN_SAVE_DUMPS} "AsanDumpInfo.dmp") # ASAN_SAVE_DUMPS=MyFileName.dmp
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /D_DEBUG /fsanitize=address")

    unset(ASAN_ENABLED)
  else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /D_DEBUG") # /MTd
  endif()

  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /DNDEBUG") # /MT

  # Embedded debug info (/Z7) instead of a shared PDB (/Zi): ccache can only cache /Z7, and
  # parallel compilations no longer write to the same PDB. The linker still produces .pdb files.
  # The Visual Studio solution (CoffeeShop.sln) is not affected and keeps /Zi.
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  message(STATUS "Setting GCC/GNU flags")

  set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fno-rtti -Wno-psabi -fexceptions"
  )
  if(ASAN_ENABLED)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fsanitize=address -static-libasan")
  else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
  endif()

  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fno-strict-aliasing -Werror")
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

  if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  endif()

  add_subdirectory(tests/UnitTests)
  add_dependencies(UnitTests AllLayers)
endif()

if(ITESTS)
  message(STATUS "Compiling Integration Tests")

  add_subdirectory(tests/IntegrationTests)
  add_dependencies(IntegrationTests AllLayers)
endif()

# Sets the startup project in a Visual Studio solution.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT apps)
