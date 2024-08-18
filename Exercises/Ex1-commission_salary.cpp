// Ex1) Write an algorithm that reads the code of a salesperson of a company, 
// their fixed salary, and the total sales made by them.
// Each salesperson receives a fixed salary plus a commission proportional to 
// the sales made by them. The commission is 3% on total sales up to
// $1,000.00; 5% from $1,000.00 to $2,000.00 and 10% for sales above 
// $2,000.00. The objective of this algorithm is to show the salesperson's code, 
// the total of their sales, their fixed salary, and their total salary.

#include <iostream>
using namespace std;

int main(){
	cout << "Salary calculation algorithm\n";
	int code;
	float fixedSalary, totalSales, commission, totalSalary;
	cout << "Enter the salesperson's code: ";
	cin >> code;
	cout << "Enter the salesperson's fixed salary: ";
	cin >> fixedSalary;
	cout << "Enter the salesperson's total sales: ";
	cin >> totalSales;
	
	if (totalSales <= 1000) {
    commission = totalSales * (3.0 / 100);
  	} 
  	else if (totalSales <= 2000) {
    commission = totalSales * (5.0 / 100);
  	} 
	else {
    commission = totalSales * (10.0 / 100);
  	}
	
	totalSalary = fixedSalary + commission;
  	cout <<"The total sales of salesperson " << code << " was $" << totalSales << " and the total salary of the salesperson is: $" << totalSalary << endl;
	
	return 0;
}
