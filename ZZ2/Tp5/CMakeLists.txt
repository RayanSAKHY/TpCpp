cmake_minimum_required(VERSION 4.0)
project(Tp5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tp5
        Chaine.cpp
        Chaine.hpp
        main.cpp
        main_test.cpp
        tests_catch.cpp
        Agregateur.cpp
        Agregateur.hpp
        OutOfRangeException.cpp)
