#include <iostream>
using namespace std;
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
int main() {
    int size;
    cout << "Enter the size of the array (1 to 20): ";
    cin >> size;
    int* array = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << " (0 to 12): ";
        cin >> array[i];
        sum += array[i];
    }
    double average = (sum * 1.0) / size;
    cout << "Average of all elements: " << average << endl;
    for (int i = 0; i < size; i++) {
        cout << "Factorial of " << array[i] << " is " << factorial(array[i]) << endl;
    }
    delete[] array;
    return 0;
}
