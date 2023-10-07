#ifndef COFRINHO_H_INCLUDED
#define COFRINHO_H_INCLUDED

// Assinatura das funções
double calcularEmprestimo();
void preverTempo();

// Funcao main dessa biblioteca
void guardarDinheiro()
{
    cout << "E pra finalizar..." << endl << endl;

    char opcao;
    cout << "Deseja guardar dinheiro? (S/N): ";
    cin >> opcao;

    while (opcao == 'S' || opcao == 's')
    {
        string nomeCofrinho;
        cout << "Informe o nome do cofrinho: ";
        cin.ignore();
        getline(cin, nomeCofrinho);

        double quantidadeDinheiro;
        cout << "Por favor, insira a quantidade de dinheiro que deseja guardar: R$ ";
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

        cout << "Os dados foram salvos com sucesso!!!" << endl;

        cout << "Deseja guardar mais dinheiro? (S/N): ";
        cin >> opcao;
    }
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
