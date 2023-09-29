#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <stdio.h>

using namespace std;

struct Gastos
{
    double gastoAgua;
    double gastoEnergia;
    double gastoMoradia;
    double gastoAlimentacao;
    double gastoLazer;
};
struct Carteira
{
    double ganho;
    Gastos gastos;
    int diaVencimento;
};
struct Usuario
{
    string cpf;
    string nome;
    string senha;
    Carteira carteira;
};

// função para criar um novo cadastro do usuário
void cadastrarUsuario(Usuario *usuario)
{
    cout << "Digite seu nome de usuario: " << endl;
    getline(cin, usuario->nome);

    cout << "Digite seu cpf: " << endl;
    getline(cin, usuario->cpf);

    cout << "Digite sua senha: " << endl;
    getline(cin, usuario->senha);

    Carteira carteira;

    cout << "Digite quanto voce ganha por mes: " << endl;
    cin >> carteira.ganho;
    cin.ignore();

    usuario->carteira = carteira;

    cout << "Cadastro criado com sucesso!" << endl;
}


// #TO DO
//atualizar cadastro;

//cadsastrar gastos;

void dadosUsuario(Usuario *usuario)
{
    cout << "Nome: " << usuario->nome << endl;
    cout << "Cpf: " << usuario->cpf << endl;
    cout << "Senha: " << usuario->senha << endl;
    cout << "Ganho: " << usuario->carteira.ganho << endl;
}

#endif