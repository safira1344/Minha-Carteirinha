#ifndef MENSAGENS_H_INCLUDED
#define MENSAGENS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int main() {
    vector<Gasto> listaGastos;
    ifstream inputFile("dados_financeiro.txt");

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    string linha;
    Gasto gastosAtuais;

    while (getline(inputFile, linha)) {
        if (linha.find("Data de Vencimento: ") != string::npos) {
            gastosAtuais.dataVenc = linha.substr(21);
            listagastos.push_back(gastosAtuais);
        }
    }

    inputFile.close();

    // Verifica se alguma data de vencimento está próxima
    //for (const Gasto& gasto : listagastos) {
    //    if (dataProxima(gasto.dataVenc)) {
    //        cout << "Aviso: A data de vencimento para a categoria '" << gasto.categoria
    //                  << "' está próxima (" << gasto.dataVenc << ")." << endl;
        }
    }

    return 0;
}

#endif // MENSAGENS_H_INCLUDED
