# *******************************************************************************************
#/ <summary>
#/
#/ </summary>
#/ <created>ʆϒʅ,30.03.2019</created>
#/ <changed>ʆϒʅ,14.10.2019</changed>
# *******************************************************************************************

#-----------------------------------------------------------------------------------------------------------
## Note that the projects in this repository are perfectly compilable using CMake,
## each and every one from the corresponding directory,
## therefore don't pay attention to the errors of this CMake document.
## This document contains the different, learnt and experienced aspects, while fighting a way through CMake. :)
#-----------------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#------------------- CMake -------------------
#
#-- description: cross-platform, open-source, widely used and fast build system, that build, test and package software.
#-- method: control compilation process through simple platform and compiler independent configuration files.

# with other words: generation of native makefiles and workspaces, that are usable in wished complier environment.

# CMakeCache.text: compiler and platform test results. (modification and rerun of CMake is possible.)
# CMake GUI: compilation, it also provides graphical cache editor.

# Nerd Snow's opinions
# Fortunately I saw some MS-Dos commands within them! :)
# There is also a lot of known words here or there between a lot of creepy settings! :)
# All in all I personally have a lot of hope at constant CMake improvement! :)
# Upper case words don't ever give up yelling! :)

# Nerd Snow's proposal
# please get rid of not needed and old stuff! :)

# Note that before continuing, it is strongly recommended to find a package manager under windows,
# which can provide easiness here and there, considering an advanced fight through a build system!


#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#------------------- CMakeLists.txt -------------------
#
# recommanded:
# provide the ability to build a project as sub-projects additionally to stand-alone.

# not recommanded:
# assumption that the root of project is build root.
# modification of global compile/link flags.
# practicing any global changes.


#------------------- CMake settings -------------------
# establish version and policy settings for future compatibility
# latest version of CMake should be preferred.
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# build type setting
set(CMAKE_BUILD_TYPE Release)

# verbose make file: printing current command before execution (troubleshooting build related issues)
set(CMAKE_VERBOSE_MAKEFILE true)

# produced code is executable regardless of the memory location of shared libraries
set(CMAKE_POSITION_INDEPENDENT_CODE on)


#------------------- Project settings -------------------

# variable TARGET_NAME for further use
set(TARGET_NAME ProjectName)

set(PROJECT_NAME ${TARGET_NAME})

# project properties
# a direct call is needed and not through function, macro or include.
# if not present at top, CMake adds an implicit call to this function.
project(${PROJECT_NAME}
  VERSION 0.1.0.0 #[Version <major>[.<minor>[.<patch>[.<tweak>]]]]
  DESCRIPTION "CMake notes and examples" #[]
  HOMEPAGE_URL "https://github.com/BirdSofts/LearningCMake" #[]
  LANGUAGES CXX #[]
  )

# further information:
# https://cmake.org/cmake/help/latest/command/configure_file.html#
set(APPLICATION_NAME ${TARGET_NAME})
set(APPLICATION_VERSION ${VERSION})
set(APPLICATION_ORGANIZATION "BirdSofts")
set(APPLICATION_ORGANIZATION_DOMAIN "https://github.com/BirdSofts/")
configure_file(src/appinfo.h.input appinfo.h -parameters-)

# resources
# resource files
set(PRODUCT_VERSION_MAJOR 1)
set(PRODUCT_VERSION_MINOR 0)
set(PRODUCT_VERSION_PATCH 0)
set(PRODUCT_VERSION_BUILD 1)
set(FILE_VERSION_MAJOR 1)
set(FILE_VERSION_MINOR 0)
set(FILE_VERSION_PATCH 0)
set(FILE_VERSION_BUILD 1)
set(PRODUCT_COMMENTS "")
set(PRODUCT_COMPANY_NAME "BirdSofts")
set(PRODUCT_FILE_DESCRIPTION "Learning CMake examples")
set(PRODUCT_INTERNAL_NAME "LearningCMake")
set(PRODUCT_COMPANY_COPYRIGHT "")
set(PRODUCT_ORIGINAL_FILENAME "LearningCMake.exe")
set(PRODUCT_BUNDLE "LearningCMake")

configure_file(
  ${ROOT}/LearningCMake.rc
  ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_NAME}.rc
  COPYONLY)

configure_file(
  ${ROOT}/resource.h
  ${CMAKE_CURRENT_SOURCE_DIR}/resource.h
  @ONLY)

list(APPEND RESOURCES
  ${TARGET_NAME}.rc
  resource.h
  )

