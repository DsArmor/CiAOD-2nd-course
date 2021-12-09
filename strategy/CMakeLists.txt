cmake_minimum_required(VERSION 3.20)
project(strategy)

set(CMAKE_CXX_STANDARD 14)

add_executable(strategy main.cpp salesman.cpp salesman.h matrix.cpp matrix.h)
