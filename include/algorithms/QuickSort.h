//
// Created by Karol Nalepa on 13/04/2026.
//

#ifndef PROJEKT_1_QUICKSORT_H
#define PROJEKT_1_QUICKSORT_H
#include <vector>
#include <algorithm>


template<typename T>
class QuickSort {

public:
    static void sort(std::vector<T>& data);
public:
    static void quickSort(std::vector<T>& data, int left, int right);
    static int partition(std::vector<T>& data, int left, int right);
};

#include "QuickSort.tpp"


#endif //PROJEKT_1_QUICKSORT_H
