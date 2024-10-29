#include <iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
    int comparisons=0,swaps=0;
    for (int i=1;i<n;i++) {
        int key= arr[i];
        int j= i - 1;
        while(j >=0 && arr[j]< key) {
            comparisons++;
            arr[j+1]=arr[j];
            j=j-1;
            swaps++;
        }
        arr[j+1]=key;
        swaps++;
    }
    cout<<"Comparisons: "<<comparisons<<" ,Swaps: "<<swaps<<endl;
}
void printArray(int arr[],int n)
{
    for (int i =0;i <n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void testInsertionSort() {
    int arr1[]={5,2,9,1,5,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]={1,2,3,4,5,6};
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    int arr3[]={6,5,4,3,2,1};
    int n3=sizeof(arr3)/sizeof(arr3[0]);

    cout<<"Original array: ";
    printArray(arr1,n1);
    insertionSort(arr1,n1);
    cout<<"Sorted array: ";
    printArray(arr1,n1);

    cout<<"Original array: ";
    printArray(arr2,n2);
    insertionSort(arr2,n2);
    cout<<"Sorted array: ";
    printArray(arr2,n2);

    cout<<"Original array: ";
    printArray(arr3,n3);
    insertionSort(arr3,n3);
    cout << "Sorted array: ";
    printArray(arr3,n3);
}
// Time Complexity:
                //Worst Case: O(n^2)

                //Best Case: O(n)

                // Average Case: O(n^2)
int main()
{
    testInsertionSort();
    return 0;
}