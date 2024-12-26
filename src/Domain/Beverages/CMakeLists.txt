set(SOURCES Cocoa.cpp Coffee.cpp Tea.cpp)
add_library(Beverages ${SOURCES})

set_target_properties(Beverages PROPERTIES FOLDER "Domain/Beverages")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (Beverages)")
  target_precompile_headers(Beverages REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
