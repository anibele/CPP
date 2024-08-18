// Ex7) Create an algorithm that generates a 10x10 matrix, reads 10
// numbers entered by the user, and then checks if these
// numbers are in the matrix. If they are, show their position,
// for example: "The value X was found at position I,J in the matrix."

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int matrix[10][10];
    int values[10];
    bool found;

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
    cout << "Enter 10 values between 1 and 100 to check in the matrix: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "value " << i+1 << ": ";
        cin >> values[i];
    }
    for (int k = 0; k < 10; k++) {
        found = false;
        for (int i = 0; i < 10 && !found; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] == values[k]) {
                    cout << "The value " << values[k] << " was found at position " << i << "," << j << " in the matrix." << endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "The value " << values[k] << " was not found in the matrix." << endl;
        }
    }
    return 0;
}
