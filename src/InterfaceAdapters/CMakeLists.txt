include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES BeverageController.cpp OrderRepository.cpp)

add_library(InterfaceAdapters ${SOURCES})
target_include_directories(InterfaceAdapters PRIVATE ${PUBLIC_INCLUDE_PATH})

set_target_properties(InterfaceAdapters PROPERTIES FOLDER "InterfaceAdapters")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (InterfaceAdapters)")
  target_precompile_headers(InterfaceAdapters REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

add_subdirectory(Gateways)

target_link_libraries(InterfaceAdapters Gateways)
