make_minimum_required(VERSION 3.8)
project(ME-Project1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(ME-Project1 main.cpp)
