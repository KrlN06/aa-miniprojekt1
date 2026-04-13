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

template<typename T>
void QuickSort<T>::sort(std::vector<T> &data) {
    if (data.size() <= 1) {
        return;
    }
    quickSort(data, 0, data.size() - 1);
}


template<typename T>
void QuickSort<T>::quickSort(std::vector<T> &data, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(data, left, right);

    quickSort(data, left, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, right);

}

template<typename T>
int QuickSort<T>::partition(std::vector<T>& data, int left, int right) {

    int i = left - 1;
    T pivot = data[right];

    for (int j = left; j < right; j++) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[j], data[i]);
        }
    }
    std::swap(data[i + 1], data[right]);
    int pivotIndex = i + 1;
    return pivotIndex;

}


#endif //PROJEKT_1_QUICKSORT_H
