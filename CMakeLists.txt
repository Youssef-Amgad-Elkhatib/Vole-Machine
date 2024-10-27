cmake_minimum_required(VERSION 3.27)
project(Vole_machine)

set(CMAKE_CXX_STANDARD 23)

add_executable(Vole_machine main.cpp
        Memory.h
        Memory.cpp
        Instructions.h
        Instructions.cpp
        Registers.h
        Registers.cpp
        ALU.h
        ALU.cpp
        ram.h
        ram.cpp)
