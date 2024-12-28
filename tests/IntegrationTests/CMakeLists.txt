include(GoogleTest)

set(SOURCES
    main.cpp
    BeverageBuilder/src/CoffeeEspressoBuilder_Test.cpp
    BeverageBuilder/src/CoffeeEspressoBuilderParameterized_Test.cpp
    BeverageBuilder/src/TeaBlackBuilderParameterized_Test.cpp)

#TODO: CHANGE TO IntegrationTests
add_executable(IntegrationTests ${SOURCES})

set_target_properties(IntegrationTests PROPERTIES FOLDER "tests/IntegrationTests")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (FunctionalTests)")
  target_precompile_headers(IntegrationTests REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

target_link_libraries(
  IntegrationTests
  PRIVATE
  GTest::GTest
  BeverageBuilder
  BeverageFactories)

gtest_discover_tests(IntegrationTests)
