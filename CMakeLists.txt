cmake_minimum_required(VERSION 3.17)
project(Pad3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pad3
        imagec.cpp
        imagec.h
        main.cpp
        user_io.cpp
        user_io.h)
