#ifndef PROJEKT_1_BENCHMARK_TPP
#define PROJEKT_1_BENCHMARK_TPP

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
#endif








