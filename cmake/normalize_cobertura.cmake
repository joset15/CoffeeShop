# Makes the file paths of OpenCppCoverage's Cobertura report relative to the repository, as gcovr
# writes them, so that coverage services (Codecov) can match them with the repository's files.
#
#   cmake -DREPORT=<cobertura.xml> -DROOT=<source folder> -P normalize_cobertura.cmake
#
# OpenCppCoverage writes the drive as the source (<source>D:</source>) and each file from there,
# with backslashes: users\...\CoffeeShop\include\Domain\...\X.hpp. This script writes the source
# folder as the source and include/Domain/.../X.hpp as the file name.

foreach(variable IN ITEMS REPORT ROOT)
  if(NOT DEFINED ${variable})
    message(FATAL_ERROR "${variable} is not set.")
  endif()
endforeach()

file(READ "${REPORT}" report)

# The source folder without its drive (D:/users/.../CoffeeShop -> users/.../CoffeeShop/).
cmake_path(CONVERT "${ROOT}" TO_CMAKE_PATH_LIST root)
string(REGEX REPLACE "^[A-Za-z]:/" "" root_without_drive "${root}")
if(NOT root_without_drive MATCHES "/$")
  string(APPEND root_without_drive "/")
endif()

string(REPLACE "\\" "/" report "${report}")
string(REPLACE "filename=\"${root_without_drive}" "filename=\"" report "${report}")
string(REGEX REPLACE "<source>[^<]*</source>" "<source>${root}</source>" report "${report}")

# Every file must now be inside the repository: stop if a path wasn't converted (e.g. another
# folder, or a different letter case in the path).
string(REGEX MATCHALL "filename=\"[^\"]*\"" file_names "${report}")
foreach(file_name IN LISTS file_names)
  if(NOT file_name MATCHES "^filename=\"(include|src)/")
    message(FATAL_ERROR "${REPORT}: ${file_name} is not relative to ${root}.")
  endif()
endforeach()

file(WRITE "${REPORT}" "${report}")
