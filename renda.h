#ifndef RENDA_H_INCLUDED
#define RENDA_H_INCLUDED

struct Renda
{
    string nome;
    double valor;
};

// Assinatura das funções
void solicitarRenda(Renda *renda);

Renda *criarRenda()
{
    Renda *novaRenda = new Renda;
    novaRenda->valor = 0.0;
    return novaRenda;
}

// Funcao main dessa biblioteca
void entradaDeRenda()
{
    gotoxy(60,16);
    cout << "Bem-vindo a sua CARTEIRINHA!" ;
    gotoxy(51,17);
    cout << "Primeiro passo - Vamos cadastrar sua renda..." << endl;

    char opcao;

    do
    {
        Renda *renda = criarRenda();

        solicitarRenda(renda);

        delete renda;
        
        gotoxy(57,27);
        cout << "Deseja adicionar outra renda? (S/N): ";
        gotoxy(57,28);
        cin >> opcao;

    } while (opcao == 'S' || opcao == 's');
}

void solicitarRenda(Renda *renda)
{
    ofstream arquivo("dados_renda.txt", ios::app);
    
    gotoxy(42,19);
    cout << "Informe de onde vem a renda: ";
    gotoxy(42,20);
    cin.ignore();
    getline(cin, renda->nome);

    gotoxy(42,22);
    cout << "Informe o valor da renda mensal de " << renda->nome << ": " ;
    gotoxy(42,23);
    cout << "R$ ";
    gotoxy(45,23);
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

    cout << "" << endl;
    cout << "Renda de " << renda->nome << " salva com sucesso!!!" << endl;
}

#endif
