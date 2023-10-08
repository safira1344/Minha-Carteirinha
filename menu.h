#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// seta cima = 72
/// direita = 77
/// esqueda = 75
/// baixo = 80
/// ESC   = 27

int menuSetasSecundario(int identificaMenu);
int menuSetasPrincipal(int cor);

void menuCarteirinha()
{
    int op;
    do
    {
        op = menuSetasSecundario(1);
        switch (op)
        {
        case 1:
            break;
        case 2:
            // atualizarDadosCarteirinha();
            break;
        }
    } while (op != 3);
}

void menuPerfil()
{
    int op;
    do
    {
        op = menuSetasSecundario(0);
        switch (op)
        {
        case 1:
            // Aqui chamar a função de atualizar usuário e senha;
            break;
        case 2:
            // Aqui chamar a função de apagar usuario;
            break;
        }
    } while (op != 3);
}

void menuPrincipal()
{
    int escolha, color;
    color = notificacao();

    do
    {
        escolha = menuSetasPrincipal(color);
        switch (escolha)
        {
        case 1:
            menuSetasSecundario(true);
            break;
        case 2:
            emitirRelatorio();
            break;
        case 3:
            cout << "teste";
            break;
        case 4:
            menuSetasSecundario(false);
            break;
        }
    } while (escolha != 5);
}

int menuSetasPrincipal(int cor)
{
    interface_menu(cor);
    perfumaria_menu_principal(cor);

    int escolha, enter = 1, linha = 14, aux = 14;

    do
    {
        escolha = getch();
        switch (escolha)
        {
        case 13:
            return enter;
        case 80:
            if (linha < 34)
            {
                linha += 5;
                if (linha == 24 && cor == RED)
                {
                    retangulos(MAGENTA, 52, linha, 3, 50);
                    retangulos(RED, 51, linha - 1, 3, 50);
                }
                else
                {
                    retangulos(MAGENTA, 52, linha, 3, 50);
                    retangulos(WHITE, 51, linha - 1, 3, 50);
                }

                if (aux == 24 && cor == RED)
                {
                    retangulos(0, 52, aux, 3, 50);
                    retangulos(RED, 51, aux - 1, 3, 50);
                }
                else
                {
                    retangulos(0, 52, aux, 3, 50);
                    retangulos(WHITE, 51, aux - 1, 3, 50);
                }
                enter++;
            }
            break;
        case 72:
            if (linha > 14)
            {
                linha -= 5;
                if (linha == 24 && cor == RED)
                {
                    retangulos(MAGENTA, 52, linha, 3, 50);
                    retangulos(RED, 51, linha - 1, 3, 50);
                }
                else
                {
                    retangulos(MAGENTA, 52, linha, 3, 50);
                    retangulos(WHITE, 51, linha - 1, 3, 50);
                }
                if (aux == 24 && cor == RED)
                {
                    retangulos(0, 52, aux, 3, 50);
                    retangulos(RED, 51, aux - 1, 3, 50);
                }
                else
                {
                    retangulos(0, 52, aux, 3, 50);
                    retangulos(WHITE, 51, aux - 1, 3, 50);
                }

                enter--;
            }
            break;
        }
        perfumaria_menu_principal(cor);
        aux = linha;
    } while (escolha != 27);
    enter = 4;
    return enter;
}

int menuSetasSecundario(bool identificaMenu)
{
    int escolha, enter = 1, linha = 24, aux = 24;

    interfaceMenuSecundario();

    if (identificaMenu)
    {
        perfumariaMenuCarteirinha();
    }
    else
    {
        perfumariaMenuPerfil();
    }

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
                retangulos(WHITE, 51, linha - 1, 3, 50);

                retangulos(0, 52, aux, 3, 50);
                retangulos(WHITE, 51, aux - 1, 3, 50);

                enter++;
            }
            break;
        case 72:
            if (linha > 24)
            {
                linha -= 5;

                retangulos(MAGENTA, 52, linha, 3, 50);
                retangulos(WHITE, 51, linha - 1, 3, 50);

                retangulos(0, 52, aux, 3, 50);
                retangulos(WHITE, 51, aux - 1, 3, 50);

                enter--;
            }
            break;
        }

        if (identificaMenu)
        {
            perfumariaMenuCarteirinha();
        }
        else
        {
            perfumariaMenuPerfil();
        }

        aux = linha;
    } while (escolha != 27);

    enter = 3;

    return enter;
}

#endif
