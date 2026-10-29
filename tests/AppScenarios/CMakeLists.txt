# The console app run end to end: each scenario feeds <Name>.input.txt to CoffeeShopApp and checks
# what it prints (see run_scenario.cmake).
set(SCENARIOS CancelOrders PrintOrders)

foreach(scenario IN LISTS SCENARIOS)
  add_test(
    NAME ConsoleAppScenario.${scenario}
    COMMAND
      ${CMAKE_COMMAND} -DAPP=$<TARGET_FILE:CoffeeShopApp>
      -DSCENARIO=${CMAKE_CURRENT_SOURCE_DIR}/${scenario}
      -DWORK_DIR=${CMAKE_CURRENT_BINARY_DIR}/${scenario} -P
      ${CMAKE_CURRENT_SOURCE_DIR}/run_scenario.cmake
  )
endforeach()
