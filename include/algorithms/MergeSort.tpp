#ifndef PROJEKT_1_MERGESORT_TPP
#define PROJEKT_1_MERGESORT_TPP

// implementacje

template<typename T>
void MergeSort<T>::sort(std::vector<T> &data) {
    if (data.size() <= 1) {
        return;
    }
    mergeSort(data, 0, data.size() - 1);
}


template<typename T>
void MergeSort<T>::mergeSort(std::vector<T> &data, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

template<typename T>
void MergeSort<T>::merge(std::vector<T> &data, int left, int mid, int right) {

    std::vector<T> leftPart(data.begin() + left, data.begin() + mid + 1);
    std::vector<T> rightPart(data.begin() + mid + 1, data.begin() + right + 1);

    size_t i = 0;
    size_t j = 0;
    size_t k = static_cast<size_t>(left);
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            data[k] = leftPart[i];
            i++;    
        }
        else {
            data[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPart.size()) {
        data[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < rightPart.size()) {
        data[k] = rightPart[j];
        j++;
        k++;
    }



}

#endif