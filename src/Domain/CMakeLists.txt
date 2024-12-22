# cmake_minimum_required(VERSION 3.9)

# find_package(Threads)

set(SOURCES
    BeverageBuilder.cpp)

add_library(Domain ${SOURCES})
target_link_libraries(Domain BeverageBuilder BeverageFactories Beverages)

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(
    STATUS "Compiling using pre-compiled header support (Domain)")
    target_precompile_headers(Domain REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

add_subdirectory(BeverageBuilder)
add_subdirectory(BeverageFactories)
add_subdirectory(Beverages)
