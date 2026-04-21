#ifndef PROJEKT_1_BENCHMARK_TPP
#define PROJEKT_1_BENCHMARK_TPP
#include <iostream>

#include "../algorithms/QuickSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/IntroSort.h"
#include "../generators/ArrayGenerator.h"
#include "../utils/BenchmarkSaver.h"
#include "../utils/Timer.h"
#include <string>
#include <map>
#include <ostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

// Runs the full benchmark for all array sizes and initial sorting levels
template<typename T>
void Benchmark<T>::run() {

    // Iterate through all benchmark scenarios: random, 25%, 50%, etc.
    for (double percent : percents) {

        // Test all configured array sizes
        for (int size : sizes) {


            int datasetCount = 100;
            int repetitions = 100;


            // Generate datasets for current size and sorting percentage
            for (int i = 0; i < datasetCount; i++) {

                // Common dataset for all algorithms
                std::vector<T> data = ArrayGenerator<T>::generatePartiallySortedData(size, percent);

                // Run benchmarks on the same generated dataset
                benchmarkQuickSort(data, repetitions);
                benchmarkMergeSort(data, repetitions);
                benchmarkIntroSort(data, repetitions);
            }

            // Calculate average result for current array size
            quickSortResultsAverages.push_back(calculateAverage(quickSortResults));
            mergeSortResultsAverages.push_back(calculateAverage(mergeSortResults));
            introSortResultsAverages.push_back(calculateAverage(introSortResults));

            displayResults(size, percent);

            quickSortResults.clear();
            mergeSortResults.clear();
            introSortResults.clear();



        }

        std::map<double, std::string> filenames = {
            {0.0, "random.csv"},
            {0.25, "25_sorted.csv"},
            {0.50, "50_sorted.csv"},
            {0.75, "75_sorted.csv"},
            {0.95, "95_sorted.csv"},
            {0.99, "99_sorted.csv"},
            {0.997, "99_7_sorted.csv"}
        };

        const std::string filename = filenames.at(percent);

        // Save averaged benchmark results to CSV file
        BenchmarkSaver::saveOperationResults(
            filename,
            sizes,
            quickSortResultsAverages,
            mergeSortResultsAverages,
            introSortResultsAverages,
            SIZE
        );

        quickSortResultsAverages.clear();
        mergeSortResultsAverages.clear();
        introSortResultsAverages.clear();

    }

}


// Measures average execution time of QuickSort
template<typename T>
void Benchmark<T>::benchmarkQuickSort(const std::vector<T> &originalArray, int repetitions) {
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;
        Timer timer;

        timer.start();
        QuickSort<T>::sort(data);
        timer.stop();

        if (!std::is_sorted(data.begin(), data.end())) {
            throw std::runtime_error("QuickSort failed");
        }

        long long elapsed = timer.getElapsedTime();
        totalTime += elapsed;
    }

    quickSortResults.push_back(totalTime / repetitions);
}

// Measures average execution time of MergeSort
template<typename T>
void Benchmark<T>::benchmarkMergeSort(const std::vector<T>& originalArray, int repetitions) {
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;
        Timer timer;

        timer.start();
        MergeSort<T>::sort(data);
        timer.stop();

        if (!std::is_sorted(data.begin(), data.end())) {
            throw std::runtime_error("MergeSort failed");
        }

        long long elapsed = timer.getElapsedTime();
        totalTime += elapsed;
    }

    mergeSortResults.push_back(totalTime / repetitions);
}


// Measures average execution time of IntroSort
template<typename T>
void Benchmark<T>::benchmarkIntroSort(const std::vector<T>& originalArray, int repetitions) {
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;
        Timer timer;

        timer.start();
        IntroSort<T>::sort(data);
        timer.stop();

        if (!std::is_sorted(data.begin(), data.end())) {
            throw std::runtime_error("IntroSort failed");
        }

        long long elapsed = timer.getElapsedTime();
        totalTime += elapsed;
    }

    introSortResults.push_back(totalTime / repetitions);
}

template<typename T>
long long Benchmark<T>::calculateAverage(const std::vector<long long> &results) {

    if (results.empty()) {
        return 0;
    }

    long long sum = 0;
    for (long long result : results) {
        sum += result;
    }
    return sum / results.size();
}

template<typename T>
void Benchmark<T>::displayResults(int size, double percent) {

    std::cout << "===============================================" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<double>(percent * 100) << "% Benchmark Results" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "QuickSort: " << calculateAverage(quickSortResults) << "us" << std::endl;
    std::cout << "MergeSort: " << calculateAverage(mergeSortResults) << "us" << std::endl;
    std::cout << "IntroSort: " << calculateAverage(introSortResults) << "us" << std::endl;
}


#endif
