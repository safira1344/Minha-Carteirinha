#ifndef COFRINHO_H_INCLUDED
#define COFRINHO_H_INCLUDED

// Assinatura das funções
double extrairCofrinho(string &arquivoCofre, string &data);
double calcularEmprestimo();
void preverTempo();

// Funcao main dessa biblioteca
void guardarDinheiro()
{
    retangulos(WHITE, 32, 17, 13, 88);
    gotoxy(67, 17);
    cout << "E pra finalizar..." << endl
         << endl;
    gotoxy(58, 18);

    cout << "Deseja guardar dinheiro? (S/N): ";
    char opcao;
    cin >> opcao;

    while (opcao == 'S' || opcao == 's')
    {
        retangulos(WHITE, 32, 17, 13, 88);
        string nomeCofrinho;
        gotoxy(42, 19);
        cout << "Informe o nome do cofrinho: ";
        gotoxy(42, 20);
        cin >> nomeCofrinho;
        gotoxy(42, 19);
        cout << "Informe o nome do cofrinho: ";
        gotoxy(42, 20);
        cin >> nomeCofrinho;

        double quantidadeDinheiro;

        gotoxy(42, 22);
        cout << "Informe a quantidade de dinheiro que deseja guardar:";
        gotoxy(42, 23);
        cout << "R$ ";
        gotoxy(45, 23);
        cin >> quantidadeDinheiro;

        ofstream arquivo("dados_cofre.txt", ios::app);

        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir o arquivo, desculpe" << endl;
            return;
        }

        arquivo << "Nome: " << nomeCofrinho << endl
                << "Valor: " << quantidadeDinheiro << endl;

        arquivo.close();
        gotoxy(42, 26);
        cout << "Os dados foram salvos com sucesso!!!" << endl;

        gotoxy(42, 27);
        cout << "Deseja guardar mais dinheiro? (S/N): ";
        cin >> opcao;
    }
}


// Função que importa o nome e valor dos cofres, e faz a soma deles
double extrairCofrinho(string &arquivoCofre, string &data){
    double valorCofre;

    ifstream arquivo(arquivoCofre);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo do cofre." << endl;
        return 0.0;
    }

    double totalGuardado = 0.0;
    string linha;

    cout << "DINHEIRO GUARDADO" << endl;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string nomeCofre;
            valorCofre = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Nome: ") != string::npos)
                {
                    nomeCofre = linha.substr(linha.find("Nome: ") + 6);
                }
                else if (linha.find("Valor: ") != string::npos)
                {
                    valorCofre = stod(linha.substr(linha.find("Valor: ") + 7));
                }
            }

            cout << "- Cofre: " << nomeCofre << " - " << valorCofre << endl;
            totalGuardado += valorCofre;
        }
    }

    arquivo.close();

    return valorCofre;
}

// Função  para prever em quanto tempo o usuário terá uma certa quantidade de dinheiro
void preverTempo()
{
    double valorAlvo;
    double economiaMensal;

    cout << "Informe o valor alvo que deseja alcançar: R$ ";
    cin >> valorAlvo;

    cout << "Informe a economia mensal que deseja fazer: R$ ";
    cin >> economiaMensal;

    if (valorAlvo <= 0 || economiaMensal <= 0)
    {
        cout << "Informe um valor alvo e uma economia mensal válidos maiores que zero." << endl;
        return;
    }

    double saldoAtual = 0;
    int meses = 0;

    while (saldoAtual < valorAlvo)
    {
        saldoAtual += economiaMensal;
        meses++;
    }

    cout << "Com uma economia de R$ " << economiaMensal << " por mês, levará aproximadamente " << meses << " meses para alcançar o valor alvo de R$ " << valorAlvo << "." << endl;
}

// Função q calcula os ganhos ao final de um empréstimo com juros mensais crescentes
double calcularEmprestimo()
{
    double valorEmprestado;
    double taxaJuros;
    int meses;

    cout << "Informe o valor que deseja emprestar: R$ ";
    cin >> valorEmprestado;

    cout << "Informe a taxa de juros mensal (em decimal): ";
    cin >> taxaJuros;

    if (valorEmprestado <= 0 || taxaJuros <= 0)
    {
        cout << "Informe um valor de empréstimo e uma taxa de juros válidos maiores que zero." << endl;
        return 0.0;
    }

    cout << "Informe o número de meses para o empréstimo: ";
    cin >> meses;

    if (meses <= 0)
    {
        cout << "Informe um número de meses válido maior que zero." << endl;
        return 0.0;
    }

    if (meses == 1)
    {
        return valorEmprestado * (1 + taxaJuros);
    }
    else
    {
        double saldoMesAnterior = calcularEmprestimo();
        return saldoMesAnterior * (1 + taxaJuros);
    }
}

#endif
