cmake_minimum_required(VERSION 4.3)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp
        saisir.cpp
        saisir.h
        afficher.cpp
        afficher.h)