#include <iostream>
#include <vector>
#include "include/algorithms/MergeSort.h"
#include "include/generators/ArrayGenerator.h"


int main() {
    std::vector<int> data;

    for (int i = 0; i < 20; i++) {
        data.push_back(ArrayGenerator<int>::generateRandomInt(1, 100));
    }

    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    MergeSort<int>::sort( data);

    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

