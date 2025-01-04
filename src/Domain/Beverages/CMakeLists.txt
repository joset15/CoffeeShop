include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES Cocoa.cpp Coffee.cpp Tea.cpp)
add_library(Beverages ${SOURCES})

# target_include_directories(Beverages PRIVATE ../../../include)
target_include_directories(Beverages PRIVATE ${PUBLIC_INCLUDE_PATH})

set_target_properties(Beverages PROPERTIES FOLDER "Domain/Beverages")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (Beverages)")
  target_precompile_headers(Beverages REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
