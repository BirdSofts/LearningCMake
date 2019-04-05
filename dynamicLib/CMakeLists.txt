# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,03.04.2019</created>
#/ <changed>ʆϒʅ,05.04.2019</changed>
# ********************************************************************************

# CMakeList.txt : CMake project for dynamicLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# project settings
set(TARGET_NAME dynamicLib)
set(PROJECT_NAME ${TARGET_NAME})
project(${PROJECT_NAME})

# build type settings
set(CMAKE_BUILD_TYPE Release)

# source files
list(APPEND HEADER_FILES
src/dynamicLib
)
list(APPEND SOURCE_FILES
src/dynamicLib.cpp
)
if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

# additionally include (FYI: above code is sufficient, since all files are in source directory)
include_directories(include)

# generate the dynamic library
add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})

# generate export header automatically
include(GenerateExportHeader)
generate_export_header(${TARGET_NAME}
  BASE_NAME ${TARGET_NAME}
  EXPORT_MACRO_NAME ${TARGET_NAME}_EXPORTS
  EXPORT_FILE_NAME ${TARGET_NAME}_EXPORTS.h
  STATIC_DEFINE ${TARGET_NAME}_EXPORTS_BUILD_AS_STATIC
)

# library install location (not needed for this example)
#install(TARGETS ${TARGET_NAME} DESTINATION _Path)

# TODO: Add tests and install targets if needed.
