//Ex4) Faça um método que receba um número inteiro entre 1 a 10 e o escreva em romanos.
#include <iostream>
using namespace std;
#include "converter.h"
int main() {
    int valor;
    cout << "Digite um numero inteiro entre 1 e 10: ";
    cin >> valor;
    converteParaRomano(valor);
    return 0;
}