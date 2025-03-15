#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#define TAM 10
#define PRECO_POR_HORA 5.0

using namespace std;

struct Garagem {
    string placa;
    string dataE;
    string horaE;
    string horaS;
    int tempoPermanencia;
    float valor;
};

int calculaTempoPermanencia(string horaE, string horaS) {
    int horaEntrada = stoi(horaE.substr(0, 2));
    int minutoEntrada = stoi(horaE.substr(3, 2));
    int horaSaida = stoi(horaS.substr(0, 2));
    int minutoSaida = stoi(horaS.substr(3, 2));
    int minutosEntrada = horaEntrada * 60 + minutoEntrada;
    int minutosSaida = horaSaida * 60 + minutoSaida;
    return max(0, minutosSaida - minutosEntrada);
}

string getHoraAtual() {
    time_t agora = time(0);
    tm *ltm = localtime(&agora);
    int hora = ltm->tm_hour;
    int minuto = ltm->tm_min;
    return (hora < 10 ? "0" : "") + to_string(hora) + ":" + (minuto < 10 ? "0" : "") + to_string(minuto);
}

string getDataAtual() {
    time_t agora = time(0);
    tm *ltm = localtime(&agora);
    int dia = ltm->tm_mday;
    int mes = ltm->tm_mon + 1;
    int ano = ltm->tm_year + 1900;
    return (dia < 10 ? "0" : "") + to_string(dia) + "/" + (mes < 10 ? "0" : "") + to_string(mes) + "/" + to_string(ano);
}

void salvarRegistroCSV(Garagem veiculo) {
    ofstream arquivo("registro_garagem.csv", ios::app);
    if (arquivo.is_open()) {
        arquivo << veiculo.placa << "," << veiculo.dataE << "," << veiculo.horaE << "," 
                << veiculo.horaS << "," << veiculo.tempoPermanencia << "," << veiculo.valor << "\n";
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo CSV\n";
    }
}

bool verificaPlacaDuplicada(Garagem lista[], int totalVeiculos, string placa) {
    for (int i = 0; i < TAM; i++) {
        if (lista[i].placa == placa) {
            return true;
        }
    }
    return false;
}

void entradaVeiculo(Garagem lista[], int &totalVeiculos) {
    if (totalVeiculos == TAM) {
        cout << "Garagem lotada\n";
        return;
    }
    
    int i;
    for (i = 0; i < TAM; i++) {
        if (lista[i].placa.empty()) {
            break;
        }
    }

    string placa;
    do {
        cout << "Placa: ";
        cin >> placa;
        if (verificaPlacaDuplicada(lista, totalVeiculos, placa)) {
            cout << "Placa ja registrada! Insira outra.\n";
        }
    } while (verificaPlacaDuplicada(lista, totalVeiculos, placa));

    lista[i].placa = placa;
    lista[i].dataE = getDataAtual();
    lista[i].horaE = getHoraAtual();
    cout << "Entrada registrada com sucesso!" << endl;
    cout << "Data: " << lista[i].dataE << " Hora: " << lista[i].horaE << endl;
    totalVeiculos++;
}

void saidaVeiculo(Garagem lista[], int &totalVeiculos) {
    if (totalVeiculos == 0) {
        cout << "Garagem vazia\n";
        return;
    }

    string placa;
    cout << "Digite a placa do veiculo: ";
    cin >> placa;

    int i;
    for (i = 0; i < TAM; i++) {
        if (lista[i].placa == placa) {
            break;
        }
    }

    if (i < TAM) {
        lista[i].horaS = getHoraAtual();
        cout << "Hora de saida: " << lista[i].horaS << endl;
        lista[i].tempoPermanencia = calculaTempoPermanencia(lista[i].horaE, lista[i].horaS);
        lista[i].valor = (lista[i].tempoPermanencia / 60.0) * PRECO_POR_HORA;
        cout << "Tempo de permanencia: " << lista[i].tempoPermanencia << " minutos\n";
        cout << "Valor a pagar: R$ " << lista[i].valor << endl;
        
        salvarRegistroCSV(lista[i]);
        lista[i] = Garagem();
        totalVeiculos--;
    } else {
        cout << "Veiculo nao encontrado na garagem\n";
    }
}

void listarVeiculos(Garagem lista[], int totalVeiculos) {
    if (totalVeiculos == 0) {
        cout << "Garagem vazia\n";
    } else {
        for (int i = 0; i < TAM; i++) {
            if (!lista[i].placa.empty()) {
                cout << "Veiculo: " << lista[i].placa << endl;
            }
        }
    }
}

void exibirRelatorioDiario() {
    ifstream arquivo("registro_garagem.csv");
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo.\n";
        return;
    }

    string linha;
    cout << "Relatorio Diario:\n";
    cout << "Placa\tData Entrada\tHora Entrada\tHora Saida\tTempo\tValor\n";
    cout << "------------------------------------------------------------\n";

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string placa, dataE, horaE, horaS, tempoStr, valorStr;
        
        getline(ss, placa, ',');
        getline(ss, dataE, ',');
        getline(ss, horaE, ',');
        getline(ss, horaS, ',');
        getline(ss, tempoStr, ',');
        getline(ss, valorStr, ',');
        
        int tempo = stoi(tempoStr);
        float valor = stof(valorStr);

        cout << placa << "\t" << dataE << "\t" << horaE << "\t" << horaS << "\t" 
             << tempo << " min\t" << valor << " R$\n";
    }

    arquivo.close();
}

int main() {
    int opcao;
    Garagem lista[TAM] = {};
    int totalVeiculos = 0;
    
    do {
        system("cls");
        cout << "Menu Garagem\n";
        cout << "1 - Entrada veiculo\n";
        cout << "2 - Saida veiculo\n";
        cout << "3 - Lista veiculos em garagem\n";
        cout << "4 - Exibir relatorio diario\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                entradaVeiculo(lista, totalVeiculos);
                break;
            case 2:
                saidaVeiculo(lista, totalVeiculos);
                break;
            case 3:
                listarVeiculos(lista, totalVeiculos);
                break;
            case 4:
                exibirRelatorioDiario();
                break;
            case 5:
                cout << "Obrigado por usar o sistema\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
        system("pause");
    } while (opcao != 5);
    
    return 0;
}
