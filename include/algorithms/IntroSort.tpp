#ifndef PROJEKT_1_INTROSORT_TPP
#define PROJEKT_1_INTROSORT_TPP

template<typename T>
void IntroSort<T>::sort(std::vector<T>& data) {

    if (data.size() <= 1){
        return;
    }

    int depthLimit = 3 * static_cast<int>(log2(data.size()));

    introSort(data, 0, data.size() - 1, depthLimit);


}

template<typename T>
void IntroSort<T>::introSort(std::vector<T> &data, int left, int right, int depthLimit) {

    if (left >= right) {
        return;
    }


    int size = right - left + 1;

    if (size <= INSERTION_SORT_THRESHOLD) {
        insertionSort(data, left, right);
        return;
    }

    if (depthLimit <= 0) {
        heapSort(data, left, right);
        return;
    }

    int lt = left;
    int gt = right;

    int pivotIndex = medianOfThree(data, left, right);
    std::swap(data[left], data[pivotIndex]);
    T pivot = data[left];

    int i = left + 1;

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

    introSort(data, left, lt - 1, depthLimit - 1);
    introSort(data, gt + 1, right, depthLimit - 1);
}

template<typename T>
void IntroSort<T>::heapSort(std::vector<T> &data, int left, int right) {

    if (left >= right) {
        return;
    }

    int size = right - left + 1;

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(data, size, i, left);
    }

    for (int i = size - 1; i >= 1; i--) {
        std::swap(data[left], data[left + i]);
        heapify(data, i, 0, left);
    }

}

template<typename T>
void IntroSort<T>::heapify(std::vector<T> &data, int heapSize, int root, int offset) {

    int leftChildIndex = 2 * root + 1;
    int rightChildIndex = 2 * root + 2;

    int largestIndex = root;

    if (leftChildIndex < heapSize && data[offset + leftChildIndex] > data[offset + largestIndex] ) {
        largestIndex = leftChildIndex;
    }

    if (rightChildIndex < heapSize && data[offset + rightChildIndex] > data[offset + largestIndex]) {
        largestIndex = rightChildIndex;
    }
    if (largestIndex != root) {
        std::swap(data[offset + root], data[offset + largestIndex]);
        heapify(data, heapSize, largestIndex, offset);
    }
}

template<typename T>
void IntroSort<T>::insertionSort(std::vector<T> &data, int left, int right) {

    for (int i = left + 1; i <= right; i++) {
        T key = data[i];
        int j = i - 1;
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

template<typename T>
int IntroSort<T>::medianOfThree(std::vector<T>& data, int left, int right) {

    int mid = left + (right - left) / 2;

    if (data[left] > data[mid]) {
        std::swap(data[left], data[mid]);
    }

    if (data[left] > data[right]) {
        std::swap(data[left], data[right]);
    }

    if (data[mid] > data[right]) {
        std::swap(data[mid], data[right]);
    }

    return mid;
}

#endif
