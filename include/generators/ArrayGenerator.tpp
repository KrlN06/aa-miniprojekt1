#ifndef PROJEKT_1_ARRAYGENERATOR_TPP
#define PROJEKT_1_ARRAYGENERATOR_TPP

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

    if (sortedPercent == 0.0) {
        for (int i = 0; i < size; i++) {
            data.push_back(static_cast<T>(generateRandomInt(0, 9999)));
        }
        return data;
    }
    int sortedIndexes = static_cast<int>(size * sortedPercent);

    for (int i = 0; i < sortedIndexes; i++) {
        data.push_back(static_cast<T>(i));
    }
    int randomIndexes = size - sortedIndexes;
    for (int i = 0; i < randomIndexes; i++) {
        data.push_back(static_cast<T>(generateRandomInt(0, 9999)));
    }
    return data;
}
#endif
