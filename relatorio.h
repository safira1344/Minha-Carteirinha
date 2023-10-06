#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct UsuarioRelatorio {
    string nome;
    string cpf;
};

struct RendaRelatorio {
    int mesCadastro;
    string nome;
    double valor;
};

struct DespesaRelatorio {
    int mesCadastro;
    string categoria;
    double valor;
};

void extrairUsuario(const string& arquivoUsuario) {
    ifstream arquivo(arquivoUsuario);

    if (arquivo.is_open()) {
        string nomeUsuario, cpfUsuario;
        while (arquivo >> nomeUsuario >> cpfUsuario) {
            cout << "Nome: " << nomeUsuario << ", CPF: " << cpfUsuario << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de usuários." << endl;
    }
}

double calculoRenda(const string& arquivoRenda, int mesDesejado) {
    ifstream arquivo(arquivoRenda);
    double totalRendas = 0.0;

    if (arquivo.is_open()) {
        int mesRenda;
        string nomeRenda;
        double valorRenda;
        while (arquivo >> mesRenda >> nomeRenda >> valorRenda) {
            if (mesRenda == mesDesejado) {
                totalRendas += valorRenda;
            }
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de rendas." << endl;
    }

    return totalRendas;
}

void extrairDespesas(const string& arquivoDespesa, int mesDesejado) {
    ifstream arquivo(arquivoDespesa);
    double totalDespesasMes = 0.0;

    if (arquivo.is_open()) {
        int mesDespesa;
        string categoriaDespesa;
        double valorDespesa;

        while (arquivo >> mesDespesa >> categoriaDespesa >> valorDespesa) {
            if (mesDespesa == mesDesejado) {
                cout << "Categoria: " << categoriaDespesa << ", Valor: " << valorDespesa << endl;
                totalDespesasMes += valorDespesa;
            }
        }
        arquivo.close();

        cout << "Total de Despesas em " << mesDesejado << ": " << totalDespesasMes << endl;
    } else {
        cout << "Erro ao abrir o arquivo de despesas." << endl;
    }
}

// Função main
int emitirRelatorio() {

    int mesDesejado;
    cout << "Digite o mês desejado (1 a 12): ";
    cin >> mesDesejado;

    double totalRendas;

    string arquivoUsuario = "dados_usuario.txt";
    string arquivoRenda = "dados_renda.txt";
    string arquivoDespesa = "dados_financeiros.txt";

    extrairUsuario(arquivoUsuario);

    totalRendas = calculoRenda(arquivoRenda, mesDesejado);
    cout << "Total de Rendas no mês " << mesDesejado << ": " << totalRendas << endl;

    extrairDespesas(arquivoDespesa, mesDesejado);

    return 0;
}

#endif

