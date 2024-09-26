#include <fstream>

typedef struct
{
    string nome;
    string sigla;
    float valor;
} Cripto;

void split(string vetor[], string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1)
    {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

int conectarComBase(string nomeArquivo, Cripto lista[], int n)
{
    ifstream procuradorLeitura;
    int indice = 0;

    // abrir e associar o arquivo com seu procurador - formatado leitura
    procuradorLeitura.open(nomeArquivo);

    if (!procuradorLeitura)
        return indice;

    // percorrer o procurador
    string linha;
    while (!procuradorLeitura.eof() && indice < n)
    {
        // para cada linha percorrida do procurador, splitar por ;
        getline(procuradorLeitura, linha);
        if (linha != "")
        {

            // inserir na lista as partes splitadas (valor e data)
            string vetorLinha[3];
            split(vetorLinha, linha, ";");

            lista[indice].nome = vetorLinha[0];
            lista[indice].sigla = vetorLinha[1];
            lista[indice].valor = stof(vetorLinha[2]);

            indice++;
        }
    }

    // fechar
    procuradorLeitura.close();

    return indice;
}

void exibirLista(Cripto lista[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Cripto: " << lista[i].nome << " | Sigla: " << lista[i].sigla << " | Valor: " << lista[i].valor << endl;
    }
}

void gravarArquivo(string nomeArquivo, string nome, string sigla, float valor)
{
    ofstream procuradorEscrita;
    procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
    procuradorEscrita << nome << ";" << sigla << ";" << valor << endl;
    procuradorEscrita.close();
}

void atualizarArquivo(string nomeArquivo, Cripto lista[], int totalCadastrados)
{
    ofstream procuradorEscrita;
    procuradorEscrita.open(nomeArquivo);
    for (int i = 0; i < totalCadastrados; i++)
    {
        procuradorEscrita << lista[i].nome << ";" << lista[i].sigla << ";" << lista[i].valor << endl;
    }
    procuradorEscrita.close();
}

bool existeCripto(string nome, Cripto lista[], int totalCadastrados)
{
    for (int i = 0; i < totalCadastrados; i++)
    {
        if (lista[i].nome == nome)
        {
            return true;
        }
    }
    return false;
}

int cadastrarLista(Cripto lista[], int totalCadastrados)
{
    string nome;
    string sigla;
    float valor;

    cout << "Nome da Moeda: ";
    getline(cin, nome);
    if (existeCripto(nome, lista, totalCadastrados))
    {
        cout << "Erro! Criptomoeda ja cadastrada :(" << endl;
        return totalCadastrados;
    }

    cout << "Sigla: ";
    getline(cin, sigla);
    cout << "Valor da Moeda: ";
    cin >> valor;
    cin.ignore();
    cout << "Criptomoeda cadastrada com sucesso!" << endl;

    lista[totalCadastrados].nome = nome;
    lista[totalCadastrados].sigla = sigla;
    lista[totalCadastrados].valor = valor;
    totalCadastrados++;

    // persistir no arquivo
    gravarArquivo("criptos.csv", nome, sigla, valor);

    return totalCadastrados;
}

int removerCripto(Cripto lista[], int totalCadastrados, string nome)
{
    bool encontrado = false;
    for (int i = 0; i < totalCadastrados; i++)
    {
        if (lista[i].nome == nome)
        {
            for (int j = i; j < totalCadastrados; j++)
            {
                lista[j] = lista[j + 1];
            }
            totalCadastrados--;
            encontrado = true;
            break;
        }
    }
    if (encontrado)
    {
        atualizarArquivo("criptos.csv", lista, totalCadastrados);
        cout << "Criptomoeda " << nome << " removida com sucesso!" << endl;
    }
    else
    {
        cout << "Criptomoeda nao encontrada!" << endl;
    }
    return totalCadastrados;
}

int menu(Cripto lista[], int totalCadastrados, int n)
{
    int opcao;
    do
    {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Listar Criptomoedas\n";
        cout << "2 - Cadastrar Criptomoedas\n";
        cout << "3 - Remover Criptomoedas\n";
        cout << "4 - Sair\n";
        cout << "Insira a opcao: ";
        cin >> opcao;
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            if (totalCadastrados > 0)
            {
                cout << "Listar Criptomoedas: " << endl;
                exibirLista(lista, totalCadastrados);
            }
            else
            {
                cout << "Lista vazia!" << endl;
            }

            break;
        case 2:
            if (totalCadastrados < TAM)
            {
                cout << "Cadastrar Criptomoeda: " << endl;
                totalCadastrados = cadastrarLista(lista, totalCadastrados);
            }
            else
            {
                cout << "Lista cheia!" << endl;
            }
            break;
        case 3:
            if (totalCadastrados > 0)
            {
                cout << "Remover Criptomoeda: " << endl;
                cout << "Insira o nome da criptomoeda: " << endl;
                string nomeRemover;
                getline(cin, nomeRemover);
                totalCadastrados = removerCripto(lista, totalCadastrados, nomeRemover);
            }
            else
            {
                cout << "Lista vazia!" << endl;
            }
            break;
        case 4:
            cout << "Saindo da aplicacao!" << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
        system("pause");
    } while (opcao != 4);
    return totalCadastrados;
}