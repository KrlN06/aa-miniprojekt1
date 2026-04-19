//
// Created by Karol Nalepa on 19/04/2026.
//

#ifndef PROJEKT_1_BENCHMARK_H
#define PROJEKT_1_BENCHMARK_H
#include "../algorithms/QuickSort.h"
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

    void benchmarkQuickSort(const std::vector<T>& originalArray);

    void benchmarkMergeSort(const std::vector<T>& originalArray);

    void benchmarkIntroSort(const std::vector<T>& originalArray);

    long long calculateAverage(const std::vector<long long>& results);

    void displayResults(int size);
};

template<typename T>
void Benchmark<T>::run() {

    for (double percent : percents) {

        for (int size : sizes) {


            for (int i = 0; i < 100; i++) {


                //Common datasets
                std::vector<T> data = ArrayGenerator<T>::generatePartiallySortedData(size, percent);

                //Arrays to be sorted by different algorithms
                std::vector<T> quickSortData = data;
                std::vector<T> mergeSortData = data;
                std::vector<T> introSortData = data;



                //Run benchmarks
                benchmarkQuickSort(quickSortData);
                benchmarkMergeSort(quickSortData);
                benchmarkIntroSort(quickSortData);

                displayResults(size);

            }
            quickSortResultsAverages.push_back(calculateAverage(quickSortResults));
            mergeSortResultsAverages.push_back(calculateAverage(mergeSortResults));
            introSortResultsAverages.push_back(calculateAverage(introSortResults));

            quickSortResults.clear();
            mergeSortResults.clear();
            introSortResults.clear();


        }
    }

}










#endif //PROJEKT_1_BENCHMARK_H
