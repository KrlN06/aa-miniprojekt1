#ifndef PROJEKT_1_QUICKSORT_H
#define PROJEKT_1_QUICKSORT_H

#include <vector>

template<typename T>
class QuickSort {
public:
    static void sort(std::vector<T>& data);

private:
    void quickSort(std::vector<T>& data, int left, int right);
    void insertionSort(std::vector<T>& data, int left, int right);
};

#include "QuickSort.tpp"

#endif
