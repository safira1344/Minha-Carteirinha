#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

struct Despesa
{
    string categoria;
    double valor;
    string dataVencimento;
    string mesCadastro; // Esse int representa o mes em que a despesa foi cadastrada
};

struct GastoDiario
{
    string descricao;
    double valor;
};

// Assinatura das funções
string obterMesAtual();
bool validarData(const string &data);
string solicitarDataVencimento();
void entradaDeCategorias();
double extrairDespesas(string &arquivoDespesa, string &data);
int tetoDeGastos();

// Funcao main
void entradaDeCategorias()
{
    string diretorioDadosDespesas = "dados_financeiros.txt";
    ofstream arquivo(diretorioDadosDespesas, ios::app);

    retangulos(WHITE, 40, 15 , 14, 79);

    const int maxDespesas = 100;
    Despesa **despesas = new Despesa *[maxDespesas]; // Vetor de ponteiros para Despesa

    char opcao;
    int numDespesas = 0;

    for (int numDespesas = 0; numDespesas < maxDespesas; numDespesas++){

        despesas[numDespesas] = new Despesa;

        despesas[numDespesas]->mesCadastro = obterMesAtual();

        arquivo << "Mes de Cadastro: " << despesas[numDespesas]->mesCadastro << endl;

        gotoxy(40, 17);
        cout << "Segundo Passo - Cadastre suas despesas fixas (Moradia, Energia...)";

        gotoxy(42, 19);
        cout << "Digite a categoria da despesa: ";
        gotoxy(42, 20);
        cin.ignore();
        getline(cin, despesas[numDespesas]->categoria);

        gotoxy(42, 21);
        cout << "Digite o valor da despesa:";
        gotoxy(42, 22);
        cout << "R$ ";
        gotoxy(45, 22);
        cin >> despesas[numDespesas]->valor;

        despesas[numDespesas]->dataVencimento = solicitarDataVencimento();

        arquivo << "Categoria: " << despesas[numDespesas]->categoria << endl
                << "Valor: " << despesas[numDespesas]->valor << endl;

        if (!despesas[numDespesas]->dataVencimento.empty())
        {
            arquivo << "Data de Vencimento: " << despesas[numDespesas]->dataVencimento << endl;
        }

        arquivo << endl;

        gotoxy(42, 27);
        cout << "Despesa registrada com sucesso!" << endl
             << endl;

        gotoxy(42, 29);
        cout << "Deseja adicionar outra despesa fixa? (S/N): ";
        cin >> opcao;
        retangulos(WHITE, 40, 15 , 14, 79);
        if (!(opcao == 'S' || opcao == 's'))
        {
            break;
        }
    }

    arquivo.close();
    tetoDeGastos();
}

// Função que salva o teto de gastos
int tetoDeGastos()
{
    double *limiteGastos = new double;

    telinha();
    cabecalho();
    gotoxy(42,17);
    cout << "Terceiro Passo - Cadastre um teto de gasto para suas despesas variaveis" ;
    gotoxy(42,19);
    cout << "Para que o programa possa lhe ajudar e ser eficiente";
    gotoxy(42,20);
    cout << "insira todos os dias seus gastos diario na sua carteirinha" ;
    gotoxy(42,22);
    cout << "Digite o limite de gastos para o mes: ";
    gotoxy(42,23);
    cin >> *limiteGastos;

    ofstream arquivoDeTeto("teto_de_gastos.txt");

    if (!arquivoDeTeto.is_open())
    {
        cout << "Erro ao abrir o arquivo teto_de_gastos.txt" << endl;
        delete limiteGastos;
        return 1;
    }

    arquivoDeTeto << limiteGastos;

    arquivoDeTeto.close();

    gotoxy(42,26);
    cout << "Teto de gastos salvo com sucesso!" << endl;

    delete limiteGastos;
    return 0;
}

