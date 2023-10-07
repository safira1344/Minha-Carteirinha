#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

// Assinatura das funções
void extrairRenda(string &arquivoRenda, string &data, string &mesExtenso);
void extrairDespesas(string &arquivoDespesa, string &data, string &mesExtenso);
void extrairCofrinho(string &arquivoCofre, string &data, string &mesExtenso);
string converterMes(string data);

// Funcao main dessa biblioteca
void emitirRelatorio()
{
    string data;
    cout << "Digite o mes desejado no formato mm-aaaa: ";
    cin >> data;

    if (data.size() != 7 || data[2] != '-')
    {
        cout << "Formato de mês inválido. Use o formato mm-aaaa." << endl;
        return;
    }

    string mesExtenso = converterMes(data);

    string arquivoRenda = "dados_renda.txt";
    string arquivoDespesa = "dados_financeiros.txt";
    string arquivoCofre = "dados_cofre.txt";

    Usuario usuario = importarUsuario();
    string mesEmissao = obterMesAtual();

        cout << ""<< endl;
        cout << "---- RELATORIO DE CONTROLE DE GASTOS DO MES " << data << " ----"<< endl << endl;
        cout << "Nome: " << usuario.nome << endl;
        cout << "CPF: " << usuario.cpf << endl << endl;
        cout << "Mes de emissao do Relatorio: " << mesEmissao << endl << endl;
        extrairRenda(arquivoRenda, data, mesExtenso);
        extrairDespesas(arquivoDespesa, data, mesExtenso);
        extrairCofrinho(arquivoCofre, data, mesExtenso);
        cout << "-------------------------------------------------------" << endl << endl;

}

// Função que soma todas as rendas de dentro do arquivo de renda
void extrairRenda(string &arquivoRenda, string &data, string &mesExtenso)
{
    ifstream arquivo(arquivoRenda);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de rendas." << endl;
    }

    double totalRendas = 0.0;
    string linha;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string nomeRenda;
            double valorRenda = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Nome: ") != string::npos)
                {
                    nomeRenda = linha.substr(linha.find("Nome: ") + 6);
                }
                else if (linha.find("Valor: R$ ") != string::npos)
                {
                    valorRenda = stod(linha.substr(linha.find("Valor: R$ ") + 9));
                }
            }

            totalRendas += valorRenda;
        }
    }

    arquivo.close();

    cout << "RENDA" << endl;
    cout << "- Renda Total de " << mesExtenso << ": " << totalRendas << endl << endl;
}

// Função que importa o nome e valor das despesas, e faz a soma delas
void extrairDespesas(string &arquivoDespesa, string &data, string &mesExtenso)
{
    ifstream arquivo(arquivoDespesa);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de despesas." << endl;
        return;
    }

    double totalDespesasMes = 0.0;
    string linha;

    cout << "DESPESAS" << endl;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string categoriaDespesa;
            double valorDespesa = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Categoria: ") != string::npos)
                {
                    categoriaDespesa = linha.substr(linha.find("Categoria: ") + 11);
                }
                else if (linha.find("Valor: ") != string::npos)
                {
                    valorDespesa = stod(linha.substr(linha.find("Valor: ") + 7));
                }
            }

            cout << "- Despesa: " << categoriaDespesa << " - " << valorDespesa << endl;
            totalDespesasMes += valorDespesa;
        }
    }

    arquivo.close();

    cout << "" << endl;
    cout << "Despesa total em " << mesExtenso << ": " << totalDespesasMes << endl << endl;
}

// Função que importa o nome e valor dos cofres, e faz a soma deles
void extrairCofrinho(string &arquivoCofre, string &data, string &mesExtenso)
{
    ifstream arquivo(arquivoCofre);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo do cofre." << endl;
        return;
    }

    double totalGuardado = 0.0;
    string linha;

    cout << "DINHEIRO GUARDADO" << endl;

    while (getline(arquivo, linha))
    {
        if (linha.find("Mes de Cadastro: " + data) != string::npos)
        {
            string nomeCofre;
            double valorCofre = 0.0;

            while (getline(arquivo, linha) && !linha.empty())
            {
                if (linha.find("Nome: ") != string::npos)
                {
                    nomeCofre = linha.substr(linha.find("Nome: ") + 6);
                }
                else if (linha.find("Valor: ") != string::npos)
                {
                    valorCofre = stod(linha.substr(linha.find("Valor: ") + 7));
                }
            }

            cout << "- Cofre: " << nomeCofre << " - " << valorCofre << endl;
            totalGuardado += valorCofre;
        }
    }

    arquivo.close();

    cout << "" << endl;
    cout << "Valor total guardado em " << mesExtenso << ": " << totalGuardado << endl << endl;
}

// Função que escreve o mes por extenso
string converterMes(string data)
{
    string numeroMes = data.substr(0, 2);
    string ano = data.substr(3);

    string nomeMes;
    if (numeroMes == "01") nomeMes = "janeiro";
    else if (numeroMes == "02") nomeMes = "fevereiro";
    else if (numeroMes == "03") nomeMes = "março";
    else if (numeroMes == "04") nomeMes = "abril";
    else if (numeroMes == "05") nomeMes = "maio";
    else if (numeroMes == "06") nomeMes = "junho";
    else if (numeroMes == "07") nomeMes = "julho";
    else if (numeroMes == "08") nomeMes = "agosto";
    else if (numeroMes == "09") nomeMes = "setembro";
    else if (numeroMes == "10") nomeMes = "outubro";
    else if (numeroMes == "11") nomeMes = "novembro";
    else if (numeroMes == "12") nomeMes = "dezembro";
    else nomeMes = "mês inválido";

    return nomeMes + " de " + ano;
}

#endif

