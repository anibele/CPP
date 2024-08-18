// Ex3) Write an algorithm to calculate the salary adjustment for a company that has 1000
// employees according to the following criteria:
// --> employees with a salary below 10,000 should receive a 55% adjustment;
// --> employees with a salary between 10,000 and 25,000 should receive a 30% adjustment;
// --> employees with a salary above 25,000 should receive a 20% adjustment.
// For this exercise, we will generate random salary values ranging from 8,000 to 
// 30,000 using <cstdlib>.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    float initialSalary[1000], adjustedSalary[1000];
    cout << "Salary adjustment algorithm" << endl;

    srand(time(0)); 
    for (int i = 0; i < 1000; i++) {
        initialSalary[i] = 8000 + rand() % 22000; 
    }

    for (int i = 0; i < 1000; i++) {
        if (initialSalary[i] < 10000) {
            adjustedSalary[i] = initialSalary[i] * 1.55;
        } else if (initialSalary[i] <= 25000) {
            adjustedSalary[i] = initialSalary[i] * 1.30;
        } else {
            adjustedSalary[i] = initialSalary[i] * 1.20;
        }
    }

    for (int i = 0; i < 1000; i++) {
        cout << "Employee " << i + 1 << ": Initial salary: $" << initialSalary[i] 
             << " | Adjusted salary: $" << adjustedSalary[i] << endl;
    }
    return 0;
}
