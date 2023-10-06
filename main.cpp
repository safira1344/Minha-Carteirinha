#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>

#include "gconio.h"
#include "interface.h"
#include "usuario.h"
#include "categoria.h"
#include "renda.h"
#include "cofrinho.h"
#include "relatorio.h"
#include "menu.h"


#define MAX_GASTOS 10

using namespace std;

bool arquivoExiste(const string& arquivoDados) {
    ifstream arquivo(arquivoDados);
    return arquivo.good();
}

int main()
{
    Usuario novoUsuario;

    cadastrarUsuario(&novoUsuario);

    if (!arquivoExiste("dados_financeiros.txt")) {

        entradaDeRenda();
        entradaDeCategorias();
        entradaDeCofrinho();

    }

    menuPrincipal();


    return 0;
}

