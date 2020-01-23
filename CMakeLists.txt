cmake_minimum_required(VERSION 3.15)

project(Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(Project main.cpp HangmanGame.cpp HangmanGame.h)
