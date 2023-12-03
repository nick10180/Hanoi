cmake_minimum_required(VERSION 3.18.4)
project(Hanoi)

set(CMAKE_CXX_STANDARD 14)

link_libraries("-static")
add_executable(Hanoi main.cpp)
