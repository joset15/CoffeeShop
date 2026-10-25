include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES pch.cpp)
add_library(AllLayers ${SOURCES})

# target_include_directories(AllLayers PRIVATE ../include)
target_include_directories(AllLayers PRIVATE ${PUBLIC_INCLUDE_PATH})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(AllLayers PUBLIC ${PUBLIC_INCLUDE_PATH}/pch.h) # With PUBLIC they will be used by targets using this target
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message(STATUS "Setting MSVC flags (AllLayers)")

  target_compile_features(AllLayers PRIVATE cxx_std_17)
  # target_compile_definitions(AllLayers PRIVATE _CRT_SECURE_NO_WARNINGS)
  # target_compile_options(AllLayers PRIVATE /W4) #WX
else()
  message(FATAL_ERROR "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

set_target_properties(AllLayers PROPERTIES FOLDER "src")

add_subdirectory(Application)
add_subdirectory(Domain)
add_subdirectory(Infrastructure)
add_subdirectory(InterfaceAdapters)

if(MSVC)
  target_compile_options(AllLayers PRIVATE "/std:c++17")
else()
  target_compile_features(AllLayers PRIVATE cxx_std_17)
endif()
