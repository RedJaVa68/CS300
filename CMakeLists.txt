cmake_minimum_required(VERSION 3.20)
project(ProjectTwo)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjectTwo main.cpp FileReader.cpp FileReader.h Course.cpp Course.h)
