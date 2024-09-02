//Ex2) Faça um método que receba uma frase qualquer e exiba caracter por caracter, um abaixo do outro.
#include <iostream>
#include <string>
using namespace std;
#include "caracter.h"
int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);
    exibeCaracterPorCaracter(frase);
    return 0;
}