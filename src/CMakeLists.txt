cmake_minimum_required(VERSION 3.9)

# find_package(Threads)

set(SOURCES
    pch.cpp)

add_executable(AllLayers ${SOURCES})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(
    STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(
    AllLayers PUBLIC pch.h)    # With PUBLIC they will be used by targets
                                   # using this target
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

# add_subdirectory(Protocols)
# add_subdirectory(Emitter)
# add_subdirectory(ConfigUtilities)
add_subdirectory(Application)
add_subdirectory(Domain)
add_subdirectory(InterfaceAdapters)

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
