cmake_minimum_required(VERSION 4.2)
project(11_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(11_1 main.c
        point2d.c
        point2d.h
        cercle.c
        cercle.h
        triangle.c
        triangle.h)
