#include <iostream>
using namespace std;
void searchInMatrix(int matrix[4][4], int n) {
    bool found = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == n) {
                cout << "Value found at row " << i << ", column " << j << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Value not found in the matrix." << endl;
    }
}
int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n;
    cout << "Enter the value to search for: ";
    cin >> n;
    cout << "Matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    searchInMatrix(matrix,n);
    return 0;
}