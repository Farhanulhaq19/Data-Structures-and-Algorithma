#include <iostream>
#include <ctime>
using namespace std;

void merge(int arr[],int l,int mid,int r) {
    int a1=mid - l+ 1;
    int a2=r - mid;
    int a[a1],b[a2];
    for (int i=0;i<a1;i++) {
        a[i]=arr[l + i];
    }
    for (int i = 0; i < a2; i++) {
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while (i < a1 && j < a2) {
        if (a[i]<=b[j]){
            arr[k]=a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < a1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < a2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void printArray(int arr[],int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void measureTime(int arr[],int n) {
    clock_t start=clock();
    mergeSort(arr,0,n - 1);
    clock_t end=clock();
    double time_taken=double(end - start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken by Merge Sort: " << time_taken << " seconds" << endl;
}
int main() {
    int arr1[] = {1,2,3,4,5,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Original array 1 (Already Sorted): ";
    printArray(arr1,n1);
    measureTime(arr1,n1);
    cout<<"Sorted array 1: ";
    printArray(arr1,n1);

    int arr2[]={6,5,4,3,2,1};
    int n2=sizeof(arr2) / sizeof(arr2[0]);
    cout<<"Original array 2 (Reverse Sorted): ";
    printArray(arr2, n2);
    measureTime(arr2, n2);
    cout<<"Sorted array 2: ";
    printArray(arr2, n2);

    int arr3[]={10,7,8,9,1,5};
    int n3=sizeof(arr3) / sizeof(arr3[0]);
    cout<<"Original array 3 (Random Unsorted): ";
    printArray(arr3,n3);
    measureTime(arr3,n3);
    cout<<"Sorted array 3: ";
    printArray(arr3,n3);

    return 0;
}