cmake_minimum_required(VERSION 3.17)
project(UebungenGit)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UebungenGit
        graph.cpp
        graph.h
        main.cpp
        user_io.cpp
        user_io.h)
