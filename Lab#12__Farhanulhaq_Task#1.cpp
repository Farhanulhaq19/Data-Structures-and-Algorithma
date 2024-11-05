#include <iostream>
#include <ctime>
using namespace std;
void swap(int arr[], int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = (l - 1);
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void printArray(int arr[],int size) {
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void measureTime(int arr[],int n) {
    clock_t start=clock();
    quickSort(arr,0,n-1);
    clock_t end = clock();
    double time_taken=double(end - start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken by QuickSort: "<<time_taken << " seconds" << endl;
}
int main() {
    int arr1[] = {10,7,8,9,1,5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original array 1: ";
    printArray(arr1, n1);
    measureTime(arr1, n1);
    cout<<"Sorted array 1: ";
    printArray(arr1,n1);

    int arr2[]={1,2,3,4,5,6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original array 2 (Nearly Sorted): ";
    printArray(arr2, n2);
    measureTime(arr2, n2);
    cout << "Sorted array 2: ";
    printArray(arr2, n2);

    int arr3[]={6,5,4,3,2,1};
    int n3=sizeof(arr3) / sizeof(arr3[0]);
    cout<<"Original array 3 (Completely Unsorted): ";
    printArray(arr3,n3);
    measureTime(arr3,n3);
    cout<<"Sorted array 3: ";
    printArray(arr3,n3);

    return 0;
}