# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp headers/composition.h headers/aggregation.h headers/overload.h headers/construct.h headers/contain.h headers/inherit.h headers/coursera.h)