cmake_minimum_required(VERSION 3.9)

# find_package(Threads)

set(SOURCES
    main.cpp)

add_executable(CoffeeShopApp ${SOURCES})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(
    STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(
    CoffeeShopApp PUBLIC pch.h)    # With PUBLIC they will be used by targets
                                   # using this target
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
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
