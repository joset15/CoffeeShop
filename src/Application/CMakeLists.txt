add_library(Application "")
target_link_libraries(Application UseCases)

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (Application)")

  target_precompile_headers(Application REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

add_subdirectory(UseCases)
