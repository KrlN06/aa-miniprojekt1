#include <iostream>
#include <vector>
#include "include/algorithms/MergeSort.h"
#include "include/algorithms/QuickSort.h"
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



    return 0;
}

