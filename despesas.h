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

    cout << "Segundo Passo" << endl;
    cout << "" << endl;
    cout << "Vamos cadastrar suas despesas, por categorias (Moradia, Cartoes, Agua, Energia..." << endl;

    const int maxDespesas = 100;
    Despesa **despesas = new Despesa *[maxDespesas]; // Vetor de ponteiros para Despesa

    char opcao;
    int numDespesas = 0;

    for (int numDespesas = 0; numDespesas < maxDespesas; numDespesas++)
    {
        despesas[numDespesas] = new Despesa;

        despesas[numDespesas]->mesCadastro = obterMesAtual();

        arquivo << "Mes de Cadastro: " << despesas[numDespesas]->mesCadastro << endl;

        cout << "" << endl;
        cout << "Digite a categoria da despesa: ";
        cin.ignore();
        getline(cin, despesas[numDespesas]->categoria);

        cout << "Digite o valor da despesa: R$ ";
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

        cout << "" << endl;
        cout << "Despesa registrada com sucesso!" << endl << endl;

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

    cout << "Deseja digitar o teto de gasto? (S/N): ";
    cin >> escolha;

    if (!(escolha == 'S' || escolha == 's'))
    {
        return 0.0;
    }

    cout << "Digite o teto de gasto (ou deixe em branco): R$ ";
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
    cout << "Deseja digitar a data de vencimento? (S/N): ";
    cin >> escolha;

    if (!(escolha == 'S' || escolha == 's'))
    {
        return "";
    }

    do
    {
        cout << "Digite uma data valida de vencimento da despesa (dd-mm-aaaa): ";
        cin >> data;
    } while (!validarData(data));

    return data;
}

#endif
