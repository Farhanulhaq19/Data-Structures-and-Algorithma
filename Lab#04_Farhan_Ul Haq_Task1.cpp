#include <iostream>
using namespace std;
// This function performs a linear search on an unsorted array of integers to find the index of the target element.
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main()
{
    int target;
    cout << "Enter the element to find its index: ";
    cin >> target;
    int arr[] = {34,7,23,32,5,62};
    int size= sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, size, target);
    if (result!= -1)
    {
        cout << "Test Case 1: Element " <<target<< " found at index " << result<<endl;
    } 
    else
    {
        cout<<"Test Case 1: Element " <<target<<"not found"<<endl;
    }
    int arrf[] = {1,2,3,4,5};
    int size2 = sizeof(arrf) / sizeof(arrf[0]);
    int result2 = linearSearch(arrf, size2, target);
    if (result2!= -1)
    {
        cout <<"Test Case 2: Element "<<target<<" found at index "<<result2<<endl;
    }
    else
    {
        cout<<"Test Case 2: Element "<<target<<"not found"<<endl;
    }
    return 0;
}