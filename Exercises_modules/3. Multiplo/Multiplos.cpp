//Ex3) Faça um método que receba dois valores inteiros e escreva na tela se o primeiro parâmetro é ou não múltiplo do segundo 
#include <iostream>
using namespace std;
#include "verificador.h"
int main() {
    int valor1, valor2;
    cout << "Digite o primeiro valor inteiro: ";
    cin >> valor1;
    cout << "Digite o segundo valor inteiro: ";
    cin >> valor2;
    verificaMultiplo(valor1, valor2);
    return 0;
}