cmake_minimum_required(VERSION 3.5)
project(AlgoOA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp solution.h solution.cpp)
add_executable(AlgoOA ${SOURCE_FILES})
