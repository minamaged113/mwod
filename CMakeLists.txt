################################################################################
# CMake properties
set(MWOD_CMAKE_VERSION 3.16)
cmake_minimum_required(VERSION ${MWOD_CMAKE_VERSION})

################################################################################
# Project details
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(TARGET MWOD)

PROJECT(
    ${TARGET}
    LANGUAGES C CXX
    DESCRIPTION "A simple stopwatch application"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

################################################################################
# Enable testing
enable_testing()
# Add Google Test
find_package(GTest REQUIRED)
# Add include directories
include_directories(${GTEST_INCLUDE_DIRS})

################################################################################
# Build libraries
add_library(
    ${TARGET}_view
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/src/view/view.cc
)

################################################################################
# Main executable build
add_executable(
    ${TARGET}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
)

target_link_libraries(
    ${TARGET}
    ${TARGET}_view
)
################################################################################
# Main tests build
# set(TARGET_TEST test_${TARGET})
set(TEST_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test/test_view.cc
)

add_test(NAME test_${TARGET}_view COMMAND test_${TARGET}_view)

add_executable(test_${TARGET}_view
    ${TEST_SOURCE_FILES}
)

set_target_properties(test_${TARGET}_view PROPERTIES COMPILE_OPTIONS "")

target_include_directories(test_${TARGET}_view
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(test_${TARGET}_view
    gtest
    pthread
    ${TARGET}_view
)
