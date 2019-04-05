# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,04.04.2019</created>
#/ <changed>ʆϒʅ,05.04.2019</changed>
# ********************************************************************************

# CMakeList.txt : CMake project for sharedLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# project settings
set(TARGET_NAME staticLib)
set(PROJECT_NAME ${TARGET_NAME})
project(${PROJECT_NAME})

# build type settings
set(CMAKE_BUILD_TYPE Release)

# source files
list(APPEND HEADER_FILES
src/staticLib
)
list(APPEND SOURCE_FILES
src/staticLib.cpp
)
if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

# additionally include
include_directories(include)

# generate the shared library
add_library (${TARGET_NAME} STATIC ${SOURCE_FILES})

# library install location (not needed for this example)
#install(TARGETS ${TARGET_NAME} DESTINATION _Path)

# TODO: Add tests and install targets if needed.
