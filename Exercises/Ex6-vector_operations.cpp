// Ex6) Write an algorithm that has 2 integer arrays of 20 positions,
// the values will be generated randomly in this exercise using <cstdlib>.
// The user will choose a mathematical operation (+, -, x, /) that will perform
// the operation between the 2 arrays and store it in a third array. At the end,
// show the operations performed.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int array1[20], array2[20], result[20];
    char operation;

    srand(time(0));
    for (int i = 0; i < 20; i++) {
        array1[i] = rand() % 100 + 1;
        array2[i] = rand() % 100 + 1;
    }

    cout << "Choose an operation (+, -, x, /): ";
    cin >> operation;
    for (int i = 0; i < 20; i++) {
        switch (operation) {
            case '+':
                result[i] = array1[i] + array2[i];
                break;
            case '-':
                result[i] = array1[i] - array2[i];
                break;
            case 'x':
                result[i] = array1[i] * array2[i];
                break;
            case '/':
                if (array2[i] != 0) {
                    result[i] = array1[i] / array2[i];
                } else {
                    cout << "Error: Division by zero at position " << i << endl;
                    result[i] = 0; 
                }
                break;
            default:
                cout << "Invalid operation!" << endl;
                return 1;
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << "Operation: " << array1[i] << " " << operation << " " << array2[i] << " = " << result[i] << endl;
    }
    return 0;
}