# to embed projects as sub-projects
# for each sub-project CMake creates a Makefile/Solution.
# a subfolder for each subproject isn't obligatory.
add_subdirectory(<sourceDir> [<binaryDir>])

# pre-installed dependencies
# features: sets some variables - defines imported targets - supports components
find_package(Qt5 REQUIRED COMPONENTS Widgets)

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


#------------------- Source settings -------------------

# manual addition, file after file (explicit reference to each file)
set(SOURCES "src/CMakeProject1.cpp" "src/CMakeProject1.h")

# explicit addition of header files into a list
list(APPEND HEADER_FILES
  src/file.h
  )
# explicit addition of source files into a list
list(APPEND SOURCE_FILES
  src/file.cpp
  )
# appending headers to source on windows (needed for Visual Studio)
if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()


#------------------- Compile Configurations and Flags -------------------

# setting compile definitions (preprocessor constants)
target_compile_definitions(${TARGET_NAME}
  PRIVATE SRC_DIR=${TARGET_SOURCE_DIR}
  )
# recommanded:
# add_definitions() command is to be avoided
# adding definitions to CMAKE_<LANG>_FLAGS is to be avoided

# make files with the C++14 standard enabled in source code are compilable (some compilers needs)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 11, 14, 17)

# setting compile options/flags
if(MSVC)
  target_compile_options(
    #                    PUBLIC
    )
elseif(CMAKE_COMPILER_IS_GNUCXX)
  target_compile_options(
    PUBLIC -fno-elide-constructors
    )
endif(MSVC)
# recommanded:
# some appropriate wrapping condition for compiler specific options
# add_compile_options() command is to be avoided
# adding options to CMAKE_<LANG>_FLAGS is to be avoided
# avoid: addition of -std=c++11 to CMAKE_<LANG>_FLAGS
# avoid: passing -std=c++11 to target_compile_options()

# setting required compiler features
# result: automate addition of required compile flags
# errors if compiler isn't supported
target_compile_features(${TARGET_NAME}
  PUBLIC
  #                    cxx_auto_type
  #                    cxx_range_for
  PRIVATE
  #                    cxx_variadic_templates
  )

# further information:
# https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#


#------------------- Executable generation -------------------

# generate the project's executable target.
add_executable(${TARGET_NAME} [WIN32]
  src/file.cpp
  src/file.h
  )
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})
add_executable(my::${TARGET_NAME} ALIAS ${TARGET_NAME})


#------------------- library generation -------------------

# if not explicit static then build SAHARED (control over default)
option(BUILD_SHARED_LIBS ON)
# recommanded:
# control over BUILD_SHARED_LIBS is to be left to client.

# generate a STATIC library (other library build options are SHARED, MODULE and INTERFACE)
add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})
add_library(my::${TARGET_NAME} ALIAS ${TARGET_NAME})
# generate a SHARED library (dynamic)
add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})
add_library(my::${TARGET_NAME} ALIAS ${TARGET_NAME})
# generate export header automatically
include(GenerateExportHeader)
generate_export_header(${TARGET_NAME}
  BASE_NAME ${TARGET_NAME}
  EXPORT_MACRO_NAME ${TARGET_NAME}_EXPORTS
  EXPORT_FILE_NAME ${TARGET_NAME}_EXPORTS.h
  STATIC_DEFINE ${TARGET_NAME}_EXPORTS_BUILD_AS_STATIC
  )
# recommanded:
# namespaced aliases for libraries is strongly recommanded.
# avoid STATIC/SHARED libraries, unless there is no other way


#------------------- Inclusion, Dependency and library usage -------------------

# platform architecture (different architecture inclusion)
# for detecting x86 use 4 as size
if(${CMAKE_SIZEOF_VOID_P} EQUAL "8")
  set(PROJECTNAME_ARCHITECTURE "x64")
else()
  set(PROJECTNAME_ARCHITECTURE "x86")
endif()
#
if(MSVC)
  if(CMAKE_CL_64 OR ${PROJECTNAME_ARCHITECTURE} EQUAL "x64")
    # ...
  else()
    # ...
  endif()
endif()

# CMake scripts that find third-party libraries
# each inclusion and linkage to a different library can be written in a .cmake file,
# considering their differences and having them organized
# for more infos refer to https://pmateusz.github.io/c++/cmake/2018/03/11/cmake-project-setup.html
list(APPEND MODULE_PATH path_to_cmake_scripts)
# CMake scripts that find third-party libraries
find_package (cmakeScriptName REQUIRED)
#...

