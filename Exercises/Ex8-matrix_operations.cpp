// Ex8) Create an algorithm that generates a 4x4 matrix with random values
// and performs operations with the elements of the matrix. The operations are:
// --> The sum of the elements in the first row;
// --> The product of the elements in the first column;
// --> The sum of the main diagonal;
// --> The sum of all the elements in the matrix.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int matrix[4][4];
    int sumfr = 0;
    int prodfc = 1;
    int summd = 0;
    int sumt = 0;
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = rand() % 100 + 1;
            sumt += matrix[i][j];
            if (i == 0) {
                sumfr += matrix[i][j];
            }
            if (j == 0) {
                prodfc *= matrix[i][j];
            }
            if (i == j) {
                summd += matrix[i][j];
            }
        }
    }
    cout << "4x4 matrix with random values:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Sum of the elements in the first row: " << sumfr << endl;
    cout << "Product of the elements in the first column: " << prodfc << endl;
    cout << "Sum of the main diagonal: " << summd << endl;
    cout << "Sum of all the elements in the matrix: " << sumt << endl;
    return 0;
}