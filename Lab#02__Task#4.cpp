#include <iostream>
using namespace std;
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    int index;
    cout << "Enter the index of the element to delete from 1 to 10: ";
    cin >> index;
    if (index < 1 || index > size) {
        cout << "Invalid index. Index must be between 1 and 10" << size << " " << endl;
        return 1;
    }
    for (int i = index - 1; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "The updated array is: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
