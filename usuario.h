#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#define MAX_USUARIOS 1000

#include <iostream>
#include <stdio.h>

using namespace std;

struct Usuario
{
    int id;
    string cpf;
    string nome;
    string senha;
    bool ativo;
};

// // função para verificar se um cliente com o mesmo ID já existe
// bool usuarioExiste(const Usuario *usuarios, int quantUsuarios, int id)
// {
//     for (int i = 0; i < quantUsuarios; ++i)
//     {
//         if (usuarios[i].id == id)
//         {
//             return true; // se cliente com o mesmo ID já existe
//         }
//     }
//     return false; // nenhum cliente com o mesmo ID foi encontrado
// }

bool cpfExiste(Usuario *usuarios[], int quantUsuarios, string cpf)
{
    for (int i = 0; i < quantUsuarios; ++i)
    {
        if (usuarios[i]->cpf == cpf)
        {
            return true; // se cliente com o mesmo cpf já existe
        }
    }
    return false; // nenhum cliente com o mesmo cpf foi encontrado
}

// função para criar um novo cadastro do usuário
bool criarUsuario(Usuario *usuarios[], int &quantUsuarios)
{
    Usuario *novoUsuario = new Usuario; // criando um ponteiro novoUsuario do tipo Usuario
    novoUsuario->id = quantUsuarios;    //(*novoUsuario).id == novoUsuario->id
    cout << "Digite seu nome de usuario: " << endl;
    getline(cin, novoUsuario->nome);
    bool cpfValido;
    do
    {
        cout << "Digite seu cpf: " << endl;
        getline(cin, novoUsuario->cpf);
        cpfValido = !cpfExiste(usuarios, quantUsuarios, novoUsuario->cpf);
        if (cpfValido == false)
        {
            cout << "CPF já cadastrado" << endl;
        }
    } while (cpfValido == false);
    cout << "Digite sua senha: " << endl;
    getline(cin, novoUsuario->senha);
    novoUsuario->ativo = true;

    usuarios[quantUsuarios] = novoUsuario;

    quantUsuarios++;

    cout << "Cadastro criado com sucesso!" << endl;
    return true;
}

void mostrarUsuarios(Usuario *usuarios[], int &quantUsuarios)
{
    for (int i = 0; i < quantUsuarios; i++)
    {
        cout << usuarios[i]->id << endl;
        cout << usuarios[i]->nome << endl;
        cout << usuarios[i]->cpf << endl;
        cout << usuarios[i]->senha << endl;
        cout << usuarios[i]->ativo << endl
             << endl;
    }
}

#endif
