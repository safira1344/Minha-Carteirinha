#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <regex>

#include "gconio.h"
#include "bibliotecas/mensagens.h"
#include "bibliotecas/interface.h"
#include "bibliotecas/usuario.h"
#include "bibliotecas/despesas.h"
#include "bibliotecas/renda.h"
#include "bibliotecas/cofrinho.h"
#include "bibliotecas/relatorio.h"
#include "bibliotecas/menu.h"
#include "bibliotecas/carteirinha.h"

#define MAX_GASTOS 10

using namespace std;

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
        entradaDeCofrinho();

    }

    menuPrincipal();
    
    return 0;
}