set(LIBRARY_ROOT_DIR path_to_root)
if(NOT LIBRARY_ROOT_DIR)
  message(FATAL_ERROR "Library root path couldn't be found!")
endif()

set(_INCLUDE_DIRECTORY ${LIBRARY_ROOT_DIR}/include)
set(_LIBRARY_DIRECTORY ${LIBRARY_ROOT_DIR})
message(${_INCLUDE_DIRECTORY})
message(${_LIBRARY_DIRECTORY})

# note that CMake is perfectly developed for different platforms and systems,
# thus there is not need to mention the extension of filename.
find_path(LIBRARY_FILE fileName HINTS ${_LIBRARY_DIRECTORY} PATH_SUFFIXES lib)
if (NOT LIBRARY_FILE)
  message(FATAL_ERROR "Library file couldn't be found!")
endif()

# creation of a list of all library headers
list(APPEND HEADER_FILE ${...})

# set as helper variable (hidden and unavailable for an external assignment)
mark_as_advanced(_INCLUDE_DIRECTORY _LIBRARY_DIRECTORY)

# setting the path to include directories
#set(INCLUDE_DIRECTORY path_to_directory)
# appending the needed header/source files
#if(WIN32)
#          list(APPEND SOURCE_FILES ${INCLUDE_DIRECTORY}/fileName)
#endif()

# in addition:
# additional libraries
#list(APPEND LIBRARIES)
# duplicate library dependencies removal
#list(REMOVE_DUPLICATES LIBRARIES)

# setting library dependencies:
# note that a code generation command should precede the inclusions or like against any library
set(LIBRAY_DIRECTORY path_to_directory)

# linking against the needed libraries:
target_link_libraries(${TARGET_NAME}
  PUBLIC ${LIBRAY_DIRECTORY}/fileName
  PRIVATE ...
  PUBLIC my::${LIBRARY_ONE_NAME} # namespaced
  PRIVATE my::${LIBRARY_TWO_NAME} # namespaced
  )
# recommanded:
# a link against namespaced targets has preference
# dependencies can be public or PRIVATE
# the link_libraries() and link_directories() commands are to be avoided
# no need: calling add_dependencies()

# different application entry points: main, WinMain
set_target_properties(${TARGET_NAME} PROPERTIES
  LINK_FLAGS /SUBSYSTEM:CONSOLE
  LINK_FLAGS /SUBSYSTEM:WINDOWS
  )

# including the include directories
target_include_directories(${TARGET_NAME} BEFORE
  PUBLIC ${INCLUDE_DIRECTORY}
  PRIVATE ...
  )
# recommanded:
# include_directories() is to be avoided
# notes:
# PRIVATE: useable for the target
# PUBLIC: usable for the target and all other targets with linkage against it
# INTERFACE: useable for targets with linkage against it

# pre and post build event:
# copy library into target directory
# must follow a generation event
add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
  COMMAND cmake -E copy_if_different # or additionally copy_directory
  $ENV{UserProfile}.../Library.dll
  $<TARGET_FILE_DIR:${TARGET_NAME}>
  )


#------------------- Performing supported tests -------------------

# CMake CTest inclusion
include(CTest)

# enable testing (a series of needed magical procedures :) )
enable_testing()

add_subdirectory(gtests) # wished test directory (Google test, Boost test etc.)

# the test itself (gtests sub directory)-------------------
file(GLOB TESTS_FILES "gtests*.cpp")

foreach(file ${TESTS_FILES})

  string(REGEX REPLACE "^.*/|\.[^.]*$" "" plain ${file})

  set(TARGET_NAME ${plain})

  set(PROJECT_NAME ${TARGET_NAME})

  project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Google Tests of ..."
    HOMEPAGE_URL "https://github.com/BirdSofts"
    LANGUAGES CXX
    )

  find_package(GTest CONFIG REQUIRED)

  add_executable(${TARGET_NAME} ${file})

  target_link_libraries(${TARGET_NAME}
    PUBLIC GTest::gtest GTest::gtest_main
    )

  # procedure: each test in a separate suitable file
  add_test(AllTestsIn${TARGET_NAME} ${TARGET_NAME})

endforeach()

#------------------- GTest best practice -------------------


include(CTest)

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

enable_testing()

add_subdirectory(lib...)
#...

add_subdirectory(gtests)

# the test itself (gtests sub directory)-------------------

cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME TestProject)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "Google Tests of ..."
  HOMEPAGE_URL "https://github.com/BirdSofts"
  LANGUAGES CXX
  )

