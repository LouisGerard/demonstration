cmake_minimum_required(VERSION 3.9)
project(modale)

set(CMAKE_CXX_STANDARD 11)

add_executable(modale main.cpp
        infix2postfix.cpp infix2postfix.h
        Expression.cpp Expression.h
        Arbre.cpp Arbre.h
        Regle.cpp Regle.h)