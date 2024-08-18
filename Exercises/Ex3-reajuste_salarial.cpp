// Ex3) Escreva um algoritmo para calcular o reajuste salarial de uma empresa que possui 1000
// funcionários de acordo com os seguintes critérios:
// --> os funcionários com salário inferior a 10.000 devem receber 55% de reajuste;
// --> os funcionários com salário entre 10.000 e 25.000 devem receber 30% de reajuste;
// --> os funcionários com salário acima de 25.000 devem receber 20% de reajuste.
// Para esse exercício, vamos gerar valores aleatórios de salários que variam de 8.000 a 
// 30.000 utilizando <cstdlib>.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    float salarioInicial[1000], salarioReajustado[1000];
    cout << "Algoritmo de reajuste salarial" << endl;

    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        salarioInicial[i] = 8000 + rand() % 22000; 
    }

    for (int i = 0; i < 1000; i++) {
        if (salarioInicial[i] < 10000) {
            salarioReajustado[i] = salarioInicial[i] * 1.55;
        } else if (salarioInicial[i] <= 25000) {
            salarioReajustado[i] = salarioInicial[i] * 1.30;
        } else {
            salarioReajustado[i] = salarioInicial[i] * 1.20;
        }
    }

    for (int i = 0; i < 1000; i++) {
        cout << "Funcionario " << i + 1 << ": Salario inicial: R$" << salarioInicial[i] 
             << " | Salario reajustado: R$" << salarioReajustado[i] << endl;
    }

    return 0;
}
