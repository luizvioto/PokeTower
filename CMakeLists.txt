cmake_minimum_required(VERSION 3.27)
project(PokeTower)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PokeTower
        classes.cpp
        classes.h
        funcoes.cpp
        funcoes.h
        global_objects.cpp
        global_objects.h
        main.cpp)
