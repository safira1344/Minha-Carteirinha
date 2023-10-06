#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// seta cima = 72
/// direita = 77
/// esqueda = 75
/// baixo = 80
/// ESC   = 27

#include <iostream>
#include "usuario.h"
#include "mensagens.h"
#include "relatorio.h"

//int menu_setas_principal();

int menuPrincipal()
{
    int escolha;

    do
    {
        cout //<< "1- Ver Minha Carteirinha" << endl
             << "2- Emitir Relatorio" << endl
             //<< "3- Notificacoes" << endl
             //<< "4- Meu Perfil" << endl
             << "5- Sair do Programa" << endl
             << endl;

        cin >> escolha;
        cin.ignore();

        system("CLS");

        switch (escolha)
        {
        case 1:
            break;
        case 2:
            emitirRelatorio();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        }
    } while (escolha != 5 );
}

int menuSetasPrincipal()
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

#endif 
