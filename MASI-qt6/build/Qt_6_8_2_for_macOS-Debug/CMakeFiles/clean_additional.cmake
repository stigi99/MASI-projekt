# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/nienazwane3_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/nienazwane3_autogen.dir/ParseCache.txt"
  "nienazwane3_autogen"
  )
endif()
