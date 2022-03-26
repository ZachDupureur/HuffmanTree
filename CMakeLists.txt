cmake_minimum_required(VERSION 3.21)
project(HuffmanTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanTree main.cpp header.h implementation.cpp HuffmanCode.txt)

message(SEND_ERRORS)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/HuffmanCode.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/HuffmanMessage.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)