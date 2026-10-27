#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <utility>

template<typename T>
int routineSmallest(T arr[], int K, int maxSize) {
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < maxSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], int maxSize) {
    int POS;
    for (int i = 0; i < maxSize - 1; i++) {
        POS = routineSmallest(arr, i, maxSize);
        std::swap(arr[i], arr[POS]);
    }
}

template<typename T>
void bubbleSort(T arr[], int maxSize) {
    for (int i = 0; i < maxSize - 1; i++) {
        for (int j = 0; j < maxSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void insertionSort(T arr[], int maxSize) {
    int k = 1;
    int j;
    T temp;

    while (k < maxSize) {
        temp = arr[k];
        j = k - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}



#endif