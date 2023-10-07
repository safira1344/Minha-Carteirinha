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
#include "mensagens.h"
#include "interface.h"
#include "usuario.h"
#include "despesas.h"
#include "renda.h"
#include "cofrinho.h"
#include "relatorio.h"
#include "menu.h"
#include "carteirinha.h"

#define MAX_GASTOS 10


bool arquivoExiste(const string& arquivoDados) {
    ifstream arquivo(arquivoDados);
    return arquivo.good();
}

int main()
{
    Usuario novoUsuario;

    cadastroOuLogin();

    if (!arquivoExiste("dados_financeiros.txt")) {

        entradaDeRenda();
        entradaDeCategorias();
//        entradaDeCofrinho();

    }

    menuPrincipal();
    
    return 0;
}
