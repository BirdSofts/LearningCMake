# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,04.04.2019</created>
#/ <changed>ʆϒʅ,05.04.2019</changed>
# ********************************************************************************

# CMakeList.txt : CMake project for libUsage, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(TARGET_NAME libUsage)
set(PROJECT_NAME ${TARGET_NAME})
project(${PROJECT_NAME})

# dynamic library linkage
#set(PROJECT_LINK_LIBS dynamicLib.dll)
#link_directories(C:/Users/Mehrdad/Source/Repos/dynamicLib/build)

#include_directories(C:/Users/Mehrdad/Source/Repos/dynamicLib/src)

# static library linkage
set(PROJECT_LINK_LIBS staticLib.lib)
link_directories(C:/Users/Mehrdad/Source/Repos/staticLib/build)

include_directories(C:/Users/Mehrdad/Source/Repos/staticLib/src)

# Add source to this project's executable.
add_executable (libUsage "src/libUsage.cpp")
target_link_libraries(libUsage ${PROJECT_LINK_LIBS})

# TODO: Add tests and install targets if needed.
