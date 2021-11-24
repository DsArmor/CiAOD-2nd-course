cmake_minimum_required(VERSION 3.20)
project(encode_decode)

set(CMAKE_CXX_STANDARD 14)

add_executable(encode_decode main.cpp Huffman.cpp Huffman.h Shannon_fano.cpp Shannon_fano.h)
