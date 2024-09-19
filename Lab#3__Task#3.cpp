#include <iostream>
using namespace std;
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int newSize = 11;
    int newArr[newSize];
    for (int i = 0; i < 10; ++i) {
        newArr[i] = arr[i];
    }
    int index;
    cout << "Enter the index at which to insert the new element from 1 to 10: ";
    cin >> index;
    int newValue;
    cout << "Enter the new value to insert: ";
    cin >> newValue;
    for (int i = newSize - 1; i > index - 1; --i) {
        newArr[i] = newArr[i - 1];
    }
    newArr[index - 1] = newValue;
    cout << "Updated array: ";
    for (int i = 0; i < newSize; ++i) {
        cout << newArr[i] << " ";
    }
    return 0;
}