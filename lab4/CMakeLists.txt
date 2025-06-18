cmake_minimum_required(VERSION 3.29)
project(lab4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab4
    funcs.c
    funcs.h
    main.c
    structs.h)
