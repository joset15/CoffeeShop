include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(
  SOURCES
  BeverageBuildDirector.cpp
  CocoaBuilder.cpp
  CoffeeBuilder.cpp
  CoffeeDecafBuilder.cpp
  CoffeeEspressoBuilder.cpp
  CoffeeLatteBuilder.cpp
  TeaBlackBuilder.cpp
  TeaBuilder.cpp
  TeaGreenBuilder.cpp
)

add_library(BeverageBuilder ${SOURCES})
# target_include_directories(BeverageBuilder PRIVATE ../../../include)
target_include_directories(BeverageBuilder PRIVATE ${PUBLIC_INCLUDE_PATH})

set_target_properties(BeverageBuilder PROPERTIES FOLDER "Domain/BeverageBuilder")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (BeverageBuilder)")
  target_precompile_headers(BeverageBuilder REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
