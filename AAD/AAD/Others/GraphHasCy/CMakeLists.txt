cmake_minimum_required(VERSION 3.8)
project(LambdaTest)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp graph.h graph.cpp graphgen.h graphgen.cpp)
add_executable(LambdaTest ${SOURCE_FILES})