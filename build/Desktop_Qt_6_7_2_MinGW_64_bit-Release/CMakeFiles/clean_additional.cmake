# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\appProject_PBL_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appProject_PBL_autogen.dir\\ParseCache.txt"
  "appProject_PBL_autogen"
  )
endif()
