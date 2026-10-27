#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H

#include <iostream>
#include <algorithm>

// Insertion Sort used to sort sub-lists
inline void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Standard Quick Sort Partition
inline int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort partition combined with Insertion Sort for left/right sub-lists
inline void hybridQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        std::cout << "After Partitioning (Pivot = " << arr[pivotIndex] << "): ";
        for (int k = low; k <= high; k++) std::cout << arr[k] << " ";
        std::cout << "\n";

        // Sort Left Sub-list using Insertion Sort
        if (low < pivotIndex - 1) {
            insertionSort(arr, low, pivotIndex - 1);
        }

        // Sort Right Sub-list using Insertion Sort
        if (pivotIndex + 1 < high) {
            insertionSort(arr, pivotIndex + 1, high);
        }
    }
}

#endif