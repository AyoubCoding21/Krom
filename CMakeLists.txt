# Version setup
cmake_minimum_required(VERSION 3.25)

# Setting up general info
project(Krom LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23) 

# Setting compiler info
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Adding libraries
add_executable(lexer src/main.cxx)
target_include_directories(lexer PRIVATE lib/)

# Compilar args
set(CMAKE_C_FLAGS "-v")
set(CMAKE_CXX_FLAGS "-v")
