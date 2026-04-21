#include <iostream>
#include <vector>
#include "include/algorithms/MergeSort.h"
#include "include/algorithms/QuickSort.h"
#include "include/algorithms/IntroSort.h"
#include "include/benchmarks/Benchmark.h"
#include "include/generators/ArrayGenerator.h"



int main() {


    Benchmark<int> benchmark;
    benchmark.run();


    return 0;
}

