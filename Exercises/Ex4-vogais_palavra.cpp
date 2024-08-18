// Ex4) Faça um algoritmo que leia uma palavra digitada e mostre apenas as vogais
// escritas com letras minusculas.

#include <string>
#include <iostream>
using namespace std;

int main(){
	string palavra;
	cout << "Escreva uma palavra: ";
	cin >> palavra;
	cout << "vogais presentes na palavra digitada: ";
	int tamanho = palavra.length();
	for (int i=0;i<tamanho;i++){
		if(palavra[i] == 'a'){
			cout << "a ";
		}
		else if(palavra[i] == 'e'){
			cout << "e ";
		}
		else if(palavra[i] == 'i'){
			cout << "i ";
		}
		else if(palavra[i] == 'o'){
			cout << "o ";
		}
		else if(palavra[i] == 'u'){
			cout << "u ";
		}
	}
	return 0;

}
