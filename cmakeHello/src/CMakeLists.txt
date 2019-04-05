# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,03.04.2019</created>
#/ <changed>ʆϒʅ,05.04.2019</changed>
# ********************************************************************************

# CMakeList.txt : CMake project for cmakeHello, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# project settings
set(PROJECT_NAME "cmakeHello")
project(${PROJECT_NAME})

# project source files
set (SOURCE_FILES "cmakeHello.cpp" "cmakeHello.h")

# additionally include
#include_directories("include")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCE_FILES})

# TODO: Add tests and install targets if needed.
