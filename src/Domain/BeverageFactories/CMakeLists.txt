set(SOURCES BeverageBuilderSimpleFactory.cpp BeverageFactory.cpp IngredientFactory.cpp)
add_library(BeverageFactories ${SOURCES})

set_target_properties(BeverageFactories PROPERTIES FOLDER "Domain/BeverageFactories")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (BeverageFactories)")
  target_precompile_headers(BeverageFactories REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
