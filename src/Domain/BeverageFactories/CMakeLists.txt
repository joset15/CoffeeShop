include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES BeverageBuilderSimpleFactory.cpp BeverageFactory.cpp IngredientFactory.cpp)

add_library(BeverageFactories ${SOURCES})
target_include_directories(BeverageFactories PRIVATE ${PUBLIC_INCLUDE_PATH})
# The libraries it uses. gcc's linker needs them; MSVC's finds them anyway.
target_link_libraries(BeverageFactories PRIVATE BeverageBuilder Beverages)

set_target_properties(BeverageFactories PROPERTIES FOLDER "Domain/BeverageFactories")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (BeverageFactories)")
  target_precompile_headers(BeverageFactories REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
