cmake_minimum_required(VERSION 3.8)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph.cpp GraphUtil.cpp GraphUtil.h)
add_executable(Graph ${SOURCE_FILES})