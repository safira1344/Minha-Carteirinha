#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Usuario
{
    string nome;
    string cpf;
    string senha;
};

bool arquivoContemDados();
void salvarUsuario(Usuario *novoUsuario);
void importarUsuario(Usuario *novoUsuario);
bool verificarSenha(const string& senhaDigitada);


// Função main
void cadastrarUsuario(Usuario *novoUsuario)
{
    if (!arquivoContemDados()){
        cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" << endl;
        cout << "====================================================" << endl;

        cout << "Digite seu nome de usuario: " << endl;
        getline(cin, novoUsuario->nome);

        cout << "Digite seu cpf: " << endl;
        getline(cin, novoUsuario->cpf);

        cout <<"Digite sua senha de login: " <<endl;
        cin >> novoUsuario->senha;

        cin.ignore();

        salvarUsuario(novoUsuario);

        cout <<"Usuario cadastrado com sucesso" <<endl;
        cout << "====================================================" << endl << endl;

    }
    else {
        Usuario usuarioSalvo;
        importarUsuario(&usuarioSalvo);

        cout <<"Ola, " << usuarioSalvo.nome << "!" <<endl;
        cout << "====================================================" << endl;
        cout <<"Digite sua senha de login: " <<endl;
        string senhaDigitada;
        cin >> senhaDigitada;
        verificarSenha(senhaDigitada);

    }
}

//Função que mostra os dados do usuário
void dadosUsuario(Usuario *novoUsuario)
{
    cout << "Nome: " << novoUsuario->nome << endl;
    cout << "Cpf: " << novoUsuario->cpf << endl;
    cout << "Senha: " << novoUsuario->senha << endl;
}

//Função que verifica se existe usuário cadastrado
bool arquivoContemDados()
{
    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        return false;
    }

    bool temDados = !arquivo.eof();

    arquivo.close();

    return temDados;
}

//Função que salva os dados em um formato especifico
void salvarUsuario(Usuario *novoUsuario)
{
    ofstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    arquivo << novoUsuario->nome << endl
            << novoUsuario->cpf << endl
            << novoUsuario->senha << endl;

    arquivo.close();
}


//Função que importa os dados do arquivo para manipulação
void importarUsuario(Usuario *novoUsuario)
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
    novoUsuario->nome = linha;

    getline(arquivo, linha);
    novoUsuario->cpf = linha;

    getline(arquivo, linha);
    novoUsuario->senha = linha;

    arquivo.close();
}

//Função que verifica se as senhas são iguais
bool verificarSenha(const string& senhaDigitada)
{
    Usuario usuarioSalvo;
    importarUsuario(&usuarioSalvo);

    if (senhaDigitada == usuarioSalvo.senha)
    {
        cout << "Senha correta. Acesso permitido!" << endl;
        cout << "====================================================" << endl << endl;
        return true;
    }
    else
    {
        cout << "Senha incorreta. Acesso negado!" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        return false;
    }
}


#endif
