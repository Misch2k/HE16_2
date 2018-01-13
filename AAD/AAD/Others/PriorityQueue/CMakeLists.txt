cmake_minimum_required(VERSION 3.8)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PriorityQueue.cpp PriorityQueue.h)
add_executable(PriorityQueue ${SOURCE_FILES})