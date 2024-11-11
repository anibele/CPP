#include <string>
#include <fstream>
#include <cctype>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

// struct Inscricao
typedef struct
{
    string nome;
    string email;
    int matricula;
} Inscricao;

// struct Frequencia
typedef struct
{
    int matricula;
    string data;
    string hora;
} Frequencia;

// formatar para maiusculo
string paraMaiusculo(string frase)
{
    for (int i = 0; i < frase.length(); i++) // percorre a string
    {
        frase[i] = toupper(frase[i]); // converte para maiusculo
    }
    return frase;
}

// capturar data atual
class Data
{
public:
    // Metodo para obter somente a data atual
    string obterDataAtual()
    {
        // Obtem o tempo atual do sistema
        auto agora = chrono::system_clock::now();
        // Converte para o tipo de tempo C do sistema
        time_t tempo_agora = chrono::system_clock::to_time_t(agora);
        // Converte para a estrutura tm para manipulacao mais facil
        tm *data_atual = localtime(&tempo_agora);
        // Formata somente a data
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", data_atual);
        return string(buffer);
    }
};
Data data;
string dataAtual = data.obterDataAtual();

// capturar hora atual
class Hora
{
public:
    // Metodo para obter somente a hora atual
    string obterHoraAtual()
    {
        // Obtem o tempo atual do sistema
        auto agora = chrono::system_clock::now();
        // Converte para o tipo de tempo C do sistema
        time_t tempo_agora = chrono::system_clock::to_time_t(agora);
        // Converte para a estrutura tm para manipulacao mais facil
        tm *hora_atual = localtime(&tempo_agora);
        // Formata a hora
        char buffer[6];
        strftime(buffer, sizeof(buffer), "%H:%M", hora_atual);
        return string(buffer);
    }
};
Hora hora;
string horaAtual = hora.obterHoraAtual();

// split
void split(string vetor[], string str, string deli = " ")
{
    int start = 0;            // inicio da string
    int end = str.find(deli); // fim da string
    int i = 0;                // contador
    while (end != -1)         // enquanto nao chegar no fim da string
    {
        vetor[i] = str.substr(start, end - start); // pega a substring
        i++;                                       // incrementa o contador
        start = end + deli.size();                 // atualiza o inicio
        end = str.find(deli, start);               // atualiza o fim
    }
    vetor[i] = str.substr(start, end - start); // pega a ultima substring
}

// conectar com base
int conectarComBase(string nomeArquivo, Inscricao lista[], int n)
{
    ifstream procuradorLeitura; // objeto para leitura
    int indice = 0;             // contador

    // Verifica se o arquivo existe antes de abrir
    procuradorLeitura.open(nomeArquivo); // abre o arquivo
    if (!procuradorLeitura)              // se nao conseguir abrir
    {
        cout << "Arquivo não encontrado. Nenhuma inscrição carregada." << endl;
        return indice;
    }

    string linha;
    while (getline(procuradorLeitura, linha) && indice < n) // enquanto houver linhas
    {
        if (linha != "") // se a linha nao for vazia
        {
            string vetorLinha[3];                          // vetor para armazenar os dados
            split(vetorLinha, linha, ";");                 // separa os dados
            lista[indice].nome = vetorLinha[0];            // armazena o nome
            lista[indice].email = vetorLinha[1];           // armazena o email
            lista[indice].matricula = stoi(vetorLinha[2]); // armazena a matricula
            indice++;                                      // incrementa o contador
        }
    }
    procuradorLeitura.close(); // fecha o arquivo
    return indice;
}

// listar inscricoes
void listarInscricoes(Inscricao lista[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Inscricao: " << lista[i].nome << " | Email: " << lista[i].email << " | Matricula: " << lista[i].matricula << endl;
    }
}

// gravar arquivo
void gravarArquivo(string nomeArquivo, string nome, string email, int matricula)
{
    ofstream procuradorEscrita;                               // objeto para escrita
    procuradorEscrita.open(nomeArquivo, ios::out | ios::app); // abre o arquivo
    if (procuradorEscrita.is_open())                          // se conseguir abrir
    {
        procuradorEscrita << nome << ";" << email << ";" << matricula << endl; // escreve no arquivo
    }
    else
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl; // se nao conseguir abrir
    }
    procuradorEscrita.close(); // fecha o arquivo
}

