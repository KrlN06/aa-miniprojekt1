#ifndef PROJEKT_1_QUICKSORT_TPP
#define PROJEKT_1_QUICKSORT_TPP

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

    int lt = left;
    int gt = right;

    int middle = left + (right - left) / 2;

    if (data[left] > data[middle]) {
        std::swap(data[left], data[middle]);
    }

    if (data[left] > data[right]) {
        std::swap(data[left], data[right]);
    }

    if (data[middle] > data[right]) {
        std::swap(data[middle], data[right]);
    }

    T pivot = data[middle];

    int i = left;

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
