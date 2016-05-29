cmake_minimum_required(VERSION 2.8)
project(ComputationalScience)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(TCLAP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${TCLAP_INCLUDE_DIR})

#set(COMMON_SOURCES CFunction.h CFunction.cpp)

set(INTERPOLATION_SOURCE_FILES interpolation.cpp ${COMMON_SOURCES})
add_executable(interpolation ${INTERPOLATION_SOURCE_FILES})

set(SOLVER_SOURCE_FILES solver.cpp)
add_executable(solver ${SOLVER_SOURCE_FILES})