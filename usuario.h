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

// Assinatura das funções
bool existeUsuarioCadastrado();
void logarUsuario(Usuario *usuario);
void cadastrarUsuario(Usuario *novoUsuario);
void dadosUsuario(Usuario *novoUsuario);
bool arquivoContemDados();
void salvarUsuario(Usuario *novoUsuario);
Usuario importarUsuario();
bool verificarSenha(const string &senhaDigitada);


// Função que verifica se existe usuário cadastrado
bool existeUsuarioCadastrado()
{
    return arquivoContemDados();
}

// Função que loga o usuário
void logarUsuario(Usuario *usuario)
{
    Usuario usuarioSalvo = importarUsuario();

    cout << "Ola, " << usuarioSalvo.nome << "!" << endl;
    cout << "====================================================" << endl;

    int tentativas = 0;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        cout << "Digite sua senha de login: " << endl;
        getline(cin, senhaDigitada);

        if (verificarSenha(senhaDigitada)) // Se a senha estiver correta o usuário é logado
        {
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            cout << "Senha incorreta!" << endl;
            cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
        }

        if (++tentativas == 3) // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
        {
            cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
            cout << "Contate o administrador do sistema." << endl;

            cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
            cin >> opcao;

            if (opcao == 'S' || opcao == 's')
            {
                cadastrarUsuario(usuario);
            }
            else
            {
                cout << "Obrigado por usar o sistema!" << endl;
                exit(0);
            }
        }
    }

    cout << "Ola, " << usuarioSalvo.nome << "!" << endl;
}

// Função que cadastra o usuário
void cadastrarUsuario(Usuario *novoUsuario)
{
    cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" << endl;
    cout << "====================================================" << endl;

    cout << "Digite seu nome de usuario: " << endl;
    getline(cin, novoUsuario->nome);

    cout << "Digite seu cpf: " << endl;
    getline(cin, novoUsuario->cpf);

    cout << "Digite sua senha de login: " << endl;
    getline(cin, novoUsuario->senha);

    salvarUsuario(novoUsuario);

    cout << "Usuario cadastrado com sucesso" << endl;
    cout << "====================================================" << endl
         << endl;
}

// Função que mostra os dados do usuário
void dadosUsuario(Usuario *novoUsuario)
{
    cout << "Nome: " << novoUsuario->nome << endl;
    cout << "Cpf: " << novoUsuario->cpf << endl;
    cout << "Senha: " << novoUsuario->senha << endl;
}

// Função que verifica se existe usuário cadastrado
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

// Função que salva os dados do usuario no arquivo
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

// Função que importa os dados do usuario no arquivo
Usuario importarUsuario()
{
    Usuario novoUsuario;
    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return novoUsuario; // Retornando um usuario vazio
    }

    string linha;

    getline(arquivo, linha);
    novoUsuario.nome = linha;

    getline(arquivo, linha);
    novoUsuario.cpf = linha;

    getline(arquivo, linha);
    novoUsuario.senha = linha;

    arquivo.close();

    return novoUsuario;
}

// Função que verifica se as senhas são iguais
bool verificarSenha(const string &senhaDigitada)
{
    Usuario usuarioSalvo = importarUsuario();

    return (senhaDigitada == usuarioSalvo.senha);
}

#endif // USUARIO_H_INCLUDED
