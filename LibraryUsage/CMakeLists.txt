# ********************************************************************************
#/ <summary>
#/
#/ </summary>
#/ <created>ʆϒʅ,04.04.2019</created>
#/ <changed>ʆϒʅ,14.10.2019</changed>
# ********************************************************************************

cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# option: link to the shared version
set(LINK_SHARED_LIB ON)

set(TARGET_NAME LibraryUsage)
set(PROJECT_NAME ${TARGET_NAME})
project(${PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "CMake notes and examples"
  HOMEPAGE_URL "https://github.com/BirdSofts/LearningCMake"
  LANGUAGES CXX
  )

set(ROOT $ENV{UserProfile}/Source/Repos/LearningCMake)

if(${LINK_SHARED_LIB} MATCHES ON)
  # dynamic library linkage
  set(PROJECT_LINK_LIBS StaticAndSharedLibrary.dll)
  link_directories(${ROOT}/StaticAndSharedLibrary/build)
else()
  # static library linkage
  set(PROJECT_LINK_LIBS StaticAndSharedLibrary.lib)
  link_directories(${ROOT}/StaticAndSharedLibrary/build)
endif()

include_directories(${ROOT}/StaticAndSharedLibrary/source)

# Add source to this project's executable.
add_executable (${TARGET_NAME} "source/LibraryUsage.cpp")

if(${LINK_SHARED_LIB} MATCHES ON)
  # pre and post build event
  # copy library into target directory
  # must follow a generation event
  add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
    COMMAND cmake -E copy_if_different
    ${ROOT}/StaticAndSharedLibrary/build/debug/StaticAndSharedLibrary.dll
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endif()

target_link_libraries(${TARGET_NAME} ${PROJECT_LINK_LIBS})
