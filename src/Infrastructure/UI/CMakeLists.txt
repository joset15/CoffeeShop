include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES ConsoleMenu.cpp)
add_library(ConsoleUi ${SOURCES})

target_include_directories(ConsoleUi PRIVATE ${PUBLIC_INCLUDE_PATH})

set_target_properties(ConsoleUi PROPERTIES FOLDER "Infrastructure/UI")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (ConsoleUi)")
  target_precompile_headers(ConsoleUi REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
