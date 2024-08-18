// Ex6) Faça um algoritmo que tenha 2 vetores inteiros de 20 posições, 
// os valores serão gerados aleatoriamente nesse exercício usando <cstdlib>.
// O usuário vai escolher uma operação matemática (+ , - , x, / ) que fará
// a operação entre os 2 vetores e armazenará em um terceiro vetor. Ao final
// mostrar as operações realizadas.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int vetor1[20], vetor2[20], resultado[20];
    char operacao;
    srand(time(0));

    for (int i = 0; i < 20; i++) {
        vetor1[i] = rand() % 100 + 1;
        vetor2[i] = rand() % 100 + 1;
    }
    cout << "Escolha uma operacao (+, -, x, /): ";
    cin >> operacao;

    for (int i = 0; i < 20; i++) {
        switch (operacao) {
            case '+':
                resultado[i] = vetor1[i] + vetor2[i];
                break;
            case '-':
                resultado[i] = vetor1[i] - vetor2[i];
                break;
            case 'x':
                resultado[i] = vetor1[i] * vetor2[i];
                break;
            case '/':
                if (vetor2[i] != 0) {
                    resultado[i] = vetor1[i] / vetor2[i];
                } else {
                    cout << "Erro: Divisao por zero na posicao " << i << endl;
                    resultado[i] = 0; 
                }
                break;
            default:
                cout << "Operacao invalida!" << endl;
                return 1;
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << "Operacao: " << vetor1[i] << " " << operacao << " " << vetor2[i] << " = " << resultado[i] << endl;
    }

    return 0;
}