set(SOURCES AddNewOrderUC.cpp) # CancelExistingOrderUC.cpp)
add_library(UseCases ${SOURCES})

set_target_properties(UseCases PROPERTIES FOLDER "Application/UseCases")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (UseCases)")
  target_precompile_headers(UseCases REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()
