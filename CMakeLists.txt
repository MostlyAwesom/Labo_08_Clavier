cmake_minimum_required(VERSION 3.12)
project(Labo_08_Clavier)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
add_executable(Labo_08_Clavier main.cpp SaisiesUtilisateurs.cpp SaisiesUtilisateurs.h GenerationAleatoire.cpp GenerationAleatoire.h chronometre.cpp chronometre.h)