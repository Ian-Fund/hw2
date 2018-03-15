cmake_minimum_required(VERSION 3.8)
project(hw2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.cpp node.h stack.cpp stack.h)
add_executable(hw2 ${SOURCE_FILES})