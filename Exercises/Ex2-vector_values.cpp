// EX2) Write an algorithm to read four values, calculate the sum,
// calculate the average, and display the values greater than the average.

#include <iostream>
using namespace std;

int main() {
  float array[4];
  float sumValues = 0;
  float average;
  
  for (int i = 0; i < 4; i++) {
    cout << "Enter value " << (i + 1) << ": ";
    cin >> array[i];
    sumValues = sumValues + array[i];
  }
  average = sumValues / 4;
  cout << "The sum of the values: " << sumValues << endl;
  cout << "The average of the values: " << average << "\n";
  cout << "Values greater than the average: ";
  for (int i = 0; i < 4; i++) {
  	if (array[i] > average){
  		cout << array[i] << " ";
	  }
	}
  return 0;
}
