// Ex7) faça um algoritmo que gere uma matriz 10x10, leia 10 
// números digitados pelo usuário e então verifique se estes 
// números estão na matriz. Se estiverem, mostrar a posição 
// deles, por exemplo: “O valor X foi encontrado na posição
// I,J da matriz”.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int matriz[10][10];
    int valores[10];
    bool encontrado;

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
    cout << "Digite 10 valores entre 1 e 100 para verificar na matriz: " << endl;
    for (int i = 0; i < 10; i++) {
    	cout << "valor " << i+1 << ": ";
        cin >> valores[i];
    }
    for (int k = 0; k < 10; k++) {
        encontrado = false;
        for (int i = 0; i < 10 && !encontrado; i++) {
            for (int j = 0; j < 10; j++) {
                if (matriz[i][j] == valores[k]) {
                    cout << "O valor " << valores[k] << " foi encontrado na posicao " << i << "," << j << " da matriz." << endl;
                    encontrado = true;
                    break;
                }
            }
        }
        if (!encontrado) {
            cout << "O valor " << valores[k] << " nao foi encontrado na matriz." << endl;
        }
    }
    return 0;
}