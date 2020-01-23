cmake_minimum_required(VERSION 3.15)
project(ME-Project1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(Project1 main.cpp HangmanGame.cpp HangmanGame.h)
