#include <iostream>
#include <vector>
#include "include/algorithms/MergeSort.h"
#include "include/algorithms/QuickSort.h"
#include "include/algorithms/IntroSort.h"
#include "include/generators/ArrayGenerator.h"



int main() {

    std::vector<int> dataMerge;

    for (int i = 0; i < 20; i++) {
        dataMerge.push_back(ArrayGenerator<int>::generateRandomInt(1, 100));
    }

    for (int x : dataMerge) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    MergeSort<int>::sort( dataMerge);

    for (int x : dataMerge) {
        std::cout << x << " ";
    }
    std::cout << std::endl;




    std::vector<int> dataQuick;
    for (int i = 0; i < 20; i++) {
        dataQuick.push_back(ArrayGenerator<int>::generateRandomInt(1, 100));
    }

    for (int y :dataQuick) {
        std::cout << y << " ";
    }
    std::cout << std::endl;

    QuickSort<int>::sort( dataQuick);

    for (int y : dataQuick) {
        std::cout << y << " ";
    }
    std::cout << std::endl;


    std::vector<int> randomData = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> sortedData = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> reversedData = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> duplicatesData = {5, 2, 5, 1, 5, 3, 2, 1, 4};
    std::vector<int> singleElement = {42};
    std::vector<int> emptyData = {};


    IntroSort<int>::sort(randomData);
    IntroSort<int>::sort(sortedData);
    IntroSort<int>::sort(reversedData);
    IntroSort<int>::sort(duplicatesData);
    IntroSort<int>::sort(singleElement);
    IntroSort<int>::sort(emptyData);

    std::cout << "randomData: ";
    for (int value : randomData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "sortedData: ";
    for (int value : sortedData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "reversedData: ";
    for (int value : reversedData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "duplicatesData: ";
    for (int value : duplicatesData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "singleElement: ";
    for (int value : singleElement) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "emptyData: ";
    for (int value : emptyData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    return 0;
}

