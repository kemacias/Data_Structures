cmake_minimum_required(VERSION 3.31)
project(lab4 C)

set(CMAKE_C_STANDARD 90)

add_executable(lab4 main_deque.c
    deque.c
    deque.h)
