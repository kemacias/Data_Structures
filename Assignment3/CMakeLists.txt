cmake_minimum_required(VERSION 3.31)
project(Assignment3 C)

set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(Assignment3
        listbag.c
        listbag.h
        main_bag.c)
