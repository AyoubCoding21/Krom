cmake_minimum_required(VERSION 3.25)

project(Krom LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23) 
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)


add_executable(lexer src/main.cxx)

target_include_directories(lexer PRIVATE lib/)
set(CMAKE_CXX_FLAGS "-v")
