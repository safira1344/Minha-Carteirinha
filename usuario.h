struct Gastos
    {
        string despesa;
        double valor;
        int diaVencimento;
        int mesVencimento;
        int anoVencimento;
    } gasto[10];

struct Usuario
{
    string cpf;
     string nome;
     string senha;
    double ganho;
};

void cadastrar_categorias(int n);

void categorias()
{
    char resp ;
    int i = 0;

    do
    {
         cout << "Categorgia: ";
         cin >> gasto[i].despesa;

         cout << "Valor: ";
         cin >> gasto[i].valor;

         cout << "Data de vencimento: ";
         cin >> gasto[i].diaVencimento >> gasto[i].mesVencimento >> gasto[i].anoVencimento;

         cout <<"Deseja Continuar cadatrando? S p/sim n p/nao";
         cin >> resp;
        i++;
    }while(resp == 'S' || resp == 's');
    cadastrar_categorias(i);
}

void cadastrar_categorias(int n)
{
     ofstream categorias;
    int i=0;
    categorias.open("dados_financeiro.txt",  ios :: app);


    if(categorias.is_open())
    {
        while(i<n)
        {
            categorias << "Categoria: "<<gasto[i].despesa<<"\n"<< "Valor: " << gasto[i].valor
            <<"\n"<< "Data de vencimento: " <<gasto[i].diaVencimento<<"-"<<gasto[i].mesVencimento
            <<"-"<<gasto[i].anoVencimento<<"\n\n";

            i++;
        }
    }
    categorias.close();
}

// função para criar um novo cadastro do usuário
//void cadastrarUsuario(Usuario *usuario)
//{
//    cout << "Digite seu nome de usuario: " << endl;
//    getline(cin, usuario->nome);
//
//    cout << "Digite seu cpf: " << endl;
//    getline(cin, usuario->cpf);
//
//    cout << "Digite sua senha: " << endl;
//    getline(cin, usuario->senha);
//
//    Carteira carteira;
//
//    cout << "Digite quanto voce ganha por mes: " << endl;
//    cin >> carteira.ganho;
//    cin.ignore();
//
//    usuario->carteira = carteira;
//
//    cout << "Cadastro criado com sucesso!" << endl;
//}
//
//
//// #TO DO
////atualizar cadastro;
//
////cadsastrar gastos;
//
//void dadosUsuario(Usuario *usuario)
//{
//    cout << "Nome: " << usuario->nome << endl;
//    cout << "Cpf: " << usuario->cpf << endl;
//    cout << "Senha: " << usuario->senha << endl;
//    cout << "Ganho: " << usuario->carteira.ganho << endl;
//}
//
//#endif
