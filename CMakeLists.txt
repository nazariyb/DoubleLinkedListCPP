cmake_minimum_required(VERSION 3.10)
project(dl_list_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(dl_list_cpp main.cpp
                            dl_list.h dl_list.cpp node.cpp node.h)