// Função para adicionar gastos diarios
void desepesaDiaria()
{
    ifstream arquivoTeto("teto_de_gastos.txt");

    moldurinha(0, 155, 0, 39, MAGENTA, WHITE);

    moldurinha(30, 120, 8, 30, WHITE, BLACK);

    if (!arquivoTeto)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    double tetoDeGastos;
    arquivoTeto >> tetoDeGastos;

    arquivoTeto.close();

    fstream despesasArquivo("despesas_variaveis.txt", ios::in | ios::out | ios::app);

    if (!despesasArquivo)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    char continuar;

    do
    {
        GastoDiario *gastoDiario = new GastoDiario;

        gotoxy(42,10);
        cout << "Digite a descrição do gasto: ";
        gotoxy(42,11);
        cin.ignore();
        getline(cin, gastoDiario->descricao);

        gotoxy(42,12);
        cout << "Digite o valor do gasto: ";
        gotoxy(42,13);
        cin >> gastoDiario->valor;

        despesasArquivo << gastoDiario->descricao << endl;
        despesasArquivo << ": " << gastoDiario->valor << endl;

        delete gastoDiario;

        gotoxy(42,14);
        cout << "Deseja adicionar mais gastos? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    double totalGastos = 0.0;
    double valor;
    while (despesasArquivo >> valor)
    {
        totalGastos += valor;
    }

    despesasArquivo.close();

    // Calcular o valor restante até o teto de gastos
    double gastosRestantes = tetoDeGastos - totalGastos;

    gotoxy(42,16);
    cout << "Soma de todos os gastos: " << totalGastos << endl;
    gotoxy(42,17);
    cout << "Restante para atingir o limite de gastos: " << gastosRestantes ;

    gotoxy(42,19);
    cout << "A responsabilidade financeira é uma qualidade fundamental ";
    gotoxy(42,20);
    cout<<"para uma vida financeira saudável!";
}

void imprimirDespesasDiarias()
{

    ifstream despesasArquivo("despesas_variaveis.txt");
    int l = 10;

    telinha();

    if (!despesasArquivo)
    {
        cerr << "Erro ao abrir o arquivo 'despesas_variaveis.txt'" << endl;
        return;
    }

    string linha;
    cout << "Despesas Variáveis:" << endl;
    while (getline(despesasArquivo, linha))
    {
        if(l == 26)
        {
            confirmar(42,27);
        }
        else
        {
            gotoxy(42,l);
            cout << linha ;
            l++;
        }
    }

    despesasArquivo.close();
}

// Função para adicionar despesas variáveis a o arquivo financeiro
void salvarGastosVar()
{
    telinha();
    string data;
    gotoxy(42,10);
    cout << "A que mes esses gastos são referenetes (mm-aaaa): ";
    gotoxy(42,11);
    getline(cin, data);

    ifstream arquivoDespesas("despesas_variaveis.txt");
    ofstream arquivoFinanceiro("dados_financeiros.txt", ios::app);

    if (!arquivoDespesas || !arquivoFinanceiro)
    {
        cout << "Erro ao abrir um dos arquivos." << endl;
        return;
    }

    arquivoFinanceiro << "Data: " << data << endl;
    arquivoFinanceiro << "Despesas Variáveis:" << endl;

    string linha;
    while (getline(arquivoDespesas, linha))
    {
        arquivoFinanceiro << linha << endl;
    }

    arquivoDespesas.close();
    arquivoFinanceiro.close();

    gotoxy(42,13);
    cout << "Despesas variáveis salvas com sucesso!!" ;
    gotoxy(42,14);
    cout << "Para acessa-las, vá na opção RELATORIO no menu principal." ;
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
    pDespesa->mesCadastro = "";
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
        cout << "Digite uma data valida de vencimento da despesa (dd-mm-aaaa): ";
        gotoxy(42, 24);
        cin >> data;
    } while (!validarData(data));

    return data;
}

// Função que importa o nome e valor das despesas, e faz a soma delas
double extrairDespesas(string &arquivoDespesa, string &data)
{
    ifstream arquivo(arquivoDespesa);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de despesas." << endl;
        return 0.0;
    }

    double totalDespesasMes = 0.0;
    string linha;

    cout << "DESPESAS" << endl;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string categoriaDespesa;
            double valorDespesa = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Categoria: ") != string::npos)
                {
                    categoriaDespesa = linha.substr(linha.find("Categoria: ") + 11);
                }
                else if (linha.find("Valor: ") != string::npos)
                {
                    valorDespesa = stod(linha.substr(linha.find("Valor: ") + 7));
                }
            }

            cout << "- Despesa: " << categoriaDespesa << " - " << valorDespesa << endl;
            totalDespesasMes += valorDespesa;
        }
    }

    arquivo.close();

    return totalDespesasMes;
}

#endif

