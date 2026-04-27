#ifndef PROJEKT_1_QUICKSORT_TPP
#define PROJEKT_1_QUICKSORT_TPP

#include <algorithm>
#include <cmath>

template<typename T>
void QuickSort<T>::sort(std::vector<T>& data) {
    if (data.size() <= 1) return;

    QuickSort<T> sorter;
    sorter.quickSort(data, 0, data.size() - 1);
}

template<typename T>
void QuickSort<T>::insertionSort(std::vector<T>& data, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T key = data[i];
        int j = i - 1;
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

template<typename T>
void QuickSort<T>::quickSort(std::vector<T>& data, int left, int right) {
    if (left >= right) return;

    // small optimization
    if (right - left <= 16) {
        insertionSort(data, left, right);
        return;
    }

    // median-of-three
    int mid = left + (right - left) / 2;

    if (data[left] > data[mid]) std::swap(data[left], data[mid]);
    if (data[left] > data[right]) std::swap(data[left], data[right]);
    if (data[mid] > data[right]) std::swap(data[mid], data[right]);

    // pivot = median
    T pivot = data[mid];


    int lt = left;
    int i = left;
    int gt = right;

    while (i <= gt) {
        if (data[i] < pivot) {
            std::swap(data[i], data[lt]);
            i++;
            lt++;
        }
        else if (data[i] > pivot) {
            std::swap(data[i], data[gt]);
            gt--;
        }
        else {
            i++;
        }
    }

    quickSort(data, left, lt - 1);
    quickSort(data, gt + 1, right);
}

#endif