// EX1) Faça um método que receba uma valor inteiro qualquer e que exiba se o valor passado no parâmetro é par ou ímpar.
#include <iostream>
using namespace std;
#include "verificador.h"
int main() {
    int valor;
    cout << "Digite um valor inteiro: ";
    cin >> valor;
    verificaParOuImpar(valor);
    return 0;
}