// verificar se existe inscricao
bool existeInscricao(int matricula, Inscricao lista[], int totalInscritos)
{
    for (int i = 0; i < totalInscritos; i++) // percorre a lista
    {
        if (lista[i].matricula == matricula) // se a matricula existir
        {
            return true; // retorna verdadeiro
        }
    }
    return false; // senao, retorna falso
}

// cadastrar inscricao
int cadastrarInscricao(Inscricao lista[], int totalInscritos)
{
    string nome, email;
    int matricula;
    cout << "Nome Completo: ";
    getline(cin, nome);
    cout << "Email: ";
    getline(cin, email);
    cout << "Matricula: ";
    cin >> matricula;
    cin.ignore();

    if (existeInscricao(matricula, lista, totalInscritos))
    {
        cout << "Erro! Inscricao ja cadastrada :(" << endl;
        return totalInscritos;
    }

    cout << "Inscricao cadastrada com sucesso!" << endl;
    lista[totalInscritos].nome = paraMaiusculo(nome);
    lista[totalInscritos].email = email;
    lista[totalInscritos].matricula = matricula;
    totalInscritos++;

    gravarArquivo("inscricoes.csv", paraMaiusculo(nome), email, matricula); // grava no arquivo
    return totalInscritos;                                                  // retorna o total de inscritos
}

// registrar frequencia
int RegistrarFrequencia(Inscricao lista[], Frequencia frequencias[], int totalInscritos, int totalFrequencias)
{
    dataAtual = data.obterDataAtual();
    horaAtual = hora.obterHoraAtual();
    string dataa = dataAtual;
    string horaa = horaAtual;

    while (true)
    {
        int matricula;
        cout << "(Para encerrar digite -27) " << endl;
        cout << "Digite a matricula: ";
        cin >> matricula;
        if (matricula == -27) // se digitar -27
        {
            break;
        }

        bool encontrada = false; // inicializa a variavel
        for (int i = 0; i < totalInscritos; i++)
        {
            if (lista[i].matricula == matricula) // se a matricula existir
            {
                encontrada = true; // encontrada
                break;
            }
        }

        if (encontrada) // se encontrada
        {
            Frequencia presenca = {matricula, dataa = data.obterDataAtual(), horaa = hora.obterHoraAtual()}; // armazena a presenca
            frequencias[totalFrequencias] = presenca;                                                        // armazena no vetor
            totalFrequencias++;                                                                              // incrementa o contador

            ofstream file("frequencias.csv", ios::app); // abre o arquivo
            if (file.is_open())                         // se conseguir abrir
            {
                file << presenca.matricula << ";" << presenca.data << ";" << presenca.hora << "\n"; // escreve no arquivo
                file.close();                                                                       // fecha o arquivo
                cout << "A frequencia da matricula: " << matricula << " foi registrada com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao abrir o arquivo para registrar a frequencia." << endl;
            }
        }
        else
        {
            cout << "Erro! A matricula nao foi encontrada" << endl;
        }
    }

    return totalFrequencias;
}

// conectar com arquivo de frequencia
int conectarComFrequencias(string nomeArquivo, Frequencia frequencias[], int n)
{
    ifstream procuradorLeitura; // objeto para leitura
    int indice = 0;             // contador

    procuradorLeitura.open(nomeArquivo); // abre o arquivo
    if (!procuradorLeitura)              // se nao conseguir abrir
    {
        cout << "O Arquivo de frequencias nao encontrado!" << endl;
        return indice;
    }

    string linha;
    while (getline(procuradorLeitura, linha) && indice < n) // enquanto houver linhas
    {
        if (linha != "") // se a linha nao for vazia
        {
            string vetorLinha[3];                                // vetor para armazenar os dados
            split(vetorLinha, linha, ";");                       // separa os dados
            frequencias[indice].matricula = stoi(vetorLinha[0]); // armazena a matricula
            frequencias[indice].data = vetorLinha[1];            // armazena a data
            frequencias[indice].hora = vetorLinha[2];            // armazena a hora
            indice++;                                            // incrementa o contador
        }
    }
    procuradorLeitura.close(); // fecha o arquivo
    return indice;
}

