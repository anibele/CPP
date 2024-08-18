// Ex1) Escrever um algoritmo que lê o código de um vendedor de uma empresa, 
// seu salário fixo e o total de vendas efetuadas por ele.
// Cada vendedor recebe um salário fixo, mais uma comissão proporcional às 
// vendas efetuadas por ele. A comissão é 3% sobre o total de vendas até
// R$1.000,00; 5% de R$ 1.000,00 à 2.000,00 e 10% para vendas acima de 
// 2.000,00. O objetivo desse algoritmo é mostrar o código do vendedor, 
// o total de suas vendas, seu salário fixo e o seu salário total.

#include <iostream>
using namespace std;

int main(){
	cout << "Algoritmo de calculo de salario\n";
	int codigo;
	float salariofixo, totalvendas, comissao, salariototal;
	cout << "Digite o codigo do vendedor: ";
	cin >> codigo;
	cout << "Digite o salario fixo do vendedor: ";
	cin >> salariofixo;
	cout << "Digite o total de vendas do vendedor: ";
	cin >> totalvendas;
	
	if (totalvendas <= 1000) {
    comissao = (totalvendas * (3.0 / 100));
  	} 
  	else if (totalvendas <= 2000) {
    comissao = (totalvendas * (5.0 / 100));
  	} 
	else {
    comissao = (totalvendas * (10.0 / 100));
  	}
	
	salariototal = salariofixo + comissao;
  	cout <<"O total de vendas do vendedor " << codigo << " foi R$" << totalvendas<< " e o salario total do vendedor eh: R$" << salariototal << endl;
	
	return 0;
}