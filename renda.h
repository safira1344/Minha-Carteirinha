#ifndef RENDA_H_INCLUDED
#define RENDA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Renda {
    string nome;
    double valor;
};

Renda* criarRenda() {
    Renda* novaRenda = new Renda;
    novaRenda->valor = 0.0;
    return novaRenda;
}

void solicitarRenda(Renda* renda) {
    ofstream arquivo("dados_renda.txt", ios::app);

    cout << "Insira de onde vem a renda: ";
    cin.ignore();
    getline(cin, renda->nome);
    cout << "Informe o valor da renda mensal de " << renda->nome << ": R$ ";
    cin >> renda->valor;

    time_t now = time(0);
    tm* ltm = localtime(&now);

    char buffer[8];
    strftime(buffer, sizeof(buffer), "%m-%Y", ltm);

    string mesCadastro = string(buffer);


    if (arquivo.is_open()) {
        arquivo << "Mês de Cadastro: " << mesCadastro << endl;
        arquivo << "Renda proveniente de: " << renda->nome << endl;
        arquivo << "Valor: R$ " << renda->valor << endl;
        arquivo << endl;

        arquivo.close();

        cout << "Renda de " << renda->nome << " salva com sucesso!!!" << endl << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvamento" << endl;
    }
}

void exibirRenda(const Renda* renda) {
    cout << "Renda de " << renda->nome << ": R$ " << renda->valor << endl;
}

// Função main
void entradaDeRenda() {
    cout << "Bem-vindo a sua CARTEIRINHA!" << endl << endl;
    cout << "Primeiro passo - Vamos cadastrar sua renda..." << endl<< endl;


    char opcao;
    do {
        Renda* renda = criarRenda();
        solicitarRenda(renda);
        delete renda;

        cout << "Deseja adicionar outra renda? (S/N): ";
        cin >> opcao;
    } while (opcao == 'S' || opcao == 's');

    cout << "" << endl;
}

#endif
