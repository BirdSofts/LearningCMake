# ********************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,03.04.2019</created>
#/ <changed>ʆϒʅ,10.04.2019</changed>
# ********************************************************************************

# CMakeList.txt : CMake project for StaticAndSharedLibrary, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# option: build a shared version
set(BUILD_SHARED_LIB ON)

# project settings
set(TARGET_NAME StaticAndSharedLibrary)
set(PROJECT_NAME ${TARGET_NAME})
project(${PROJECT_NAME}
          VERSION 0.1.0.0
          DESCRIPTION "CMake notes and examples"
          HOMEPAGE_URL "https://github.com/BirdSofts/LearningCMake"
          LANGUAGES CXX
)

# source files
list(APPEND HEADER_FILES
          source/StaticAndSharedLibrary.h
)
list(APPEND SOURCE_FILES
          source/StaticAndSharedLibrary.cpp
)
if(WIN32)
          list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

# generate the dynamic library
if(${BUILD_SHARED_LIB} MATCHES ON)
add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})

# generate export header automatically
include(GenerateExportHeader)
generate_export_header(${TARGET_NAME}
          BASE_NAME ${TARGET_NAME}
          EXPORT_MACRO_NAME ${TARGET_NAME}_EXPORTS
          EXPORT_FILE_NAME ${TARGET_NAME}_EXPORTS.h
          STATIC_DEFINE ${TARGET_NAME}_EXPORTS_BUILD_AS_STATIC
)
else()
add_library (${TARGET_NAME} STATIC ${SOURCE_FILES})
endif()

# TODO: Add tests and install targets if needed.
