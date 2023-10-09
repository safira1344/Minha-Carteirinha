#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <regex>

using namespace std;
#include "gconio.h"
#include "interface.h"
#include "mensagens.h"
#include "usuario.h"
#include "despesas.h"
#include "renda.h"
#include "cofrinho.h"
#include "relatorio.h"
#include "carteirinha.h"
#include "menu.h"

#define MAX_GASTOS 10

bool arquivoExiste(const string &arquivoDados)
{
    ifstream arquivo(arquivoDados);
    return arquivo.good();
}

int main()
{
    Usuario novoUsuario;

    tela_incial();
    confirmar(70, 29);
    cadastroOuLogin();
    menuPrincipal();

    if (!arquivoExiste("dados_financeiros.txt"))
    {

        entradaDeRenda();
        entradaDeCategorias();
        guardarDinheiro();
    }


    return 0;
}