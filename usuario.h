#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

using namespace std;

struct Usuario
{
    string nome;
    string cpf;
    string senha;
};

// Assinatura das funções
void apagarCadastro();
void importarUsuario(Usuario *novoUsuario);
bool existeUsuarioCadastrado();
void logarUsuario(Usuario *usuario);
void cadastrarUsuario(Usuario *novoUsuario);
void dadosUsuario(Usuario *novoUsuario);
bool arquivoContemDados();
void salvarUsuario(Usuario *novoUsuario);
Usuario importarUsuario();
bool verificarSenha(const string &senhaDigitada,Usuario *dados);

// Função que verifica se existe usuário cadastrado
bool existeUsuarioCadastrado()
{
    return arquivoContemDados();
}

// Função que loga o usuário
void logarUsuario(Usuario *usuario)
{
    importarUsuario(usuario);

    cout << "Ola, " << usuario->nome << "!" << endl;
    cout << "====================================================" << endl;

    int tentativas = 1;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        cout << "Digite sua senha de login: " << endl;
        getline(cin, senhaDigitada);

        tentativas++;

        if (verificarSenha(senhaDigitada, usuario)) // Se a senha estiver correta o usuário é logado
        {
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            if (tentativas > 3) // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
            {
                cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
                cout << "Contate o administrador do sistema." << endl;

                cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
                cin >> opcao;

            if (opcao == 'S' || opcao == 's')
            {
                apagarCadastro();
                cadastrarUsuario(usuario);
            }
            else
            {
                apagarCadastro();
                cout << "Obrigado por usar o sistema!" << endl;
                exit(0);
            }
            }
            else
            {
                cout << "Senha incorreta!" << endl;
                cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
            }
        }

    }

    cout << "Ola, " << usuario->nome << "!" << endl;
}

void apagarCadastro()//Para apagar os arquivos com dados dos usuários
{
    string usuario = "dados_usuario.txt";
    string renda = "dados_renda.txt";
    string financeiro = "dados_financeiros.txt";
    string cofrinho = "dados_cofre.txt";

    if (remove(usuario.c_str())==0 && remove(renda.c_str())==0 && remove(financeiro.c_str())==0 && remove(cofrinho.c_str())==0)
    {
        cout << "Arquivos apagados com sucesso!";
    }
}

// Função que cadastra o usuário
void cadastrarUsuario(Usuario *novoUsuario)
{
    if(!arquivoContemDados())
    {
        cabecalho();
        gotoxy(50,16);
        cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" ;
        gotoxy(50,17);
        cout << "====================================================";

        gotoxy(42,19);
        cout << "Digite seu nome de usuario: ";
        gotoxy(42,20);
        getline(cin, novoUsuario->nome);

        gotoxy(42,22);
        cout << "Digite seu cpf: " ;
        gotoxy(42,23);
        getline(cin, novoUsuario->cpf);

        gotoxy(42,25);
        cout << "Digite sua senha de login: " ;
        gotoxy(42,26);
        getline(cin, novoUsuario->senha);

        salvarUsuario(novoUsuario);

        gotoxy(61,28);
        cout << "Usuario cadastrado com sucesso" ;
        gotoxy(50,29);
        cout << "====================================================";

    }
    else
    {
        importarUsuario(novoUsuario);
        logarUsuario(novoUsuario);
    }
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
void importarUsuario(Usuario *novoUsuario)
{
    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
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

// Função que verifica se as senhas são iguais
bool verificarSenha(const string &senhaDigitada,Usuario *dados)
{
     importarUsuario(dados);

    return (senhaDigitada == dados->senha);
}

#endif // USUARIO_H_INCLUDED
#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

using namespace std;

struct Usuario
{
    string nome;
    string cpf;
    string senha;
};

// Assinatura das funções
void apagarCadastro();
void importarUsuario(Usuario *novoUsuario);
bool existeUsuarioCadastrado();
void logarUsuario(Usuario *usuario);
void cadastrarUsuario(Usuario *novoUsuario);
void dadosUsuario(Usuario *novoUsuario);
bool arquivoContemDados();
void salvarUsuario(Usuario *novoUsuario);
Usuario importarUsuario();
bool verificarSenha(const string &senhaDigitada,Usuario *dados);

// Função que verifica se existe usuário cadastrado
bool existeUsuarioCadastrado()
{
    return arquivoContemDados();
}

// Função que loga o usuário
void logarUsuario(Usuario *usuario)
{
    importarUsuario(usuario);

    cout << "Ola, " << usuario->nome << "!" << endl;
    cout << "====================================================" << endl;

    int tentativas = 1;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        cout << "Digite sua senha de login: " << endl;
        getline(cin, senhaDigitada);

        tentativas++;

        if (verificarSenha(senhaDigitada, usuario)) // Se a senha estiver correta o usuário é logado
        {
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            if (tentativas > 3) // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
            {
                cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
                cout << "Contate o administrador do sistema." << endl;

                cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
                cin >> opcao;

            if (opcao == 'S' || opcao == 's')
            {
                apagarCadastro();
                cadastrarUsuario(usuario);
            }
            else
            {
                apagarCadastro();
                cout << "Obrigado por usar o sistema!" << endl;
                exit(0);
            }
            }
            else
            {
                cout << "Senha incorreta!" << endl;
                cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
            }
        }

    }

    cout << "Ola, " << usuario->nome << "!" << endl;
}

void apagarCadastro()//Para apagar os arquivos com dados dos usuários
{
    string usuario = "dados_usuario.txt";
    string renda = "dados_renda.txt";
    string financeiro = "dados_financeiros.txt";
    string cofrinho = "dados_cofre.txt";

    if (remove(usuario.c_str())==0 && remove(renda.c_str())==0 && remove(financeiro.c_str())==0 && remove(cofrinho.c_str())==0)
    {
        cout << "Arquivos apagados com sucesso!";
    }
}

// Função que cadastra o usuário
void cadastrarUsuario(Usuario *novoUsuario)
{
    if(!arquivoContemDados())
    {
        cabecalho();
        gotoxy(50,16);
        cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" ;
        gotoxy(50,17);
        cout << "====================================================";

        gotoxy(42,19);
        cout << "Digite seu nome de usuario: ";
        gotoxy(42,20);
        getline(cin, novoUsuario->nome);

        gotoxy(42,22);
        cout << "Digite seu cpf: " ;
        gotoxy(42,23);
        getline(cin, novoUsuario->cpf);

        gotoxy(42,25);
        cout << "Digite sua senha de login: " ;
        gotoxy(42,26);
        getline(cin, novoUsuario->senha);

        salvarUsuario(novoUsuario);

        gotoxy(61,28);
        cout << "Usuario cadastrado com sucesso" ;
        gotoxy(50,29);
        cout << "====================================================";

    }
    else
    {
        importarUsuario(novoUsuario);
        logarUsuario(novoUsuario);
    }
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
void importarUsuario(Usuario *novoUsuario)
{
    ifstream arquivo;
    arquivo.open("dados_usuario.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
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

// Função que verifica se as senhas são iguais
bool verificarSenha(const string &senhaDigitada,Usuario *dados)
{
     importarUsuario(dados);

    return (senhaDigitada == dados->senha);
}

#endif // USUARIO_H_INCLUDED
