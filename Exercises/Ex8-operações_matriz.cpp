// Ex8) Criar um algoritmo que gere uma matriz 4x4 com valores aleatórios
// e relizar operações com os elementos da matriz. As operações são:
// --> A soma dos elementos da primeira linha;
// --> O produto dos elementos da primeira coluna;
// --> A soma da diagonal principal;
// --> A soma de todos os elementos da matriz.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int matriz[4][4];
    int somapl = 0;
    int produtopc = 1;
    int somadp = 0;
    int somat = 0;
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 100 + 1;
            somat += matriz[i][j];
            if (i == 0) {
                somapl += matriz[i][j];
            }
            if (j == 0) {
                produtopc *= matriz[i][j];
            }
            if (i == j) {
                somadp += matriz[i][j];
            }
        }
    }
    cout << "Matriz 4x4 com valores aleatorios:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Soma dos elementos da primeira linha: " << somapl << endl;
    cout << "Produto dos elementos da primeira coluna: " << produtopc << endl;
    cout << "Soma da diagonal principal: " << somadp << endl;
    cout << "Soma de todos os elementos da matriz: " << somat << endl;
    return 0;
}