# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,30.03.2019</created>
#/ <changed>ʆϒʅ,05.04.2019</changed>
# ********************************************************************************

#*********************************************************************
#------------------- CMake -------------------
# Fortunately I saw some MS-Dos commands within them! :)
# There is also a lot of known words here or there between a lot of creepy settings! :)
# All in all I personally have a lot of hope at constant CMake improvement! :)

#------------------- References -------------------
# https://cmake.org/cmake/help/latest/
# http://derekmolloy.ie/hello-world-introductions-to-cmake/
# https://github.com/nholthaus/cmake-cpp-project
# https://stackoverflow.com

#------------------- Directory -------------------
#folder path listing			tree
#create directory				mkdir
#moving between directories		cd cd.. cd\

#------------------- Build -------------------
# build-system:
# Best practice:
# build to current				cmake <source-path>
# Notes:  Current: Probably build folder. If source folder contains CMake_Notes.txt (..\src\)
# after:
# build project					cmake --build <dir> [--clean-first]
# Note: <dir> is probably still build folder! (cmake --build .)

# Additionally:
# build to current				cmake .
# build to path					cmake <existing-build-path>
# Note: Settings must contain the path to source.
# didn't work :)				cmake -S <src-path> -B <build-path>
# probably needs some creepy settings to be set! :)

# further information:
# https://cmake.org/cmake/help/v3.14/manual/cmake.1.html

#------------------- Useful -------------------
#present CMake version			cmake -version

#*********************************************************************
#------------------- CMakeLists.txt -------------------

#------------------- CMake settings -------------------
# establish version and policy settings for future compatibility
cmake_minimum_required (VERSION 3.8)

# automate addition of CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_BINARY_DIR
# mainly useful, when generated files in build tree are included by files in source tree (whatever the file may be!)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

#------------------- Source settings -------------------

# manual addition, file after file (explicit reference to each file)
set (SOURCES "src/CMakeProject1.cpp" "src/CMakeProject1.h")

# addition of all source code files present in the path (adding the list of files to the variable SOURCES)
# GLOB isn't a recommanded practice in CMake documentation
file(GLOB SOURCES src/*.cpp src/*.h)

# a list of header files
list(APPEND HEADER_FILES
src/file.h
)

# a list of source files
list(APPEND SOURCE_FILES
src/file.cpp
)

# Note: When building to 'build' directory file names are sufficient.

# appending headers to source on windows (needed for Visual Studio)
if(WIN32)
	list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

#------------------- Project settings -------------------

# variable TARGET_NAME for further use
set(TARGET_NAME ProjectName)

# to include git branch name to project name
find_package(Git)
if(GIT_FOUND)
	execute_process(
	COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	OUTPUT_VARIABLE BRANCH
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	execute_process(
	COMMAND ${GIT_EXECUTABLE} describe --abbrev=0 --tags
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	OUTPUT_VARIABLE VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	set(PROJECT_NAME ${TARGET_NAME}-S{BRANCH})
else()
	set(PROJECT_NAME ${TARGET_NAME})
endif()

# project name (more info in CMake documentation)
project(${PROJECT_NAME})

# build type settings
set(CMAKE_BUILD_TYPE Release)

#------------------- Resource inclusion -------------------

# resource files
list(APPEND RESOURCES
resources/resources.rc
)

#------------------- Compile flags -------------------

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	add_compile_options(/MP)
	add_compile_options(/std:c++17)
elseif(CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(-std:c++17)
endif(MSVC)

# further information:
# https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#

#------------------- Compiler Configurations -------------------

set(APPLICATION_NAME ${TARGET_NAME})
set(APPLICATION_VERSION ${VERSION})
set(APPLICATION_ORGANIZATION "BirdSofts")
set(APPLICATION_ORGANIZATION_DOMAIN "https://github.com/BirdSofts/")
configure_file(src/appinfo.h.input appinfo.h -parameters-)

# further information:
# https://cmake.org/cmake/help/latest/command/configure_file.html#

#------------------- Source Groups -------------------

# further information:
# https://cmake.org/cmake/help/latest/command/source_group.html
source_group(generated REGULAR_EXPRESSION .*automoc.cpp)
source_group(resources REGULAR_EXPRESSION .*[.][q]?rc)
source_group(source REGULAR_EXPRESSION .*[.]cpp)
source_group(header REGULAR_EXPRESSION .*[.]h)
source_group(continuous_integration REGULAR_EXPRESSION .*[.]yml)

#------------------- Additional libraries -------------------

list(APPEND LIBRARIES)

)

# duplicate library dependencies removal
list(REMOVE_DUPLICATES LIBRARIES)

#------------------- Executable generation -------------------

# additional include directories
include_directories(include)
include_directories(${INCLUDE_DIRS})

# project's executable to be built.
add_executable (${TARGET_NAME} src/file.cpp src/file.h)
add_executable (${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})

#------------------- library generation -------------------

# generate a static library (other build options are SHARED and MODULE)
add_library (${TARGET_NAME} STATIC ${SOURCE_FILES})

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

#------------------- Install settings -------------------

# defining the install location
install(TARGETS ${TARGET_NAME} DESTINATION _Path)

INCLUDE(InstallRequiredSystemLibraries)

#*********************************************************************
#------------------- CMakeSettings.json -------------------

# useful variables for root:
#	${projectDir}	${env.ProgramFiles}	${name}
