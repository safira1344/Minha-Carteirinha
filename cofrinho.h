#ifndef COFRINHO_H_INCLUDED
#define COFRINHO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função main
int entradaDeCofrinho() {
    char opcao;
    cout << "E pra finalizar..." << endl << endl;
    cout << "Deseja guardar dinheiro? (S/N): ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's'){
        do {
            string nomeCofrinho;
            double quantidadeDinheiro;

            cout << "Informe o nome do cofrinho: ";
            cin >> nomeCofrinho;

            cout << "Informe a quantidade de dinheiro que deseja guardar: R$ ";
            cin >> quantidadeDinheiro;
            cout <<""<< endl;

            ofstream arquivo("dados_cofre.txt");

            if (arquivo.is_open()) {
                arquivo << "Nome do cofrinho: " << nomeCofrinho << endl;
                arquivo << "Valor Guardado: R$ " << quantidadeDinheiro << endl;

                arquivo.close();

                cout << "Os dados foram salvos com sucesso!!!" << endl << endl;
            } else {
                cout << "Erro ao abrir o arquivo, desculpe" << endl;
            }

            cout << "Deseja guardar mais dinheiro para outra coisa? (S/N): ";
            cin >> opcao;

        } while (opcao == 'S' || opcao == 's');
    }
    return 0;
}

#endif
