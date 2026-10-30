# Runs the console app with redirected input and compares what it prints with the expected text.
#
#   cmake -DAPP=<CoffeeShopApp> -DSCENARIO=<folder>/<Name> -DWORK_DIR=<folder>
#         -P run_scenario.cmake
#
# Reads <Name>.input.txt (one answer per line) and compares the output with <Name>.expected.txt.
# If <Name>.orders.txt exists, it is compared with the orders.txt that the app writes.
# The app runs in WORK_DIR, which is emptied first; its path is replaced by <WORK_DIR> (with / after
# it) before comparing.
# Line endings are ignored, so the same files work on Windows and Linux.

foreach(variable IN ITEMS APP SCENARIO WORK_DIR)
  if(NOT DEFINED ${variable})
    message(FATAL_ERROR "${variable} is not set.")
  endif()
endforeach()

# Reads a text file with LF line endings.
function(read_text file out_var)
  file(READ "${file}" text)
  string(REPLACE "\r\n" "\n" text "${text}")
  set(${out_var} "${text}" PARENT_SCOPE)
endfunction()

# Fails, and keeps the actual text next to the expected one to compare them.
function(check_text actual expected_file)
  read_text("${expected_file}" expected)
  if(NOT actual STREQUAL expected)
    get_filename_component(name "${expected_file}" NAME)
    set(actual_file "${WORK_DIR}/actual.${name}")
    file(WRITE "${actual_file}" "${actual}")
    message(
      FATAL_ERROR
      "The output differs from ${expected_file}.\n"
      "Actual output: ${actual_file}\n"
      "Compare them with: git diff --no-index \"${expected_file}\" \"${actual_file}\""
    )
  endif()
endfunction()

file(REMOVE_RECURSE "${WORK_DIR}")
file(MAKE_DIRECTORY "${WORK_DIR}")

execute_process(
  COMMAND "${APP}"
  INPUT_FILE "${SCENARIO}.input.txt"
  OUTPUT_VARIABLE output
  ERROR_VARIABLE errors
  RESULT_VARIABLE result
  WORKING_DIRECTORY "${WORK_DIR}"
)
if(NOT result EQUAL 0)
  message(FATAL_ERROR "${APP} failed (${result}):\n${errors}")
endif()

string(REPLACE "\r\n" "\n" output "${output}")
file(TO_NATIVE_PATH "${WORK_DIR}" native_work_dir)
string(REPLACE "${native_work_dir}" "<WORK_DIR>" output "${output}")
string(REPLACE "<WORK_DIR>\\" "<WORK_DIR>/" output "${output}") # Windows separator.
check_text("${output}" "${SCENARIO}.expected.txt")

if(EXISTS "${SCENARIO}.orders.txt")
  if(NOT EXISTS "${WORK_DIR}/orders.txt")
    message(FATAL_ERROR "The app did not write ${WORK_DIR}/orders.txt.")
  endif()
  read_text("${WORK_DIR}/orders.txt" orders)
  check_text("${orders}" "${SCENARIO}.orders.txt")
endif()
