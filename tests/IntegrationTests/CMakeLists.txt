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
  BeverageBuilder/src/CocoaBuilder_Test.cpp
  BeverageBuilder/src/CoffeeEspressoBuilder_Test.cpp
  BeverageBuilder/src/CoffeeEspressoBuilderParameterized_Test.cpp
  BeverageBuilder/src/TeaBlackBuilderParameterized_Test.cpp
)

add_executable(IntegrationTests ${SOURCES})
# target_include_directories(IntegrationTests PRIVATE ../../include)
target_include_directories(
  IntegrationTests
  PRIVATE ${PUBLIC_INCLUDE_PATH} ${PROJECT_SOURCE_DIR}/tests/Common/include
)

set_target_properties(IntegrationTests PROPERTIES FOLDER "tests/IntegrationTests")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (FunctionalTests)")
  target_precompile_headers(IntegrationTests REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

target_link_libraries(IntegrationTests PRIVATE GTest::gtest_main BeverageBuilder BeverageFactories)

gtest_discover_tests(IntegrationTests)
