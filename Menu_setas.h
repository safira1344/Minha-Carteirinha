#ifndef MENU_SETAS_H_INCLUDED
#define MENU_SETAS_H_INCLUDED
/// seta cima = 72
/// direita = 77
/// esqueda = 75
/// baixo = 80
/// ESC   = 27

#include <iostream>
#include "usuario.h"
#include "mensagens.h"
#include "relatorio.h"

int menu_setas_principal();
int menu_principal(Usuario *usuario);


int menu_principal(Usuario *usuario)
{

    int escolha;
    // escolha = menu_setas_principal();

    while (true) // laço infinito
    {
        cout << "Opcao 1 = criar usuario" << endl
             << "opcao 4 = mostrar usuario"<<endl;

        cin >> escolha;
        cin.ignore();           // remover o buffer do teclado
        switch (escolha)
        {
        case 1:
            cadastrarUsuario(usuario);
            break;
        case 2:
            // relatorio();
            break;
        case 3:
            // mensagens();
            break;
        case 4:
            dadosUsuario(usuario);
            break;
        }
    }
    // tela_final();
}

int menu_setas_principal()
{
    interface_menu();
    perfumaria_menu_principal();

    int escolha, enter = 1, linha = 19, aux = 19;

    do
    {
        escolha = getch();
        switch (escolha)
        {
        case 13:
            return enter;
            break;
        case 80:
            if (linha < 34)
            {
                linha += 5;
                retangulos(MAGENTA, 52, linha, 3, 50);
                retangulos(15, 51, linha - 1, 3, 50);

                retangulos(0, 52, aux, 3, 50);
                retangulos(15, 51, aux - 1, 3, 50);
                enter++;
            }
            break;
        case 72:
            if (linha > 19)
            {
                linha -= 5;
                retangulos(MAGENTA, 52, linha, 3, 50);
                retangulos(15, 51, linha - 1, 3, 50);

                retangulos(0, 52, aux, 3, 50);
                retangulos(15, 51, aux - 1, 3, 50);

                enter--;
            }
            break;
        }
        perfumaria_menu_principal();
        aux = linha;
    } while (escolha != 27);
    enter = 4;
    return enter;
}

#endif // MENU_SETAS_H_INCLUDED
