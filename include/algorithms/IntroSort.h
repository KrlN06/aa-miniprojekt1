//
// Created by Karol Nalepa on 13/04/2026.
//

#ifndef PROJEKT_1_INTROSORT_H
#define PROJEKT_1_INTROSORT_H
#include <vector>
#include <cmath>

template<typename T>
class IntroSort {

public:

    static void sort(std::vector<T>& data);

private:

    static constexpr int INSERTION_SORT_THRESHOLD = 16;

    static void introSort(std::vector<T>& data, int left, int right, int depthLimit);

    static int partition(std::vector<T>& data, int left, int right);

    static void heapSort(std::vector<T>& data, int left, int right);

    static void heapify(std::vector<T>& data, int heapSize, int root, int offset);

    static void insertionSort(std::vector<T>& data, int left, int right);

    static int medianOfThree(std::vector<T>& data, int left, int right);

};


#include "IntroSort.tpp"

#endif // PROJEKT_1_INTROSORT_H