set(SOURCES pch.cpp)
add_library(AllLayers ${SOURCES})

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Compiling using pre-compiled header support (CoffeeShopApp)")
  target_precompile_headers(AllLayers PUBLIC ../include/pch.h) # With PUBLIC they will be used by targets using this target
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

set_target_properties(AllLayers PROPERTIES FOLDER "src")

add_subdirectory(Application)
add_subdirectory(Domain)
add_subdirectory(InterfaceAdapters)

if(MSVC)
  target_compile_options(AllLayers PRIVATE "/std:c++17")
else()
  target_compile_features(AllLayers PRIVATE cxx_std_17)
endif()
