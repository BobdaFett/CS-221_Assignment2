cmake_minimum_required(VERSION 3.24)
project(CS-221_Assignment2)

set(CMAKE_CXX_STANDARD 23)

file(GLOB P1
        "P1/*.h"
        "P1/*.cpp"
        )

add_executable(CS-221_Assignment2 ${P1})