#ifndef MENSAGENS_H_INCLUDED
#define MENSAGENS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


struct Gasto {
    string categoria;
    double valor;
    string dataVenc;
};

// Função que verifica se uma data está próxima da data atual
bool dataProxima(const string& dataVenc) {
    time_t horaAtual = time(nullptr);
    tm dataAtual = *horaLocal(&horaAtual);

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


int notificacao() {
    ifstream inputFile("dados_financeiro.txt");

    if (!inputFile) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }
}

    inputFile.close();
    return 0;
}

#endif // MENSAGENS_H_INCLUDED
