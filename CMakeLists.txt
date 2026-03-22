cmake_minimum_required(VERSION 4.1)
project(geostrat C)

set(CMAKE_C_STANDARD 11)

add_executable(geostrat main.c
        ressources.c
        armee.c
        pays.c
        ressources.h
        armee.h
        pays.h)
