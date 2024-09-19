#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    if (arr == nullptr) {
        cout << "Memory not allocated." << std::endl;
        return -1;
    }
    cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key value to search: ";
    cin >> key;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Key value " << key << " found at location " << i + 1 << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Key value " << key << " not found in the array." <<endl;
    }
    delete[] arr;
    return 0;
}