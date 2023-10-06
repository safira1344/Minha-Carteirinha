#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <ctime>

using namespace std;

struct Despesa {
    string categoria;
    double valor;
    string dataVencimento;
    double tetoDeGasto;
    string mesCadastro; // Esse int representa o mês em que a despesa foi cadastrada
};


string extrairMesAtual();
bool validarData(const string& data);
double solicitarTeto();
string solicitarDataVenc();
void entradaDeCategorias();


//Função main
void entradaDeCategorias() {
    string dadosDespesas = "dados_financeiros.txt";
    ofstream arquivo(dadosDespesas, ios::app);

    cout << "Segundo Passo - Vamos cadastrar suas despesas, por categorias (Moradia, Cartoes...)" << endl << endl;

    const int maxDespesas = 100;
    Despesa** despesas = new Despesa*[maxDespesas];

    char continuar;
    int numDespesas = 0;

    do {
        despesas[numDespesas] = new Despesa;

        despesas[numDespesas]->mesCadastro = extrairMesAtual();

        arquivo << "Mês de Cadastro: " << despesas[numDespesas]->mesCadastro << endl;

        cout << "Digite a categoria da despesa: ";
        cin.ignore();
        getline(cin, despesas[numDespesas]->categoria);

        cout << "Digite o valor da despesa: R$ ";
        cin >> despesas[numDespesas]->valor;
        cout << "" << endl;

        despesas[numDespesas]->dataVencimento = solicitarDataVenc();

        cout << "" << endl;

        despesas[numDespesas]->tetoDeGasto = solicitarTeto();

        arquivo << "Categoria: " <<  despesas[numDespesas]->categoria << endl;
        arquivo << "Valor: " <<  despesas[numDespesas]->valor << endl;

        if (! despesas[numDespesas]->dataVencimento.empty()) {
            arquivo << "Data de Vencimento: " <<  despesas[numDespesas]->dataVencimento << endl;
        }
        if (despesas[numDespesas]->tetoDeGasto > 0.0) {
            arquivo << "Teto de Gasto: " << despesas[numDespesas]->tetoDeGasto << endl;
        }

        arquivo << endl;

        cout << "Despesa registrada com sucesso!" << endl << endl;
        numDespesas++;


        cout << "Deseja adicionar outra despesa? (S/N): ";
        cin >> continuar;
        if (continuar != 'S' && continuar != 's') {
            break; // Sai do loop se a resposta não for 'S' ou 's'
        }
    } while (numDespesas < maxDespesas);

    cout << "" << endl;

    arquivo.close();

    }



// Função para obter o mês atual
string extrairMesAtual() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char buffer[8];
    strftime(buffer, sizeof(buffer), "%m-%Y", ltm);

    return string(buffer);
}

// Função para validar a data no formato dd-mm-aaaa usando expressão regular
bool validarData(const string& data) {
    regex pattern("^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-20(23|\\d{2})$");
    return regex_match(data, pattern);
}

// Função para limpar a struct
void limparDespesa(Despesa* pDespesa) {
    pDespesa->categoria = "";
    pDespesa->valor = 0.0;
    pDespesa->dataVencimento = "";
    pDespesa->tetoDeGasto = 0.0;
    pDespesa->mesCadastro = "";
}

// Função para solicitar e validar o teto de gasto
double solicitarTeto() {
    string tetoDeGasto;
    char escolha;

    cout << "Deseja digitar o teto de gasto? (S/N): ";
    cin >> escolha;

    if (escolha == 'S' || escolha == 's') {
        cout << "Digite o teto de gasto (ou deixe em branco): R$ ";
        cin.ignore();
        getline(cin, tetoDeGasto);
        if (!tetoDeGasto.empty()) {
            return stod(tetoDeGasto);
        }
    }

    return 0.0;
}

// Função para solicitar e validar a data de vencimento
string solicitarDataVenc() {
    string data;
    char escolha;

    cout << "Deseja digitar a data de vencimento? (S/N): ";
    cin >> escolha;

    if (escolha == 'S' || escolha == 's') {
        do {
            cout << "Digite uma data válida de vencimento da despesa (dd-mm-aaaa): ";
            cin >> data;
        } while (!validarData(data));
        return data;
    }

    return "";
}

#endif
