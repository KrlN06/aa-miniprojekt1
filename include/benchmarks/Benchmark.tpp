#ifndef PROJEKT_1_BENCHMARK_TPP
#define PROJEKT_1_BENCHMARK_TPP
#include "../algorithms/QuickSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/IntroSort.h"
#include "../generators/ArrayGenerator.h"
#include "../utils/BenchmarkSaver.h"
#include "../utils/Timer.h"

// Runs the full benchmark for all array sizes and initial sorting levels
template<typename T>
void Benchmark<T>::run() {

    // Iterate through all benchmark scenarios: random, 25%, 50%, etc.
    for (double percent : percents) {

        // Test all configured array sizes
        for (int size : sizes) {


            // Generate 100 different arrays for each size and scenario
            for (int i = 0; i < 100; i++) {


                //Common datasets
                std::vector<T> data = ArrayGenerator<T>::generatePartiallySortedData(size, percent);

                //Arrays to be sorted by different algorithms
                std::vector<T> quickSortData = data;
                std::vector<T> mergeSortData = data;
                std::vector<T> introSortData = data;



                //Run benchmarks
                benchmarkQuickSort(quickSortData, REPETITIONS);
                benchmarkMergeSort(mergeSortData, REPETITIONS);
                benchmarkIntroSort(introSortData, REPETITIONS);

            }
            // Calculate average result for current array size
            quickSortResultsAverages.push_back(calculateAverage(quickSortResults));
            mergeSortResultsAverages.push_back(calculateAverage(mergeSortResults));
            introSortResultsAverages.push_back(calculateAverage(introSortResults));

            quickSortResults.clear();
            mergeSortResults.clear();
            introSortResults.clear();

            displayResults(size);

        }
        // Select output filename based on current sorting percentage
        std::string filename;

        if (percent == 0.0) {
            filename = "random.csv";
        } else if (percent == 0.25) {
            filename = "25_sorted.csv";
        } else if (percent == 0.50) {
            filename = "50_sorted.csv";
        } else if (percent == 0.75) {
            filename = "75_sorted.csv";
        } else if (percent == 0.95) {
            filename = "95_sorted.csv";
        } else if (percent == 0.99) {
            filename = "99_sorted.csv";
        } else if (percent == 0.997) {
            filename = "99_7_sorted.csv";
        }

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
    Timer timer;
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;
        timer.start();
        QuickSort<T>::sort(data);
        timer.stop();

        totalTime += timer.getElapsed();
    }
    quickSortResults.push_back(totalTime / repetitions);
}

// Measures average execution time of MergeSort
template<typename T>
void Benchmark<T>::benchmarkMergeSort(const std::vector<T>& originalArray, int repetitions) {
    Timer timer;
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;

        timer.start();
        MergeSort<T>::sort(data);
        timer.stop();

        totalTime += timer.getElapsed();
    }

    mergeSortResults.push_back(totalTime / repetitions);
}

// Measures average execution time of IntroSort
template<typename T>
void Benchmark<T>::benchmarkIntroSort(const std::vector<T>& originalArray, int repetitions) {
    Timer timer;
    long long totalTime = 0;

    for (int i = 0; i < repetitions; i++) {
        std::vector<T> data = originalArray;

        timer.start();
        IntroSort<T>::sort(data);
        timer.stop();

        totalTime += timer.getElapsed();
    }

    introSortResults.push_back(totalTime / repetitions);
}

#endif
