// EX2) Escrever um algoritmo para ler quatro valores, calcular a soma,
// calcular a média e escrever na tela os valores maiores que a média.

#include <iostream>
using namespace std;

int main() {
  float vetor[4];
  float somavalores = 0;
  float media;
  
  for (int i = 0; i < 4; i++) {
    cout << "Digite o valor " << (i+1) << ": ";
    cin >> vetor[i];
    somavalores = somavalores + vetor[i];
  }
  media = somavalores / 4;
  cout << "A soma dos valores: " << somavalores << endl;
  cout << "A media dos valores: " << media << "\n";
  cout << "Valores maiores que a media: ";
  for (int i = 0; i < 4; i++) {
  	if (vetor[i] > media){
  		cout << vetor[i] << " ";
	  }
	}
  return 0;
}