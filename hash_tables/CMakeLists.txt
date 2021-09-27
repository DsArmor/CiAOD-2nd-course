cmake_minimum_required(VERSION 3.20)
project(hash_tables)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_tables hash_table.h bank_account.h bank_account.cpp main.cpp main.h)
