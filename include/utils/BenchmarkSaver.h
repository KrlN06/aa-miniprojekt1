//
// Created by Karol Nalepa on 20/04/2026.
//

#ifndef PROJEKT_1_BENCHMARKSAVER_H
#define PROJEKT_1_BENCHMARKSAVER_H
#include <vector>


class BenchmarkSaver {
public:
    static void saveOperationResults(
        const std::string& filename,
        int sizes[],
        std::vector<long long>quickSort,
        std::vector<long long> mergeSort,
        std::vector<long long> introSort,
        int count
    );
};


#endif //PROJEKT_1_BENCHMARKSAVER_H
