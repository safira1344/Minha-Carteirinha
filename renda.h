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
void entradaDeRenda() {
    cout << "Bem-vindo a sua CARTEIRINHA!" << endl << endl;

    cout << "Primeiro passo - Vamos cadastrar sua renda..." << endl;

    char opcao;

    do
    {
        Renda *renda = criarRenda();

        solicitarRenda(renda);

        delete renda;

        cout << "Deseja adicionar outra renda? (S/N): ";
        cin >> opcao;

    } while (opcao == 'S' || opcao == 's');
}

void solicitarRenda(Renda *renda) {
    ofstream arquivo("dados_renda.txt", ios::app);

    cin.ignore();
    cout << "" <<endl;
    cout << "Informe de onde vem a renda: ";
    getline(cin, renda->nome);

    cout << "Insira o valor da renda mensal de " << renda->nome << ": R$ ";
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
