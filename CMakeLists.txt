cmake_minimum_required(VERSION 3.24)
project(CS-221_Assignment2)

set(CMAKE_CXX_STANDARD 23)

file(GLOB P1
        "P1/*.h"
        "P1/*.cpp"
        )

file(GLOB P2
        "P2/*h"
        "P2/*.cpp"
        )

file(GLOB P3
        "P3/*h"
        "P3/*.cpp"
        )

add_executable(CS-221_Assignment2 ${P2})