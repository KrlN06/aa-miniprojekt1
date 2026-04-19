//
// Created by Karol Nalepa on 09/04/2026.
//

#ifndef PROJEKT_1_MERGESORT_H
#define PROJEKT_1_MERGESORT_H
#include <vector>

template<typename T>
class MergeSort {

public:
    static void sort(std::vector<T>& data);

private:
    static void mergeSort(std::vector<T>& data, int left, int right);
    static void merge(std::vector<T>& data, int left, int mid, int right);

};

#include "MergeSort.tpp"

#endif //PROJEKT_1_MERGESORT_H
