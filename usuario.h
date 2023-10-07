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
bool verificarSenha(const string &senhaDigitada,Usuario *dados);


// Função main dessa biblioteca
int cadastroOuLogin() {
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
void logarUsuario(Usuario *usuario){
    *usuario = importarUsuario();

    cout << "Ola, " << usuario->nome << "!" << endl;
    cout << "====================================================" << endl;

    int tentativas = 0;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        cout << "Digite sua senha de login: " << endl;
        getline(cin, senhaDigitada);

        if (verificarSenha(senhaDigitada, usuario))
        {
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            cout << "Senha incorreta!" << endl;
            cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
        }

        // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
        if (++tentativas == 3)
        {
            cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
            cout << "Contate o administrador do sistema." << endl;

            cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
            cin >> opcao;

            if (opcao == 'S' || opcao == 's')
            {
                novoCadastro(usuario);
            }
            else
            {
                cout << "Obrigado por usar o programa!" << endl;
                exit(0);
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////

        }
    }
}

// Função para cadastrar usuario no sistema
void novoCadastro(Usuario *novoUsuario)
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
bool verificarSenha(const string &senhaDigitada,Usuario *dados)
{
     importarUsuario();

    return (senhaDigitada == dados->senha);
}

#endif#ifndef USUARIO_H_INCLUDED
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
bool verificarSenha(const string &senhaDigitada,Usuario *dados);


// Função main dessa biblioteca
int cadastroOuLogin() {
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
void logarUsuario(Usuario *usuario){
    *usuario = importarUsuario();

    cout << "Ola, " << usuario->nome << "!" << endl;
    cout << "====================================================" << endl;

    int tentativas = 0;
    string senhaDigitada;

    char opcao;
    while (true)
    {
        cout << "Digite sua senha de login: " << endl;
        getline(cin, senhaDigitada);

        if (verificarSenha(senhaDigitada, usuario))
        {
            cout << "Senha correta!" << endl;
            break;
        }
        else
        {
            cout << "Senha incorreta!" << endl;
            cout << "Voce tem mais " << 3 - tentativas << " tentativas." << endl;
        }

        // Se o numero de tentativas for maior que 3 o usuário pode cadastrar um novo usuário ou sair do sistema
        if (++tentativas == 3)
        {
            cout << "Numero de tentativas excedido, conta bloqueada!" << endl;
            cout << "Contate o administrador do sistema." << endl;

            cout << "Deseja cadastrar um novo usuario? (S/N)" << endl;
            cin >> opcao;

            if (opcao == 'S' || opcao == 's')
            {
                novoCadastro(usuario);
            }
            else
            {
                cout << "Obrigado por usar o programa!" << endl;
                exit(0);
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////

        }
    }
}

// Função para cadastrar usuario no sistema
void novoCadastro(Usuario *novoUsuario)
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
bool verificarSenha(const string &senhaDigitada,Usuario *dados)
{
     importarUsuario();

    return (senhaDigitada == dados->senha);
}

#endif