// gerar relatorio de frequencia
void gerarRelatoriodeFrequencia(Frequencia frequencias[], Inscricao lista[], int nFrequencias, int nInscritos)
{
    // Estrutura para armazenar as frequencias por data
    string datas[TAM];  // Usando um vetor com tamanho maximo
    int totalDatas = 0; // Contador de datas
    // Para cada frequencia, verificamos se a data ja foi registrada
    for (int i = 0; i < nFrequencias; i++) // percorre as frequencias
    {
        bool novaData = true; // inicializa a variavel

        // Verifica se a data ja esta no vetor
        for (int j = 0; j < totalDatas; j++)
        {
            if (frequencias[i].data == datas[j]) // se a data existir
            {
                novaData = false; // Data ja existe
                break;
            }
        }

        // Se a data for nova, adicionamos ao vetor de datas
        if (novaData) // se for nova
        {
            datas[totalDatas++] = frequencias[i].data; // adiciona ao vetor
        }
    }
    cout << "--> Relatorio de frequencia <--\n";
    // Para cada data, imprimimos todas as frequencias registradas
    for (int i = 0; i < totalDatas; i++) // percorre as datas
    {
        cout << "---------- Dia " << datas[i] << " ------------\n";

        // Para cada frequencia, verificamos se pertence a esta data
        int contador = 1;                      // contador
        for (int j = 0; j < nFrequencias; j++) // percorre as frequencias
        {
            if (frequencias[j].data == datas[i]) // se a data existir
            {
                // Procura o nome do aluno pela matricula
                string nomeAluno = "Aluno nao encontrado!";
                for (int k = 0; k < nInscritos; k++) // percorre as inscricoes
                {
                    if (lista[k].matricula == frequencias[j].matricula) // se a matricula existir
                    {
                        nomeAluno = lista[k].nome; // armazena o nome
                        break;
                    }
                }

                // Exibe a matrícula, nome do aluno e hora de presença
                cout << contador << ". Matricula " << frequencias[j].matricula << "\n"; // exibe a matricula
                cout << nomeAluno << " - Hora: " << frequencias[j].hora << "\n";        // exibe o nome e a hora
                contador++;                                                             // incrementa o contador
            }
        }
    }

    cout << "--------------- Fim ----------------\n";
}

// menu
int menu(Inscricao lista[], Frequencia frequencias[], int totalInscritos, int totalFrequencias)
{
    int opcao;
    do
    {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Realizar Inscricao\n";
        cout << "2 - Listar Inscricoes\n";
        cout << "3 - Registrar Frequencia\n";
        cout << "4 - Gerar Relatorio de Presenca\n";
        cout << "5 - Sair\n";
        cout << "Insira a opcao: ";
        cin >> opcao;
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            if (totalInscritos < TAM)
            {
                cout << "Realizar Inscricao: " << endl;
                totalInscritos = cadastrarInscricao(lista, totalInscritos);
            }
            else
            {
                cout << "Erro: A lista ja esta cheia!" << endl;
            }
            break;
        case 2:
            if (totalInscritos > 0)
            {
                cout << "Listar Inscricoes: " << endl;
                listarInscricoes(lista, totalInscritos);
            }
            else
            {
                cout << "Erro: Nao ha inscricoes registradas!" << endl;
            }
            break;
        case 3:
            if (totalInscritos > 0)
            {
                cout << "--> Registrar frequencia <--" << endl;
                totalFrequencias = RegistrarFrequencia(lista, frequencias, totalInscritos, totalFrequencias);
            }
            else
            {
                cout << "Erro: a lista vazia!" << endl;
            }
            break;
        case 4:
            if (totalFrequencias > 0)
            {
                cout << "\n";
                gerarRelatoriodeFrequencia(frequencias, lista, totalFrequencias, totalInscritos);
            }
            else
            {
                cout << "Erro: Nao ha frequencias registradas!" << endl;
            }
            break;
        case 5:
            cout << "Saindo da aplicacao!" << endl;
            break;
        default:
            cout << "Erro: Opcao invalida!" << endl;
            break;
        }
        system("pause");
    } while (opcao != 5);

    return totalInscritos;
}