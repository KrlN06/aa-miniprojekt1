//
// Created by Karol Nalepa on 19/04/2026.
//

#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H
#include "../generators/ArrayGenerator.h"
#include <vector>


template<typename T>
class Benchmark {

public:
    void run();

    static constexpr int SIZE = 9;
    static constexpr int PERCENT_COUNT = 7;



private:


    int sizes[SIZE] = {
        100,
        500,
        1000,
        5000,
        10000,
        50000,
        100000,
        500000,
        1000000
    };

    double percents[PERCENT_COUNT] = {
        0.0,
        0.25,
        0.50,
        0.75,
        0.95,
        0.99,
        0.997
    };




    std::vector<long long> quickSortResults;
    std::vector<long long> mergeSortResults;
    std::vector<long long> introSortResults;

    std::vector<long long> quickSortResultsAverages;
    std::vector<long long> mergeSortResultsAverages;
    std::vector<long long> introSortResultsAverages;

    void benchmarkQuickSort(const std::vector<T>& originalArray, int repetitions);

    void benchmarkMergeSort(const std::vector<T>& originalArray, int repetitions);

    void benchmarkIntroSort(const std::vector<T>& originalArray, int repetitions);

    long long calculateAverage(const std::vector<long long>& results);

    void displayResults(int size, double percent);
};

#include "Benchmark.tpp"


#endif //PROJEKT_1_BENCHMARK_H
