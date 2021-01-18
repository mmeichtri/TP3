cmake_minimum_required(VERSION 3.17)
project(TP_2_Elementos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP_2_Elementos
        agua.cpp
        agua.h
        aire.cpp
        aire.h
        fuego.cpp
        fuego.h
        lista.cpp
        lista.h
        main.cpp
        menu.cpp
        menu.h
        nodo.cpp
        nodo.h
        personajes.cpp
        personajes.h
        tierra.cpp
        tierra.h)
