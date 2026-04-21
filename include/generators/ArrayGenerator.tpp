#ifndef PROJEKT_1_ARRAYGENERATOR_TPP
#define PROJEKT_1_ARRAYGENERATOR_TPP
#include <algorithm>

template<typename T>
std::mt19937 ArrayGenerator<T>::gen(std::random_device{}());


template<typename T>
int ArrayGenerator<T>::generateRandomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}



template<typename T>
std::vector<T> ArrayGenerator<T>::generateRandomData(int size) {
    return generatePartiallySortedData(size, 0.0);
}


template <typename T>
std::vector<T> ArrayGenerator<T>::generatePartiallySortedData(int size, double sortedPercent) {

    std::vector<T> data;
    data.reserve(size);

    for (int i = 0; i < size; i++) {
        data.push_back(static_cast<T>(generateRandomInt(0, 9999)));
    }

    if (sortedPercent <= 0.0) {
        return data;
    }

    int sortedIndexes = static_cast<int>(size * sortedPercent);
    sortedIndexes = std::min(sortedIndexes, size);

    std::sort(data.begin(), data.begin() + sortedIndexes);

    return data;
}
#endif
