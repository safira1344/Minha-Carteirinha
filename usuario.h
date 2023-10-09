#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

struct Usuario
{
    string nome;
    string cpf;
    string senha;
};

// Assinatura das funções
void logarUsuario(Usuario *usuario);
void novoCadastro(Usuario *novoUsuario);
void dadosUsuario(Usuario *novoUsuario);
bool arquivoContemDados();
void salvarUsuario(Usuario *novoUsuario);
Usuario importarUsuario();
bool verificarSenha(const string &senhaDigitada, Usuario *dados);
void editarUsuario(Usuario *usuario);
void menuPrincipal();


// Função main dessa biblioteca
int cadastroOuLogin()
{
    Usuario usuario;

    if (arquivoContemDados())
    {
        logarUsuario(&usuario);
    }
    else
    {
        novoCadastro(&usuario);
    }

    return 0;
}

// Função que loga o usuário
void logarUsuario(Usuario *usuario)
{
    *usuario = importarUsuario();

    telaLogin();

    gotoxy(42, 17);
    cout << "Ola, " << usuario->nome << "!" << endl;
    gotoxy(42, 18);
    cout << "====================================================" << endl;

    int tentativas = 0;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        gotoxy(42, 19);
        cout << "Digite sua senha de login: " << endl;
        gotoxy(42, 20);
        getline(cin, senhaDigitada);
        gotoxy(42, 20);
        cout << "                              " << endl;

        if (verificarSenha(senhaDigitada, usuario))
        {
            gotoxy(42, 21);
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            gotoxy(42, 21);
            cout << "Senha incorreta!" << endl;
            if (++tentativas == 3)
            {
                gotoxy(42, 23);
                cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
                gotoxy(42, 24);
                cout << "Contate o administrador do sistema." << endl;
                gotoxy(42, 25);
                cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
                gotoxy(42, 26);
                cin >> opcao;

                if (opcao == 'S' || opcao == 's')
                {
                    novoCadastro(usuario);
                }
                else
                {
                    gotoxy(42, 26);
                    cout << "Obrigado por usar o programa!" << endl;
                    exit(0);
                }
                return;
            }
            gotoxy(42, 22);
            cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
        }

        // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
    }
    menuPrincipal();
}

// Função para cadastrar usuario no sistema
void novoCadastro(Usuario *novoUsuario)
{
    cabecalho();
    gotoxy(50, 16);
    cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" << endl;
    gotoxy(50, 17);
    cout << "====================================================" << endl;

    gotoxy(42, 19);
    cout << "Digite seu nome de usuario: " << endl;
    gotoxy(42, 20);
    getline(cin, novoUsuario->nome);

    gotoxy(42, 22);
    cout << "Digite seu cpf: " << endl;
    gotoxy(42, 23);
    getline(cin, novoUsuario->cpf);

    gotoxy(42, 25);
    cout << "Digite sua senha de login: " << endl;
    gotoxy(42, 26);
    getline(cin, novoUsuario->senha);

    salvarUsuario(novoUsuario);

    gotoxy(61, 28);
    cout << "Usuario cadastrado com sucesso" << endl;
    gotoxy(50, 29);
    cout << "====================================================" << endl
         << endl;

    
    menuPrincipal();
}

void editarUsuario(Usuario *usuario)
{
    cabecalho();
    gotoxy(50, 16);
    cout << "Seja Bem Vindo, cadastre-se para usar a aplicacao!!!" << endl;
    gotoxy(50, 17);
    cout << "====================================================" << endl;

    gotoxy(42, 19);
    cout << "Digite seu nome de usuario: " << endl;
    gotoxy(42, 20);
    // cin.ignore();
    getline(cin, usuario->nome);
    gotoxy(42, 22);
    cout << "Digite seu cpf: " << endl;

    gotoxy(42, 23);
    getline(cin, usuario->cpf);
    gotoxy(42, 25);
    cout << "Digite sua senha de login: " << endl;

    gotoxy(42, 26);
    getline(cin, usuario->senha);
    cin.ignore();
    
    salvarUsuario(usuario);

    gotoxy(61, 28);
    cout << "Usuario editado com sucesso" << endl;

    gotoxy(50, 29);
    cout << "====================================================" << endl
         << endl;

    
    menuPrincipal();
}

void apagarUsuario(Usuario *novoUsuario)
{
    novoCadastro(novoUsuario);
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
        return novoUsuario;
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
bool verificarSenha(const string &senhaDigitada, Usuario *dados)
{
    importarUsuario();

    return (senhaDigitada == dados->senha);
}

#endif
