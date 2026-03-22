cmake_minimum_required(VERSION 4.1)
project(geostrat C)

set(CMAKE_C_STANDARD 11)

add_executable(geostrat main.c
        src/ressources.c
        src/armee.c
        src/pays.c
        src/ressources.h
        src/armee.h
        src/pays.h)