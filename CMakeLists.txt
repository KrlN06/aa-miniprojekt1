cmake_minimum_required(VERSION 4.2)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_1 main.cpp
        include/algorithms/MergeSort.h
        include/generators/ArrayGenerator.h
        include/algorithms/QuickSort.h
        include/algorithms/IntroSort.h
        include/benchmarks/Benchmark.h
        include/algorithms/MergeSort.tpp
        include/algorithms/QuickSort.tpp
        include/algorithms/IntroSort.tpp
        include/benchmarks/Benchmark.tpp
        include/generators/ArrayGenerator.tpp
)
