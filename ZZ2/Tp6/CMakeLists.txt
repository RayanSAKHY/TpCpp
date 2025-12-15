cmake_minimum_required(VERSION 4.0)
project(Tp6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tp6
        verif.cpp
        Error.cpp
        CPP6/PileG.hpp
        CPP6/Pile.hpp
        CPP6/tests_catch.cpp
        CPP6/Pile.cpp
        CPP6/main.cpp
        CPP6/main_test.cpp)