list(APPEND HEADER_FILES
  gtests.h
  )
list(APPEND SOURCE_FILES
  gtests.cpp
  )
if(WIN32)
  list(APPEND SOURCE_FILES ${HEADER_FILES})
endif(WIN32)

add_executable(${TARGET_NAME} ${SOURCE_FILES})

target_link_libraries(${TARGET_NAME}
  PUBLIC GTest::gtest GTest::gtest_main
  )

target_link_libraries(${TARGET_NAME}
  PUBLIC GTest::gtest GTest::gtest_main
  PUBLIC lib...
  )

gtest_discover_tests(${TARGET_NAME} NO_PRETTY_TYPES NO_PRETTY_VALUES)


#------------------- Install settings -------------------

# defining the install location
install(TARGETS ${TARGET_NAME} DESTINATION _Path)

INCLUDE(InstallRequiredSystemLibraries)


#------------------- best Practices -------------------
# 1. with less variables the code is more robust and readable
target_link_libraries(${TARGET_NAME} PRIVATE my::${LIBRARY_ONE_NAME})
if(WIN32)
  target_link_libraries(${TARGET_NAME} PRIVATE my::${LIBRARY_TWO_NAME})
endif()
# 2. create lists of source files explicitly and don't use file(GLOB)
# 3. custom functions are bad ideas.
# reasons:
# think of expansion for platform specific libraries, giving a very hard start to contributors, headache while maintaining


#------------------- in Addition -------------------

# automate addition of CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_BINARY_DIR
# mainly useful, when generated files in build tree are included by files in source tree (whatever the file may be!)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

# addition of all source code files present in a path
# file(GLOB) isn't a recommanded practice in CMake documentation
# recommanded: use file(GLOB) in scripting mode not in configure mode
file(GLOB SOURCES src/*.cpp src/*.h)

# source groups:
# further information:
# https://cmake.org/cmake/help/latest/command/source_group.html
source_group(generated REGULAR_EXPRESSION .*automoc.cpp)
source_group(resources REGULAR_EXPRESSION .*[.][q]?rc)
source_group(source REGULAR_EXPRESSION .*[.]cpp)
source_group(header REGULAR_EXPRESSION .*[.]h)
source_group(continuous_integration REGULAR_EXPRESSION .*[.]yml)



#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#------------------- Commands -------------------
#
#------------------- Directory -------------------
# directory listing                   tree
# create directory                    mkdir <dir> (not portable)
#                                     cmake -E make_directory
# moving between directories          cd <dir> cd.. cd\


#------------------- Build -------------------
# build-system:

#------- Best practice:
# current directory: project root directory
# change directory                    chdir build-path
# build in directory                  cmake [-A Win32, x64, ARM, ARM64] source-path
# source directory example            cmake ..\

# using toolchain provided by vcpkg: (note: remember cleaning the build directory)
#     cmake -A x64 ..\ "-DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake"

# build project                       cmake --build [--clean-first] <dir>
#-------

# build (elapsed time)                cmake -E time cmake <dir>

# example of a complex command:
#     cmake --build build --target ProjectName --config Release --clean-first

# Additionally:
# build to current                    cmake <source-path>
# Notes:
# Current: Probably build folder.
# Source folder must be defined in CMake_Notes.txt (..\src\)
# build to current                    cmake .
#                                     cmake --build .
# build to path                       cmake <existing-build-path>
# Note: Settings must contain the path to source.
# didn't work :)                      cmake -S <src-path> -B <build-path>
# probably needs some creepy settings to be set! :)

# further information:
# https://cmake.org/cmake/help/v3.14/manual/cmake.1.html


#------------------- Useful -------------------
# present CMake version               cmake -version
# processing script (.cmake files)    cmake -P file.cmake



#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------
#------------------- CMakeSettings.json -------------------
#
# useful variables (usable in CMakeList.txt):
#     ${projectDir}
#     ${name}
#     $ENV{ProgramFiles}
#     $ENV{UserProfile}



#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#------------------- References -------------------
# https://www.slideshare.net/DanielPfeifer1/cmake-48475415
# http://derekmolloy.ie/hello-world-introductions-to-cmake/
# https://pmateusz.github.io
# https://github.com/nholthaus/cmake-cpp-project
# https://stackoverflow.com
# https://github.com/halex2005/CMakeHelpers
# https://docs.microsoft.com/
# https://cmake.org/cmake/help/latest/
# https://vcpkg.readthedocs.io/en/latest/
