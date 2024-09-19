#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;
int linearSearch(const int* arr, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int binarySearch(const int* arr, int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}
template <typename Func>
double measureTime(Func searchFunc, const int* arr, int size, int key) {
    auto start = chrono::high_resolution_clock::now();
    searchFunc(arr, size, key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}
int main() {
    const int numTrials = 100;
    int sizes[] = {100000, 200000, 500000, 1000000};
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 1000000);
    cout << "Array Size, Linear Search Time (s), Binary Search Time (s)" << endl;
    for (int size : sizes) {
        int* arr = new int[size];
        int* sortedArr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = distribution(generator);
        }
        copy(arr, arr + size, sortedArr);
        sort(sortedArr, sortedArr + size);
        int key = distribution(generator);
        double linearTotalTime = 0.0;
        double binaryTotalTime = 0.0;
        for (int i=0;i<numTrials;i++)
        {
            linearTotalTime += measureTime(linearSearch, arr, size, key);
            binaryTotalTime += measureTime(binarySearch, sortedArr, size, key);
        }
        double avgLinearTime = linearTotalTime / numTrials;
        double avgBinaryTime = binaryTotalTime / numTrials;
        cout << size << ", " << fixed << setprecision(6) << avgLinearTime << ", " << avgBinaryTime << endl;
        delete[] arr;
        delete[] sortedArr;
    }
    return 0;
}