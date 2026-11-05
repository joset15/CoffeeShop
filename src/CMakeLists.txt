include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES pch.cpp)
add_library(AllLayers ${SOURCES})

target_include_directories(AllLayers PRIVATE ${PUBLIC_INCLUDE_PATH})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(AllLayers PUBLIC ${PUBLIC_INCLUDE_PATH}/pch.h) # With PUBLIC they will be used by targets using this target
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

set_target_properties(AllLayers PROPERTIES FOLDER "src")

add_subdirectory(Application)
add_subdirectory(Domain)
add_subdirectory(Infrastructure)
add_subdirectory(InterfaceAdapters)
