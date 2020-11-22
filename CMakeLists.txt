cmake_minimum_required(VERSION 3.17)
project(Pad3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pad3
        graph.cpp
        graph.h
        graphsearch.cpp
        graphsearch.h
        main.cpp
        user_io.cpp
        user_io.h)
