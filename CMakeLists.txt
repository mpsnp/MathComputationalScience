cmake_minimum_required(VERSION 2.8)
project(ComputationalScience)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(TCLAP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${TCLAP_INCLUDE_DIR})

set(SOURCE_FILES main.cpp CFunction.h CFunction.cpp)
add_executable(ComputationalScience ${SOURCE_FILES})
