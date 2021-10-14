cmake_minimum_required(VERSION 3.20)
project(trees)

set(CMAKE_CXX_STANDARD 14)
#SET(CMAKE_EXE_LINKER_FLAGS  "/FORCE")

add_executable(trees main.cpp trees.cpp main.h trees.h)
