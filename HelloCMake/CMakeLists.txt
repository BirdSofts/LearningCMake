﻿# ********************************************************************************
#/ <summary>
#/
#/ </summary>
#/ <created>ʆϒʅ,03.04.2019</created>
#/ <changed>ʆϒʅ,14.10.2019</changed>
# ********************************************************************************

cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# project settings
set(PROJECT_NAME "HelloCMake")
project(${PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "CMake notes and examples"
  HOMEPAGE_URL "https://github.com/BirdSofts/LearningCMake"
  LANGUAGES CXX
  )

# project source files
set (SOURCE_FILES "source/HelloCMake.cpp" "source/HelloCMake.h")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCE_FILES})
