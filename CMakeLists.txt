cmake_minimum_required(VERSION 3.8)
project(problem4_Search)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp parameters.h Grids.cpp Grids.h XY.cpp XY.h)
add_executable(problem4_Search ${SOURCE_FILES})