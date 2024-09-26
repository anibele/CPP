/*
Baseado no exercicio glicemia (Struct + Lista + Arquivo)
adaptar ou refatorarpara que gerencie/manipule cripto moedas
menu
1 - Listar criptos
2 - Cadastrar cripto (Controle Duplicidade)
3 - Remover cripto
4 - sair
ciptos.csv nome real;sigla;valor (em USD por unidade)
*/
#include <iostream>
#include <string>
#define TAM 100

using namespace std;
#include "metodos.h"

int main()
{
    Cripto lista[TAM];
    int totalCadastrados = 0;

    // conectar com a base
    totalCadastrados = conectarComBase("criptos.csv", lista, TAM);

    // gerar menu
    totalCadastrados = menu(lista, totalCadastrados, TAM);
    return 1;
}
