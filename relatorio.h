#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

// Assinatura das funções
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

    double despesaTotal = extrairDespesas(arquivoDespesa, data);
    double totalGuardado = extrairCofrinho(arquivoCofre, data);
    double totalRendas = somarRenda(arquivoRenda, data);

    Usuario usuario = importarUsuario();
    string mesEmissao = obterMesAtual();

    cout << endl
         << "---- RELATORIO DE CONTROLE DE GASTOS DO MES " << data << " ----" << endl
         << endl;
    cout << "Nome: " << usuario.nome << endl;
    cout << "CPF: " << usuario.cpf << endl
         << endl;
    cout << "Mes de emissao do Relatorio: " << mesEmissao << endl
         << endl;
    cout << "RENDA" << endl;
    cout << "- Renda Total de " << mesExtenso << ": " << totalRendas << endl
         << endl;

    extrairDespesas(arquivoDespesa, data);

    cout << "" << endl;
    cout << "Despesa total em " << mesExtenso << ": " << despesaTotal << endl
         << endl;

    extrairCofrinho(arquivoCofre, data);

    cout << "" << endl;
    cout << "Valor total guardado em " << mesExtenso << ": " << totalGuardado << endl
         << endl;

    cout << "-------------------------------------------------------" << endl
         << endl;
}

// Função que escreve o mes por extenso
string converterMes(string data)
{
    string numeroMes = data.substr(0, 2);
    string ano = data.substr(3);

    string nomeMes;
    if (numeroMes == "01")
        nomeMes = "janeiro";
    else if (numeroMes == "02")
        nomeMes = "fevereiro";
    else if (numeroMes == "03")
        nomeMes = "março";
    else if (numeroMes == "04")
        nomeMes = "abril";
    else if (numeroMes == "05")
        nomeMes = "maio";
    else if (numeroMes == "06")
        nomeMes = "junho";
    else if (numeroMes == "07")
        nomeMes = "julho";
    else if (numeroMes == "08")
        nomeMes = "agosto";
    else if (numeroMes == "09")
        nomeMes = "setembro";
    else if (numeroMes == "10")
        nomeMes = "outubro";
    else if (numeroMes == "11")
        nomeMes = "novembro";
    else if (numeroMes == "12")
        nomeMes = "dezembro";
    else
        nomeMes = "mês inválido";

    return nomeMes + " de " + ano;
}

#endif