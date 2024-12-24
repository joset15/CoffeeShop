cmake_minimum_required(VERSION 3.9)

set(SOURCES main.cpp)

add_executable(CoffeeShopApp ${SOURCES})
target_link_libraries(Application Domain InterfaceAdapters)

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(CoffeeShopApp REUSE_FROM XXX)
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
