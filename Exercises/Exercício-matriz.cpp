/*
Criar um algoritmo que mostre:
1) qual a soma dos elementos da matriz gerada? 
2) qual a media dos elementos da matriz gerada? 
3) qual o maior elemento da matriz gerada? 
4) qual a soma dos elementos da diagonal principal da matriz gerada?
5) qual a soma dos elementos da primeira linha da matriz gerada?
6) qual a soma dos elementos da ultima coluna da matriz gerada?
*/

#include <iostream> // Inclui a biblioteca de entrada e saida padrao.
#include <cstdlib>  // Inclui a biblioteca para funcoes de controle de processo e geracao de numeros aleatorios.
#include <ctime>    // Inclui a biblioteca para manipulacao de data e hora.
using namespace std; // Utiliza o namespace padrao para evitar a necessidade de prefixar std::.

#define TAMANHO 5 // Define uma constante para o tamanho da matriz.

int main() {
    system("cls"); // Limpa a tela do console (no Windows).
    int matriz[TAMANHO][TAMANHO], maior = 0, somap = 0, soma1 = 0, somau = 0; // Declaracao de variaveis inteiras.
    float media = 0, soma = 0; // Declaracao de variaveis de ponto flutuante.
    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios com o tempo atual.

    for (int i = 0; i < TAMANHO; i++) { // Loop externo para percorrer as linhas da matriz.
        for (int j = 0; j < TAMANHO; j++) { // Loop interno para percorrer as colunas da matriz.
            matriz[i][j] = rand() % 10; // Gera um numero aleatorio entre 0 e 9 e atribui a posicao [i][j] da matriz.
            cout << matriz[i][j] << " "; // Imprime o valor gerado na matriz.
            soma = soma + matriz[i][j]; // Soma o valor gerado a variavel soma.

            if (matriz[i][j] > maior) { // Verifica se o valor atual e maior que o maior valor encontrado ate agora.
                maior = matriz[i][j]; // Atualiza o maior valor.
            }

            if (i == j) { // Verifica se o elemento esta na diagonal principal.
                somap = somap + matriz[i][j]; // Soma o valor a soma da diagonal principal.
            }

            if (i == 0) { // Verifica se o elemento esta na primeira linha.
                soma1 = soma1 + matriz[i][j]; // Soma o valor a soma da primeira linha.
            }

            if (j == TAMANHO - 1) { // Verifica se o elemento esta na ultima coluna.
                somau = somau + matriz[i][j]; // Soma o valor a soma da ultima coluna.
            }
        }
        cout << endl; // Pula para a proxima linha no console.
    }

    media = soma / 25; // Calcula a media dos elementos da matriz.
    cout << "\nSoma Total: " << soma << "\nMedia Total: " << media << "\nMaior Elemento da Matriz: " 
         << maior << " " << "\nSoma da Diagonal Principal: " << somap << "\nSoma dos Elementos da Primeira Linha: " 
         << soma1 << "\nSoma dos Elementos da Ultima Coluna: " << somau << " "; // Imprime os resultados.
    
    return 1; // Retorna 1 para indicar que o programa terminou com sucesso.
}
