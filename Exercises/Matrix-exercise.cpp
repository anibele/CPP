/*
Create an algorithm that shows:
1) What is the sum of the elements of the generated matrix?
2) What is the average of the elements of the generated matrix?
3) What is the largest element of the generated matrix?
4) What is the sum of the elements of the main diagonal of the generated matrix?
5) What is the sum of the elements of the first row of the generated matrix?
6) What is the sum of the elements of the last column of the generated matrix?
*/

#include <iostream> // Includes the standard input and output library.
#include <cstdlib>  // Includes the library for process control functions and random number generation.
#include <ctime>    // Includes the library for date and time manipulation.
using namespace std; // Uses the standard namespace to avoid the need to prefix std::.

#define SIZE 5 // Defines a constant for the size of the matrix.

int main() {
    system("cls"); // Clears the console screen (on Windows).
    int matrix[SIZE][SIZE], largest = 0, sum_diag = 0, sum_first_row = 0, sum_last_col = 0; // Declaration of integer variables.
    float average = 0, sum = 0; // Declaration of floating-point variables.
    srand(time(NULL)); // Initializes the random number generator with the current time.

    for (int i = 0; i < SIZE; i++) { // Outer loop to traverse the rows of the matrix.
        for (int j = 0; j < SIZE; j++) { // Inner loop to traverse the columns of the matrix.
            matrix[i][j] = rand() % 10; // Generates a random number between 0 and 9 and assigns it to position [i][j] of the matrix.
            cout << matrix[i][j] << " "; // Prints the generated value in the matrix.
            sum = sum + matrix[i][j]; // Adds the generated value to the sum variable.

            if (matrix[i][j] > largest) { // Checks if the current value is greater than the largest value found so far.
                largest = matrix[i][j]; // Updates the largest value.
            }

            if (i == j) { // Checks if the element is on the main diagonal.
                sum_diag = sum_diag + matrix[i][j]; // Adds the value to the sum of the main diagonal.
            }

            if (i == 0) { // Checks if the element is in the first row.
                sum_first_row = sum_first_row + matrix[i][j]; // Adds the value to the sum of the first row.
            }

            if (j == SIZE - 1) { // Checks if the element is in the last column.
                sum_last_col = sum_last_col + matrix[i][j]; // Adds the value to the sum of the last column.
            }
        }
        cout << endl; // Moves to the next line in the console.
    }

    average = sum / 25; // Calculates the average of the elements of the matrix.
    cout << "\nTotal Sum: " << sum << "\nTotal Average: " << average << "\nLargest Element of the Matrix: " 
         << largest << " " << "\nSum of the Main Diagonal: " << sum_diag << "\nSum of the Elements of the First Row: " 
         << sum_first_row << "\nSum of the Elements of the Last Column: " << sum_last_col << " "; // Prints the results.
    
    return 1; // Returns 1 to indicate that the program ended successfully.
}
