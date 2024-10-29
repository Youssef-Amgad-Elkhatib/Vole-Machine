cmake_minimum_required(VERSION 3.27)
project(Vole_machine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Vole_machine
        CPU.cpp
        CPU.h
        Instructions.cpp
        Instructions.h
        main.cpp
        Memory.cpp
        Memory.h
        ram.cpp
        ram.h
        Registers.cpp
        Registers.h)
