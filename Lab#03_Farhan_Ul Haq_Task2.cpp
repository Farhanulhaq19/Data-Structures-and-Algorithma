#include <iostream>
using namespace std;
// This function performs a binary search on a sorted array of integers to find the index of the target element.
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int target;
    cout << "Enter the element to find its index: ";
    cin >> target;
    int arr[] = {2,5,12,23,38,45,62};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, target);
    if (result!= -1) {
        cout<<"Test Case 1: Element "<<target<<"found at index "<<result<<endl;
    } else {
        cout<<"Test Case 1: Element "<<target<<" not found"<<endl;
    }
    int arrf[] = {3,6,8,12, 15, 20, 33};
    int size2 = sizeof(arrf) / sizeof(arrf[0]);
    int result2 = binarySearch(arrf, size2, target);
    if (result2 != -1) {
        cout << "Test Case 2: Element " << target<< "found at index" <<result2<<endl;
    } else {
        cout << "Test Case 2: Element " << target << " not found" << endl;
    }
    return 0;
}
