#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <cstdlib>

// To regulate the curve
const int REPEAT = 800;

// InsertionSort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

//Merge
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSortHelper(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(std::vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

//MesureTime
double measureTime(std::vector<int> original, const std::string& algorithm) {
    double totalTime = 0.0;

    for (int i = 0; i < REPEAT; ++i) {
        std::vector<int> arr = original;

        auto start = std::chrono::high_resolution_clock::now();

        if (algorithm == "insertionSort") {
            insertionSort(arr);
        } else if (algorithm == "mergeSort") {
            mergeSort(arr);
        } else {
            std::cerr << "Unknown algorithm: " << algorithm << "\n";
            exit(1);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        totalTime += elapsed.count();
    }

    return totalTime / REPEAT;
}

//Main
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./timeToSort <insertionSort|mergeSort>\n";
        return 1;
    }

    std::string algorithm = argv[1];

    int size;
    while (std::cin >> size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }

        double avgTime = measureTime(arr, algorithm);
        std::cout << size << " " << avgTime << "\n";
    }

    return 0;
}

