cmake_minimum_required(VERSION 3.13)
project(prog C)

set(CMAKE_C_STANDARD 99)

add_executable(prog main.c list.h item.h list.c files.h files.c menu.h menu.c enter.h enter.c search.h search.c sort.h sort.c)