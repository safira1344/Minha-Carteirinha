#ifndef COFRINHO_H_INCLUDED
#define COFRINHO_H_INCLUDED

// Assinatura das funções
double extrairCofrinho(string &arquivoCofre, string &data);
double calcularEmprestimo(double valorEmprestado, double taxaJuros, int meses);
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
    menuPrincipal();
}

// Função que importa o nome e valor dos cofres, e faz a soma deles
double extrairCofrinho(string &arquivoCofre, string &data)
{
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
void preverTempo() {
    double valorAlvo = 0;
    double economiaMensal = 0;

    telinha();

    gotoxy(42, 10);
    cout << "Informe o valor alvo que deseja alcançar:";
    gotoxy(42, 11);
    cout << "R$ ";

    // Verifica a entrada para valorAlvo
    while (!(cin >> valorAlvo) || valorAlvo <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(42, 14);
        cout << "Informe um valor alvo válido maior que zero." << endl;
        gotoxy(42, 11);
        cout << "R$ ";
    }

    gotoxy(42, 12);
    cout << "Informe a economia mensal que deseja fazer:";
    gotoxy(42, 13);
    cout << "R$ ";

    // Limpa o buffer de entrada antes de ler economiaMensal pois antes estava entrando em loop
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Verifica a entrada para economiaMensal
    while (!(cin >> economiaMensal) || economiaMensal <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(42, 14);
        cout << "Informe uma economia mensal válida maior que zero." << endl;
        gotoxy(42, 13);
        cout << "R$ ";
    }

    double saldoAtual = 0;
    int meses = 0;

    while (saldoAtual < valorAlvo) {
        saldoAtual += economiaMensal;
        meses++;
    }

    gotoxy(42, 15);
    cout << "Com uma economia de R$ " << economiaMensal << " por mês, levará aproximadamente " << meses;
    gotoxy(42, 16);
    cout << " meses para alcançar o valor alvo de R$ " << valorAlvo << ".";

    menuPrincipal();
}

// Função q calcula os ganhos ao final de um empréstimo com juros mensais crescentes
double calcularEmprestimo(double valorEmprestado, double taxaJuros, int meses)
{
    double resultado;
    double saldoMesAnterior;

    telinha();

    if (valorEmprestado <= 0 || taxaJuros <= 0 || meses <= 0)
    {
        gotoxy(42, 10);
        cout << "Informe valores validos maiores que zero." << endl;
        return 0.0;
    }

    if (meses == 1)
    {
        resultado = valorEmprestado + valorEmprestado * taxaJuros;
    }
    else
    {
        resultado = calcularEmprestimo(valorEmprestado, taxaJuros, meses - 1);
        resultado += resultado * taxaJuros;
    }


            gotoxy(42, 14);
            cout << "O saldo ao final do emprestimo e: R$ " << resultado << endl;

            double juros = resultado - valorEmprestado;

            gotoxy(42, 15);
            cout << "Total de juros pagos: R$ " << juros << endl;
}

#endif
