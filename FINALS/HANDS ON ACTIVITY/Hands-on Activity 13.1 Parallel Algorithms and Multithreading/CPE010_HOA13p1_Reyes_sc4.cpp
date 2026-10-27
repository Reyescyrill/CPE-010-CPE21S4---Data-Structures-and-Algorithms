#include <iostream>
#include <vector>
#include <thread>
#include <functional>

// Standard Merge function to combine two sorted sub-arrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

// Parallel Merge Sort implementation
void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth = 0) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Limit thread creation depth (thresholding) to minimize thread management overhead
    if (depth < 2) {
        // Spawn separate threads for the left and right sub-arrays
        std::thread t1(parallelMergeSort, std::ref(arr), left, mid, depth + 1);
        std::thread t2(parallelMergeSort, std::ref(arr), mid + 1, right, depth + 1);

        // Wait for both sub-threads to complete sorting their respective sub-arrays
        t1.join();
        t2.join();
    } else {
        // Sequential fallback for deeper subproblems
        parallelMergeSort(arr, left, mid, depth + 1);
        parallelMergeSort(arr, mid + 1, right, depth + 1);
    }

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10, 19, 50, 12, 7, 64};

    std::cout << "Original Array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Execute Parallel Merge Sort
    parallelMergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted Array:   ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}