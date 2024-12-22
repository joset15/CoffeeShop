# cmake_minimum_required(VERSION 3.9)

# find_package(Threads)

set(SOURCES
    BeverageBuildDirector.cpp
    CocoaBuilder.cpp
    CoffeeBuilder.cpp
    CoffeeEspressoBuilder.cpp
    TeaBlackBuilder.cpp
    TeaBuilder.cpp)

#add_executable(CoffeeShopApp ${SOURCES})
add_executable(BeverageBuilder ${SOURCES})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(
    STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")

    target_precompile_headers(BeverageBuilder REUSE_FROM AllLayers)
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
