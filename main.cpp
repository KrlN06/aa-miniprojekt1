#include <iostream>
#include <vector>
#include "include/algorithms/MergeSort.h"
#include "include/algorithms/QuickSort.h"
#include "include/algorithms/IntroSort.h"
#include "include/benchmarks/Benchmark.h"
#include "include/generators/ArrayGenerator.h"

using namespace std;

// ===== helper: print =====
template<typename T>
void printArray(const vector<T>& arr) {
    for (const auto& x : arr) cout << x << " ";
    cout << endl;
}

// ===== presentation mode =====
void presentationMode() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    ArrayGenerator<int> generator;

    cout << "\nWybierz typ danych:\n";
    cout << "1 - Losowe\n";
    cout << "2 - 50% posortowane\n";
    cout << "3 - 95% posortowane\n";
    cout << "4 - Odwrotnie posortowane\n";
    cout << "Wybor: ";

    int type;
    cin >> type;

    vector<int> data;

    switch (type) {
        case 1:
            data = generator.generateRandomData(n);
            break;
        case 2:
            data = generator.generatePartiallySortedData(n, 0.5);
            break;
        case 3:
            data = generator.generatePartiallySortedData(n, 0.95);
            break;
        case 4:
            data = generator.generateReverseSortedData(n);
            break;
        default:
            cout << "Niepoprawny wybor\n";
            return;
    }

    cout << "\nTablica przed sortowaniem:\n";
    printArray(data);

    cout << "\nWybierz algorytm:\n";
    cout << "1 - QuickSort\n";
    cout << "2 - MergeSort\n";
    cout << "3 - IntroSort\n";
    cout << "Wybor: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            QuickSort<int> sorter;
            sorter.sort(data);
            break;
        }
        case 2: {
            MergeSort<int> sorter;
            sorter.sort(data);
            break;
        }
        case 3: {
            IntroSort<int> sorter;
            sorter.sort(data);
            break;
        }
        default:
            cout << "Niepoprawny wybor\n";
            return;
    }

    cout << "\nTablica po sortowaniu:\n";
    printArray(data);
}

int main() {

    int mode;

    cout << "=== MENU ===\n";
    cout << "1 - Benchmark\n";
    cout << "2 - Prezentacja\n";
    cout << "Wybor: ";
    cin >> mode;

    switch (mode) {
        case 1: {
            Benchmark<int> benchmark;
            benchmark.run();
            break;
        }
        case 2:
            presentationMode();
            break;
        default:
            cout << "Niepoprawny wybor\n";
    }

    return 0;
}

