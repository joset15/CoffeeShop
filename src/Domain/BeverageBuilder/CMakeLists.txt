set(
  SOURCES
  BeverageBuildDirector.cpp
  CocoaBuilder.cpp
  CoffeeBuilder.cpp
  CoffeeEspressoBuilder.cpp
  TeaBlackBuilder.cpp
  TeaBuilder.cpp
)

add_library(BeverageBuilder ${SOURCES})

set_target_properties(BeverageBuilder PROPERTIES FOLDER "Domain/BeverageBuilder")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (BeverageBuilder)")
  target_precompile_headers(BeverageBuilder REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
