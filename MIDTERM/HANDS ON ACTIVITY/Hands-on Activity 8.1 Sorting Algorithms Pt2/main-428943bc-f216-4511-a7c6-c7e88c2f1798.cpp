#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithms.h"

const int SIZE = 100;

// Prints the array cleanly in 10 columns
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

// Copies original unsorted array so every test uses the exact same base data
void copyArray(const int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int originalArray[SIZE];
    int testArray[SIZE];

    // Seed random number generator and generate 100 random values (0 to 999)
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = std::rand() % 1000;
    }

    // --- PREPARATION TASK (TABLE 8-1) ---
    std::cout << "========================================================\n";
    std::cout << " TABLE 8-1: ORIGINAL UNSORTED ARRAY (100 Elements)\n";
    std::cout << "========================================================\n";
    printArray(originalArray, SIZE);

    // --- SHELL SORT (TABLE 8-2) ---
    copyArray(originalArray, testArray, SIZE);
    shellSort(testArray, SIZE);
    std::cout << "========================================================\n";
    std::cout << " TABLE 8-2: SHELL SORT RESULT\n";
    std::cout << "========================================================\n";
    printArray(testArray, SIZE);

    // --- MERGE SORT (TABLE 8-3) ---
    copyArray(originalArray, testArray, SIZE);
    mergeSort(testArray, 0, SIZE - 1);
    std::cout << "========================================================\n";
    std::cout << " TABLE 8-3: MERGE SORT RESULT\n";
    std::cout << "========================================================\n";
    printArray(testArray, SIZE);

    // --- QUICK SORT (TABLE 8-4) ---
    copyArray(originalArray, testArray, SIZE);
    quickSort(testArray, 0, SIZE - 1);
    std::cout << "========================================================\n";
    std::cout << " TABLE 8-4: QUICK SORT RESULT\n";
    std::cout << "========================================================\n";
    printArray(testArray, SIZE);

    return 0;
}