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

private:
    static std::mt19937 gen;
};

template<typename T>
std::mt19937 ArrayGenerator<T>::gen(std::random_device{}());


template<typename T>
int ArrayGenerator<T>::generateRandomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}



#endif //PROJEKT_1_ARRAYGENERATOR_H
