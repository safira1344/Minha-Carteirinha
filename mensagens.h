#ifndef MENSAGENS_H_INCLUDED
#define MENSAGENS_H_INCLUDED

struct Gasto
{
    string categoria;
    double valor;
    string dataVenc;
};

// Função que verifica se uma data está próxima da data atual
bool dataProxima(const string &dataVenc)
{
    time_t horaAtual = time(nullptr);
    tm dataAtual = *localtime(&horaAtual);

    // Converte a data de vencimento em uma estrutura tm tbm
    tm dataVencStruct = {};
    istringstream dataVencStream(dataVenc);
    dataVencStream >> get_time(&dataVencStruct, "%d-%m-%Y");

    // Calcula a diferença entre a data de vencimento e a data atual
    time_t dataVencTimestamp = mktime(&dataVencStruct);
    time_t diferenca = dataVencTimestamp - horaAtual;

    // Verifica se a data de vencimento está próxima
    return (diferenca >= 0 && diferenca <= 2 * 24 * 60 * 60); // 2 dias em segundos
}

int notificacao()
{
    ifstream arquivo("dados_financeiros.txt");
    int n = 15;
    int l = 10;

    telinha();

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return(1);
    }

    string linha;
    Gasto despesaAtual;

    while (getline(arquivo, linha))
    {

        if (linha.find("Categoria: ") != string::npos)
        {
            despesaAtual.categoria = linha.substr(11);
        }
        else if (linha.find("Valor: ") != string::npos)
        {
            despesaAtual.valor = stod(linha.substr(7));
        }
        else if (linha.find("Data de Vencimento: ") != string::npos)
        {
            despesaAtual.dataVenc = linha.substr(21);

            if (dataProxima(despesaAtual.dataVenc))
            {
                if (l == 26)

                    confirmar(42, 27);

                else
                {
                    gotoxy(42, l);
                    cout << "Aviso: A data de vencimento para a categoria '" << despesaAtual.categoria;
                    gotoxy(42, +1);
                    cout << "' esta proxima (" << despesaAtual.dataVenc << ").";
                    l++;
                }
                n = RED;
            }
        }
    }

    arquivo.close();

    return n;
}

#endif
