// Ex5) Faça um algoritmo que possua 2 vetores. Um deles preenchido com
// valores sequenciais de 0 a 9 e outro com valores sequenciais de 10 a
// 19. Intercale os 2 vetores em um terceiro vetor, gerando uma nova 
// variável. Mostre o vetor obtido no final.

#include <iostream>
using namespace std;
int main(){
	int vetor1[10], vetor2[10], vetor3[20];
	for (int i=0;i<10;i++){
		vetor1[i] = i;
		vetor2[i] = i + 10;
	    vetor3[2 * i] = vetor1[i];
        vetor3[2 * i + 1] = vetor2[i];
    }
    for (int i=0;i<20;i++){
    	cout << vetor3[i] << " ";
	}
return 0;
}