set(SOURCES BeverageController.cpp OrderRepository.cpp)
add_library(InterfaceAdapters ${SOURCES})

set_target_properties(InterfaceAdapters PROPERTIES FOLDER "InterfaceAdapters")

# PCH support (support for PCH in CMake was added in 3.16)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND BUILD_USING_PCH)
  message(STATUS "Reusing pre-compiled header support (InterfaceAdapters)")
  target_precompile_headers(InterfaceAdapters REUSE_FROM AllLayers)
else()
  message(STATUS "Disabled pre-compiled header support")
endif()

add_subdirectory(Gateways)

target_link_libraries(InterfaceAdapters Gateways)
