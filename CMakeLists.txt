cmake_minimum_required(VERSION 3.9)

project(CoffeeShop VERSION 0.1.0 LANGUAGES CXX)

set(CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PCH support (support for PCH in CMake was added in 3.16)
option(BUILD_USING_PCH "Build using pre-compile header support" ON)

# Enabled folders for VS projects.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Submodules directories
# set(SUPPORT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Modules/Support")
# set(NETWORK_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Modules/Network")
# set(THREADLIB_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Modules/ThreadLib")

# Add a definition for the version.
# add_definitions(-DVERSION_SWE_NAME="${VERSION_SWE_NAME}")
# add_definitions(-DVERSION_PU_NAME="${VERSION_PU_NAME}")
# add_definitions(-DVERSION_HASH="${VERSION_HASH}")
# add_definitions(-DVERSION_CONFIG="${VERSION_CONFIG}")
# add_definitions(-DVERSION_BRANCH="${VERSION_BRANCH}")

if("$ENV{ARCH}" STREQUAL "armv8")
  include(profiles/architecture.armv8.cmake)
elseif("$ENV{ARCH}" STREQUAL "armv7hf")
  include(profiles/architecture.armv7hf.cmake)
elseif("$ENV{ARCH}" STREQUAL "ppc64")
  include(profiles/architecture.ppc64.cmake)
endif()

# if (("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC"))
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message(STATUS "Setting MSVC flags")

  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++17")

  #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fno-strict-aliasing -Werror")
  #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

  # elseif (("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU") OR ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"))
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  message(STATUS "Setting GCC/GNU flags")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-rtti -Wno-psabi -fexceptions")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fno-strict-aliasing -Werror")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
  # set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -fsanitize=address
  # -static-libasan -g") # -fpermissive")
else()
  message("Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

#jt include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#jt conan_basic_setup(TARGETS)

# file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/external_includes)

# add_custom_target(
#   support_inc ALL
#   COMMAND ${CMAKE_COMMAND} -E create_symlink ${SUPPORT_SOURCE_DIR}/include
#           ${CMAKE_BINARY_DIR}/external_includes/Support)

# include_directories(${CMAKE_BINARY_DIR}/external_includes
#                     ${CONAN_INCLUDE_DIRS_GTEST})
#jt include_directories(${CONAN_INCLUDE_DIRS_GTEST})

# add_custom_target(
#   network_inc ALL
#   COMMAND ${CMAKE_COMMAND} -E create_symlink ${NETWORK_SOURCE_DIR}/include
#           ${CMAKE_BINARY_DIR}/external_includes/Network)

# add_custom_target(
#   threadlib_inc ALL
#   COMMAND ${CMAKE_COMMAND} -E create_symlink ${THREADLIB_SOURCE_DIR}/include
# ${CMAKE_BINARY_DIR}/external_includes/ThreadLib)

# add_subdirectory(${SUPPORT_SOURCE_DIR})
# add_subdirectory(${NETWORK_SOURCE_DIR})
# add_subdirectory(${THREADLIB_SOURCE_DIR})

# include_directories(
#   ${SUPPORT_SOURCE_DIR}/dependencies/SWExternalDependencies/01_NLOHMANN_JSON_PARSER/include
# )

if(TESTS)
  include_directories(include src)
  enable_testing()

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

  add_subdirectory(tests)
elseif(ITESTS)
  include_directories(include src)
else()
  include_directories(include)
endif()

if(ITESTS)
  add_subdirectory(integrationtests)
endif()

add_subdirectory(src)
add_subdirectory(apps)

add_dependencies(CoffeeShopApp AllLayers)

# Sets the startup project in a Visual Studio solution.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT apps)
