# Version setup
cmake_minimum_required(VERSION 3.25)

# Setting up general info
project(Krom LANGUAGES C)

# Setting compiler info
set(CMAKE_C_COMPILER clang)

# Adding libraries
add_executable(lexer src/main.cxx)
target_include_directories(lexer PRIVATE lib/)

# Compilar args
set(CMKE_C_FLAGS "-v")
