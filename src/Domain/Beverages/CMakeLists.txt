# cmake_minimum_required(VERSION 3.9)

# find_package(Threads)

set(SOURCES Cocoa.cpp Coffee.cpp Tea.cpp)

add_library(Beverages ${SOURCES})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(Beverages REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

# add_subdirectory(Protocols)
# add_subdirectory(Emitter)
# add_subdirectory(ConfigUtilities)

# target_link_libraries(
#   MissionDBUpdater
#   Network_v2
#   support
#   NativeSocket
#   Protocols
#   emitter
#   ConfigUtilities
#   dl
#   ${CMAKE_THREAD_LIBS_INIT})
