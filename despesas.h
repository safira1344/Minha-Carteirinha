#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

struct Despesa
{
    string categoria;
    double valor;
    string dataVencimento;
    double tetoDeGasto;
    string mesCadastro; // Esse int representa o mes em que a despesa foi cadastrada
};

// Assinatura das funções
string obterMesAtual();
bool validarData(const string &data);
double solicitarTeto();
string solicitarDataVencimento();
void entradaDeCategorias();

// Funcao main
void entradaDeCategorias()
{
    string diretorioDadosDespesas = "dados_financeiros.txt";
    ofstream arquivo(diretorioDadosDespesas, ios::app);

    gotoxy(34, 17);
    cout << "Segundo Passo - Vamos cadastrar suas despesas, por categorias (Moradia, Cartoes...)";

    const int maxDespesas = 100;
    Despesa **despesas = new Despesa *[maxDespesas]; // Vetor de ponteiros para Despesa

    char opcao;
    int numDespesas = 0;

    for (int numDespesas = 0; numDespesas < maxDespesas; numDespesas++)
    {
        despesas[numDespesas] = new Despesa;

        despesas[numDespesas]->mesCadastro = obterMesAtual();

        arquivo << "Mes de Cadastro: " << despesas[numDespesas]->mesCadastro << endl;

        gotoxy(42, 19);
        cout << "Digite a categoria da despesa: ";
        gotoxy(42, 20);
        cin.ignore();
        getline(cin, despesas[numDespesas]->categoria);

        gotoxy(42, 21);
        cout << "Digite o valor da despesa: R$ ";
        gotoxy(42, 22);
        cout << "R$ ";
        gotoxy(45, 22);
        cin >> despesas[numDespesas]->valor;

        despesas[numDespesas]->dataVencimento = solicitarDataVencimento();

        despesas[numDespesas]->tetoDeGasto = solicitarTeto();

        arquivo << "Categoria: " << despesas[numDespesas]->categoria << endl
                << "Valor: " << despesas[numDespesas]->valor << endl;

        if (!despesas[numDespesas]->dataVencimento.empty())
        {
            arquivo << "Data de Vencimento: " << despesas[numDespesas]->dataVencimento << endl;
        }

        if (despesas[numDespesas]->tetoDeGasto > 0.0)
        {
            arquivo << "Teto de Gasto: " << despesas[numDespesas]->tetoDeGasto << endl;
        }

        arquivo << endl;

        gotoxy(42, 28);
        cout << "Despesa registrada com sucesso!" << endl
             << endl;

        gotoxy(42, 29);
        cout << "Deseja adicionar outra despesa? (S/N): ";
        cin >> opcao;
        if (!(opcao == 'S' || opcao == 's'))
        {
            break; // Sai do loop
        }
    }

    arquivo.close();
}

// Funcao para obter o mes atual
string obterMesAtual()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[8];
    strftime(buffer, sizeof(buffer), "%m-%Y", ltm);

    return string(buffer);
}

// Funcao para validar a data no formato dd-mm-aaaa usando expressao regular (regex - regular expression)
bool validarData(const string &data)
{
    regex pattern("^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-20(23|\\d{2})$"); // Esse pattern valida datas de 01-01-2000 a 31-12-2099
    return regex_match(data, pattern);
}

// Funcao para limpar a struct
void limparDespesa(Despesa *pDespesa)
{
    pDespesa->categoria = "";
    pDespesa->valor = 0.0;
    pDespesa->dataVencimento = "";
    pDespesa->tetoDeGasto = 0.0;
    pDespesa->mesCadastro = "";
}

// Funcao para solicitar e validar o teto de gasto
double solicitarTeto()
{
    string tetoDeGasto;
    char escolha;

    gotoxy(42, 25);
    cout << "Deseja digitar o teto de gasto? (S/N): ";
    fflush(stdin);
    gotoxy(42, 26);
    cin >> escolha;

    if (!(escolha == 'S' || escolha == 's'))
    {
        return 0.0;
    }

    gotoxy(42, 26);
    cout << "Digite o teto de gasto (ou deixe em branco): ";
    gotoxy(42, 27);
    cout << "R$ ";
    gotoxy(45, 27);
    cin.ignore();
    getline(cin, tetoDeGasto);

    if (tetoDeGasto.empty()) // Se o usuario nao digitar nada
    {
        return 0.0;
    }

    return stod(tetoDeGasto);
}

// Funcao para solicitar e validar a data de vencimento
string solicitarDataVencimento()
{
    string data;

    char escolha;
    gotoxy(42, 23);
    cout << "Deseja digitar a data de vencimento? (S/N): ";
    gotoxy(42, 24);
    cin >> escolha;

    if (!(escolha == 'S' || escolha == 's'))
    {
        return "";
    }

    do
    {
        gotoxy(42, 24);
        cout << "                                                                 ";
        gotoxy(42, 23);
        cout << "Digite uma data válida de vencimento da despesa (dd-mm-aaaa): ";
        gotoxy(42, 24);
        cin >> data;
    } while (!validarData(data));

    return data;
}

#endif
