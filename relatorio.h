#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

// Assinatura das funções
string converterMes(string data);

// Funcao main dessa biblioteca
void emitirRelatorio()
{
    telinha();

    string data;

    gotoxy(42,10);
    cout << "Digite o mes desejado no formato mm-aaaa: ";
    gotoxy(42,11);
    cin >> data;

    while(data.size() != 7 || data[2] != '-')
    {
        moldurinha(30, 120, 8, 30, WHITE, BLACK);
        gotoxy(42,10);
        cout << "Formato de mês inválido. Use o formato mm-aaaa." << endl;
        gotoxy(10,11);
        cout << "Digite o mes desejado no formato mm-aaaa: ";
        gotoxy(10,12);
        cin >> data;
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

    telinha();

    gotoxy(42,10);
    cout << "---- RELATORIO DE CONTROLE DE GASTOS DO MES " << data << " ----" ;
    gotoxy(42,12);
    cout << "Nome: " << usuario.nome ;
    gotoxy(42,13);
    cout << "CPF: " << usuario.cpf;
    gotoxy(42,14);
    cout << "Mes de emissao do Relatorio: " << mesEmissao;
    gotoxy(42,15);
    cout << "RENDA" ;
    gotoxy(42,16);
    cout << "- Renda Total de " << mesExtenso << ": " << totalRendas;

    extrairDespesas(arquivoDespesa, data);

    gotoxy(42,18);
    cout << "Despesa total em " << mesExtenso << ": " << despesaTotal ;
    extrairCofrinho(arquivoCofre, data);

    gotoxy(42,19);
    cout << "Valor total guardado em " << mesExtenso << ": " << totalGuardado;
    gotoxy(42,20);
    cout << "-------------------------------------------------------";
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
