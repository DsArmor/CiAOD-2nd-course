cmake_minimum_required(VERSION 3.20)
project(search_in_text)

set(CMAKE_CXX_STANDARD 14)

add_executable(search_in_text main.cpp pair.cpp search_boyer.cpp test.cpp)
