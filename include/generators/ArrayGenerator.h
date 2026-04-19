//
// Created by Karol Nalepa on 10/04/2026.
//

#ifndef PROJEKT_1_ARRAYGENERATOR_H
#define PROJEKT_1_ARRAYGENERATOR_H
#include <random>

template<typename T>
class ArrayGenerator {
public:
    static int generateRandomInt(int min, int max);
    static std::vector<T> generateRandomData(int size);
    static std::vector<T> generatePartiallySortedData(int size, double sortedPercent);

private:
    static std::mt19937 gen;
};

#include "ArrayGenerator.tpp"




#endif //PROJEKT_1_ARRAYGENERATOR_H
