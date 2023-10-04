#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Gastos
{
    string tipoGasto;
    string categoriaDeGastos;
    double valor;
    int diaVencimento;
    int mesVencimento;
    int anoVencimento;
};

struct Usuario
{
    string cpf;
    string nome;
    string senha;
    double ganho;
};

bool arquivoContemDados()
{
    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        return false;
    }

    // Verifica se o arquivo possui algum conteúdo
    bool temDados = !arquivo.eof();

    arquivo.close();

    return temDados;
}

// void definirTetoDeGastos(double teto)
// {
//     tetoDeGastos = teto;
//     cout << "Teto de gastos definido para: R$" << tetoDeGastos << endl;
// }


void salvarGastosNoArquivo(Gastos gastos[], int quantidadeDeGastos)
{
    ofstream arquivo;
    arquivo.open("dados_financeiro.txt", ios ::app);

    if (!arquivo.is_open())
    {
        cout << "Arquivo não foi aberto corretamente." << endl;
        return;
    }

    for (int i = 0; i < quantidadeDeGastos; i++)
    {
        arquivo << "Categoria: " << gastos[i].tipoGasto << endl
                << "Valor: " << gastos[i].valor << endl
                << "Data de vencimento: " << gastos[i].diaVencimento << "-" << gastos[i].mesVencimento << "-" << gastos[i].anoVencimento << endl
                << endl;
    }

    arquivo.close();
}

void atualizarGastos(Gastos gastos[], int quantidadeDeGastos)
{

    int escolha;

    for (int i = 0; i < quantidadeDeGastos; i++)
    {
        cout << i << " - " << gastos[i].tipoGasto << endl;
    }
    
    cout << "Digite seu tipo de gasto que deseja alterar a partir do seu respectivo numero.";
    cin >> escolha;

    system("CLS");

    cout << "Qual o novo valor desse gasto? - Gasto atual: " << gastos[escolha].valor << endl;
    cin >> gastos[escolha].valor;

    cout << "Qual o nova dia de vencimento? - Dia atual: " << gastos[escolha].diaVencimento << endl;
    cin >> gastos[escolha].diaVencimento;

    cout << "Qual o novo mes de vencimento? - Mes atual: " << gastos[escolha].mesVencimento << endl;
    cin >> gastos[quantidadeDeGastos].mesVencimento;

    cout << "Qual o novo ano de vencimento? - Ano atual: " << gastos[escolha].anoVencimento << endl;
    cin >> gastos[quantidadeDeGastos].anoVencimento;

    salvarGastosNoArquivo(gastos, quantidadeDeGastos);

    system("CLS");
}

//***uso do return em função void
void salvarUsuarioNoArquivo(Usuario *usuario)
{
    ofstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    arquivo << usuario->cpf << endl
            << usuario->nome << endl
            << usuario->senha << endl
            << usuario->ganho << endl;

    arquivo.close();
}

//*** arquivo de acesso sequencial
void importarUsuarioDoArquivo(Usuario *usuario)
{

    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    string linha;

    getline(arquivo, linha);
    usuario->cpf = linha;

    getline(arquivo, linha);
    usuario->nome = linha;

    getline(arquivo, linha);
    usuario->senha = linha;

    getline(arquivo, linha);
    usuario->ganho = stod(linha);   // stod = string to double

    arquivo.close();
}

int cadastrarGastos(Gastos gastos[])
{
    char opcao;
    char escolha;
    int quantidadeDeGastos = 0;
    double tetoDeGastos = 0.0;

    do
    {
        cout << "Descreva qual sua categoria de gastos. (Exemplo: 'Alimentacao, Moradia, Energia, Agua...')" << endl;
        getline(cin, gastos[quantidadeDeGastos].tipoGasto);

        cout << "Qual o valor do gasto com essa categoria: " << endl;
        cin >> gastos[quantidadeDeGastos].valor;

        cout << "Deseja estipular um teto de gastos com essa categoria:  Digite S ou N"<<endl;
        cin >> escolha;

        // if(escolha == "S" || escolha == "s"){

        // }

        if (gastos[quantidadeDeGastos].valor > tetoDeGastos)
        {
            cout << "O valor do gasto excede o teto de gastos. Limite atual: R$" << tetoDeGastos << endl;
            continue;       // pular este gasto e continuar com o próximo
        }

        cout << "Digite a dia de vencimento: " << endl;
        cin >> gastos[quantidadeDeGastos].diaVencimento;

        cout << "Digite o mes de vencimento:" << endl;
        cin >> gastos[quantidadeDeGastos].mesVencimento;

        cout << "Digite ano de vencimento: " << endl;
        cin >> gastos[quantidadeDeGastos].anoVencimento;

        cout << "Deseja continuar cadastrando? (S / N) " << endl;
        cin >> opcao;
        cin.ignore();

        quantidadeDeGastos++;
        

        system("CLS");

    } while (opcao == 'S' || opcao == 's');

    salvarGastosNoArquivo(gastos, quantidadeDeGastos);

    return quantidadeDeGastos;
}

// função para criar um novo cadastro do usuário
void cadastrarUsuario(Usuario *usuario)
{
    cout << "Digite seu nome de usuario: " << endl;
    getline(cin, usuario->nome);

    cout << "Digite seu cpf: " << endl;
    getline(cin, usuario->cpf);

    cout << "Digite quanto voce ganha por mes: " << endl;
    cin >> usuario->ganho;

    cout <<"Digite sua senha de login: " <<endl;
    cin >> usuario->senha;
    cin.ignore();

    salvarUsuarioNoArquivo(usuario);
}

// função que atualiza o cadastro do usuario
void atualizarCadastro(Usuario *usuario)
{
    cout << "Atualizando dados do cadastro de " << usuario->nome << endl;

    cout << "Digite seu novo nome de usuario: "; // atualizar o novo nome do usuário
    getline(cin, usuario->nome);

    cout << "Digite seu novo cpf: "; // atualizar o cpf do usuário
    getline(cin, usuario->cpf);

    cout << "Digite sua nova senha: "; // atualizar a senha do usuário
    getline(cin, usuario->senha);

    cout << "Digite seu novo ganho por mes: "; // atualizar o novo ganho do usuário
    cin >> usuario->ganho;
    cin.ignore();

    salvarUsuarioNoArquivo(usuario);

    cout << "Cadastro atualizado com sucesso!" << endl;
}

void dadosUsuario(Usuario *usuario)
{
    cout << "Nome: " << usuario->nome << endl;
    cout << "Cpf: " << usuario->cpf << endl;
    cout << "Senha: " << usuario->senha << endl;
    cout << "Ganho: " << usuario->ganho << endl;
}

#endif
