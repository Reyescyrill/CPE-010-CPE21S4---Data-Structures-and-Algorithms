cmake_minimum_required(VERSION 3.20)
project(HOA5P11)

set(CMAKE_CXX_STANDARD 17)

# Make sure both .cpp files are listed here
add_executable(HOA5P11 main.cpp Printer.cpp
        job.h
        node.h
        printer.h
        Printer.cpp)