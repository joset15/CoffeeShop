include(files_helper)

resolve_project_paths(
  SOURCE_ROOT_PATH
  TOOLS_ROOT_PATH
  PUBLIC_INCLUDE_PATH
  PRIVATE_INCLUDE_PATH
)

set(SOURCES main.cpp)
# add_executable(CoffeeShopApp WIN32 ${SOURCES})
add_executable(CoffeeShopApp ${SOURCES})

# target_include_directories(CoffeeShopApp PRIVATE ../../include)
target_include_directories(CoffeeShopApp PRIVATE ${PUBLIC_INCLUDE_PATH})

target_link_libraries(CoffeeShopApp Application Domain InterfaceAdapters)

set_target_properties(CoffeeShopApp PROPERTIES FOLDER "apps/ConsoleApp")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(CoffeeShopApp REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

if(MSVC)
  target_compile_options(CoffeeShopApp PRIVATE "/std:c++17")
else()
  target_compile_features(CoffeeShopApp PRIVATE cxx_std_17)
endif()
