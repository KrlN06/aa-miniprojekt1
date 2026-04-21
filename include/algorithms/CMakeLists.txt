cmake_minimum_required(VERSION 4.2)
project(algorithms C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(algorithms
        IntroSort.h
        MergeSort.h
        QuickSort.h)
