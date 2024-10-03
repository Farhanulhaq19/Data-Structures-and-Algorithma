#include <iostream>
using namespace std;
bool is_palindrome(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    int arr[] = {1,2,3,4,5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (is_palindrome(arr, size)) {
        cout << "The array represents a palindrome." <<endl;
    } else {
        cout<< "The array do not represent a palindrome." <<endl;
    }
    return 0;
}
