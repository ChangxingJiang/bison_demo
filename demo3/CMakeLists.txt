cmake_minimum_required(VERSION 3.28)
project(test_bison)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_bison
        calculator.c
        calculator.h
        mylex.c
        calculator.tab.h
        calculator.tab.c

)
