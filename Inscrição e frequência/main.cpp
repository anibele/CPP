#include <iostream>
#define TAM 100
using namespace std;
#include "metodos.h"
int main()
{
    Inscricao lista[TAM];
    Frequencia frequencias[TAM];
    int totalInscritos = 0;
    int totalFrequencias = 0;
    totalInscritos = conectarComBase("inscricoes.csv", lista, TAM);
    totalFrequencias = conectarComFrequencias("frequencias.csv", frequencias, TAM);
    totalInscritos = menu(lista, frequencias, totalInscritos, totalFrequencias);
    return 0;
}