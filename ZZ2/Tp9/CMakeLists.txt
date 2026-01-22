cmake_minimum_required(VERSION 4.1)
project(Tp9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tp9
        ZZ.cpp
        ZZ.hpp
        ComparateurZZ.cpp
        ComparateurZZ.hpp
        main.cpp
        rand_0_100.cpp
        rand_0_100.hpp)
