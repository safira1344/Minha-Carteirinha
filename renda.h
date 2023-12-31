#ifndef RENDA_H_INCLUDED
#define RENDA_H_INCLUDED

struct Renda
{
    string nome;
    double valor;
};

// Assinatura das funções
void solicitarRenda(Renda *renda);
double somarRenda(string &arquivoRenda, string &data);
void importarRenda(string &arquivoRenda, string &data);

Renda *criarRenda()
{
    Renda *novaRenda = new Renda;
    novaRenda->valor = 0.0;
    return novaRenda;
}

// Funcao main dessa biblioteca
void entradaDeRenda()
{
    char opcao;

    do
    {
        Renda *renda = criarRenda();

        solicitarRenda(renda);

        delete renda;

        gotoxy(57, 27);
        cout << "Deseja adicionar outra renda? (S/N): ";
        gotoxy(57, 28);
        cin >> opcao;

    } while (opcao == 'S' || opcao == 's');
}

void solicitarRenda(Renda *renda)
{
    ofstream arquivo("dados_renda.txt", ios::app);
    cabecalho();
    gotoxy(60, 16);
    cout << "Bem-vindo a sua CARTEIRINHA!";
    gotoxy(51, 17);
    cout << "Primeiro passo - Vamos cadastrar sua renda..." << endl;
    gotoxy(42, 19);
    cout << "Informe de onde vem a renda: ";
    gotoxy(42, 20);
    cin.ignore();
    getline(cin, renda->nome);

    gotoxy(42, 22);
    cout << "Informe o valor da renda mensal de " << renda->nome << ": ";
    gotoxy(42, 23);
    cout << "R$ ";
    gotoxy(45, 23);
    cin >> renda->valor;

    string mesCadastro = obterMesAtual();

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para salvamento" << endl;
        return;
    }

    arquivo << "Mes de Cadastro: " << mesCadastro << endl
            << "Nome: " << renda->nome << endl
            << "Valor: R$ " << renda->valor << endl
            << endl;

    arquivo.close();

    gotoxy(42,25);
    cout << "Renda de " << renda->nome << " salva com sucesso!!!" << endl;
}

// Função que soma todas as rendas de dentro do arquivo de renda
double somarRenda(string &arquivoRenda, string &data)
{
    ifstream arquivo(arquivoRenda);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de rendas." << endl;
    }

    double totalRendas = 0.0;
    string linha;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string nomeRenda;
            double valorRenda = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Nome: ") != string::npos)
                {
                    nomeRenda = linha.substr(linha.find("Nome: ") + 6);
                }
                else if (linha.find("Valor: R$ ") != string::npos)
                {
                    valorRenda = stod(linha.substr(linha.find("Valor: R$ ") + 9));
                }
            }

            totalRendas += valorRenda;
        }
    }

    arquivo.close();

    return totalRendas;
}

// Função que printa todas as rendas de dentro do arquivo de renda
void importarRenda(string &arquivoRenda, string &data)
{
    ifstream arquivo(arquivoRenda);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de rendas." << endl;
        return;
    }

    double totalRendas = 0.0;
    string linha;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string nomeRenda;
            double valorRenda = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Nome: ") != string::npos)
                {
                    nomeRenda = linha.substr(linha.find("Nome: ") + 6);
                }
                else if (linha.find("Valor: R$ ") != string::npos)
                {
                    valorRenda = stod(linha.substr(linha.find("Valor: R$ ") + 9));
                }
            }

            totalRendas += valorRenda;

            cout << nomeRenda << ": R$ " << valorRenda << endl;
        }
    }

    arquivo.close();
}
#endif
