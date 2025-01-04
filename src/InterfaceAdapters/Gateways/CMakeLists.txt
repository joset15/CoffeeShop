include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES OrderDiskDataSource.cpp)
add_library(Gateways ${SOURCES})

# target_include_directories(Gateways PRIVATE ../../../include)
target_include_directories(Gateways PRIVATE ${PUBLIC_INCLUDE_PATH})

set_target_properties(Gateways PROPERTIES FOLDER "InterfaceAdapters/Gateways")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (Gateways)")
  target_precompile_headers(Gateways REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
