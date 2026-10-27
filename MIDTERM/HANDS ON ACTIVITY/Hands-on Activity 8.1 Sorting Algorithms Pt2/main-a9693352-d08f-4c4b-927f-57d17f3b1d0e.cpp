#include <iostream>
#include "HybridSort.h"

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19,
74};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    printArray(arr, n);
    std::cout << "----------------------------------------\n";

    hybridQuickSort(arr, 0, n - 1);

    std::cout << "----------------------------------------\n";
    std::cout << "Final Sorted Array: ";
    printArray(arr, n);

    return 0;
}