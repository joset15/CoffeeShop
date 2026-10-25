include(GoogleTest)
include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(
  SOURCES
  BeverageBuilder/src/BeverageBuildDirector_Test.cpp
  BeverageFactories/src/BeverageBuilderSimpleFactory_Test.cpp
  Beverages/src/Coffee_Test.cpp
  Infrastructure/src/ConsoleMenu_Test.cpp
  Ingredients/src/IngredientDecorator_Test.cpp
  Ingredients/src/Sugar_Test.cpp
  InterfaceAdapters/src/BeverageController_Test.cpp
  UseCases/src/AddNewOrderUC_Test.cpp
)

add_executable(UnitTests ${SOURCES})
target_include_directories(
  UnitTests
  PRIVATE ${PUBLIC_INCLUDE_PATH} ${PROJECT_SOURCE_DIR}/tests/Common/include
)

set_target_properties(UnitTests PROPERTIES FOLDER "tests/UnitTests")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (UnitTests)")
  target_precompile_headers(UnitTests REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

target_link_libraries(
  UnitTests
  PRIVATE
    GTest::gtest_main
    ConsoleUi
    InterfaceAdapters
    UseCases
    BeverageBuilder
    BeverageFactories
    Beverages
)

gtest_discover_tests(UnitTests)
