//
// Created by Karol Nalepa on 20/04/2026.
//

#include "BenchmarkSaver.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

void BenchmarkSaver::saveOperationResults(
    const std::string& filename,
    int sizes[],
    const std::vector<long long>& quickSort,
    const std::vector<long long>& mergeSort,
    const std::vector<long long>& introSort,
    int count
) {
    std::filesystem::create_directory("results");
    std::ofstream file("results/" + filename);

    if (!file.is_open()) {
        std::cout << "Cannot open file: results/" << filename << std::endl;
        return;
    }

    file << "Size,QuickSort,MergeSort,IntroSort\n";

    for (int i = 0; i < count; i++) {
        file << sizes[i] << ","
             << quickSort[i] << ","
             << mergeSort[i] << ","
             << introSort[i] << "\n";
    }

    file.close();

    std::cout << "Results saved to results/" << filename << std::endl;
}