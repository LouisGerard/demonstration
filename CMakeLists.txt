cmake_minimum_required(VERSION 3.9)
project(modale)

set(CMAKE_CXX_STANDARD 11)

add_executable(modale main.cpp
        infix2postfix.cpp infix2postfix.h
        Arbre.cpp Arbre.h
        Regle.cpp Regle.h
        Monde.cpp Monde.h
        k.cpp k.h MondeContrainte.cpp MondeContrainte.h)