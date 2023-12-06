# Version setup
cmake_minimum_required(VERSION 3.25)

# Setting up general info
project(Krom LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 99)

# Setting compiler info
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Adding libraries
add_executable(lexer src/main.c)

target_include_directories(lexer PRIVATE lib/)

# Compilar args
set(CMAKE_C_FLAGS "-v")
set(CMAKE_CXX_FLAGS "-v")
