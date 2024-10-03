#include <iostream>
using namespace std;

void printMatrix(int matrix[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[3][4], int transposedMatrix[4][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int transposedMatrix[4][3];

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    transposeMatrix(matrix, transposedMatrix);

    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
