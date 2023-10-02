#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void moldurinha(int l, int m, int x, int y);
void retangulos(int color, int x, int y, int l, int c);

using namespace std;

void tela_incial()
{
    textbackground(MAGENTA);
    system("cls");
    moldurinha(0,155,0,39);


    gotoxy(43,4);
    cout << "       *****   **    **                          *  ";
    gotoxy(43,5);
    cout << "  ******  ***** *****     *                  **                  ";
    gotoxy(43,6);
    cout << " **   *  *  ***** *****  ***                 **                  ";
    gotoxy(43,7);
    cout << "*    *  *   * **  * **    *                  **                  ";
    gotoxy(43,8);
    cout << "    *  *    *     *                          **                  ";
    gotoxy(43,9);
    cout << "   ** **    *     *     ***     ***  ****    **  ***      ****   ";
    gotoxy(43,10);
    cout << "   ** **    *     *      ***     **** **** * ** * ***    * ***  *";
    gotoxy(43,11);
    cout << "   ** **    *     *       **      **   ****  ***   ***  *   **** ";
    gotoxy(43,12);
    cout << "   ** **    *     *       **      **    **   **     ** **    **  ";
    gotoxy(43,12);
    cout << "   ** **    *     **      **      **    **   **     ** **    **  ";
    gotoxy(43,13);
    cout << "   *  **    *     **      **      **    **   **     ** **    **  ";
    gotoxy(43,14);
    cout << "      *     *      **     **      **    **   **     ** **    **  ";
    gotoxy(43,14);
    cout << "  ****      *      **     **      **    **   **     ** **    **  ";
    gotoxy(43,15);
    cout << " *  *****           **    *** *   ***   ***  **     **  ***** ** ";
    gotoxy(43,16);
    cout << "*     **                   ***     ***   ***  **    **   ***   **";
    gotoxy(43,17);
    cout << "*                                                   *            ";
    gotoxy(43,18);
    cout << "**                                                *             ";
    gotoxy(43,19);
    cout << "                                                  *              ";
    gotoxy(43,20);
    cout << "                                                 *               ";


    gotoxy(16,22);
    cout << "      * ***                                                                                            *  ";
    gotoxy(16,23);
    cout << "    *  ****  *                             *                 *                    *                  **   ";
    gotoxy(16,24);
    cout << "   *  *  ****                             **                ***                  ***                 **    ";
    gotoxy(16,23);
    cout << "  *  **   **                              **                 *                    *                  **    ";
    gotoxy(16,24);
    cout << " *  ***                   ***  ****     ********                   ***  ****                         **   ";
    gotoxy(16,25);
    cout << "**   **           ****     **** **** * ********     ***    ***      **** **** * ***     ***  ****    **  ***      ****   ";
    gotoxy(16,26);
    cout << "**   **          * ***  *   **   ****     **       * ***    ***      **   ****   ***     **** **** * ** * ***    * ***  *";
    gotoxy(16,27);
    cout << "**   **         *   ****    **            **      *   ***    **      **           **      **   ****  ***   ***  *   **** ";
    gotoxy(16,28);
    cout << "**   **        **    **     **            **     **    ***   **      **           **      **    **   **     ** **    **  ";
    gotoxy(16,29);
    cout << "**   **        **    **     **            **     ********    **      **           **      **    **   **     ** **    **  ";
    gotoxy(16,30);
    cout << " **  **        **    **     **            **     *******     **      **           **      **    **   **     ** **    **  ";
    gotoxy(16,31);
    cout << "  ** *      *  **    **     **            **     **          **      **           **      **    **   **     ** **    **  ";
    gotoxy(16,32);
    cout << "   ***     *   **    **     ***           **     ****    *   **      ***          **      **    **   **     ** **    **  ";
    gotoxy(16,33);
    cout << "    *******     ***** **     ***           **     *******    *** *    ***         *** *   ***   ***  **     **  ***** ** ";
    gotoxy(16,34);
    cout << "      ***        ***   **                          *****      ***                  ***     ***   ***  **    **   ***   **";
    gotoxy(16,34);
    cout << "                                                                                                            *           ";
    gotoxy(16,35);
    cout << "                                                                                                           *         ";
    gotoxy(16,36);
    cout << "                                                                                                         *           ";
    gotoxy(16,37);
    cout << "                                                                                                         *         ";


}


void perfumaria_menu_principal()//tururu
{
    gotoxy(67, 19);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "ATUALIZAR CADASTRO";

    gotoxy(72, 24);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "RELATÓRIO";

    gotoxy(72, 29);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "MENSAGENS";

    gotoxy(74, 34);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "SAIR";
}
void interface_menu()
{
    moldurinha(0, 155, 0, 39);

    SetConsoleOutputCP(65001); // para permitir acentuação

    retangulos(0, 52, 19, 3, 50);  // sombra do retângulo
    retangulos(15, 51, 18, 3, 50); // retângulo branco

    retangulos(0, 52, 24, 3, 50);
    retangulos(15, 51, 23, 3, 50);

    retangulos(0, 52, 29, 3, 50);
    retangulos(15, 51, 28, 3, 50);

    retangulos(0, 52, 34, 3, 50);
    retangulos(15, 51, 33, 3, 50);
}

void retangulos(int color, int x, int y, int l, int c)
{
    int i, j;
    textbackground(color);
    for (i = 0; i < l; i++)
    {
        gotoxy(x, y + i);
        for (j = 0; j < c; j++)
        {
            std ::cout << " ";
        }
    }
}

void moldurinha(int l, int m, int x, int y)
{
    // Configura o console para modo de saída de caractere estendido
    SetConsoleOutputCP(437);
    int i, j;
    textbackground(MAGENTA);
    for (i = x + 1; i < y; i++)
    {
        gotoxy(l + 1, i);
        for (j = l + 1; j < m; j++)
            cout << " ";
    }
    textcolor(WHITE);
    gotoxy(l, x);
    cout << char(201); // caracter ╔
    gotoxy(m, x);
    cout << char(187); // caracter ╗
    gotoxy(l, y);
    cout << char(200);
    gotoxy(m, y);
    cout << char(188);
    for (int linha = x + 1; linha < y; linha++)
    {
        gotoxy(l, linha);
        cout << char(186); // caracter ║
        gotoxy(m, linha);
        cout << char(186);
    }
    for (int coluna = l + 1; coluna < m; coluna++)
    {
        gotoxy(coluna, x);
        cout << char(205); // caracter ═
        gotoxy(coluna, y);
        cout << char(205);
    }
}

void tela_final()
{

    textbackground(LIGHTMAGENTA);
    system("cls");
    gotoxy(21, 5);
    cout << " _____   _____ _____     ___    _ ______ _____ ";
    gotoxy(21, 6);
    cout << "|  __ \\ / ____|_   _|   / / |  | |  ____/ ____|";
    gotoxy(21, 7);
    cout << "| |  | | (___   | |    / /| |  | | |__ | (___  ";
    gotoxy(21, 8);
    cout << "| |  | |\\___ \\  | |   / / | |  | |  __| \\___ \\ ";
    gotoxy(21, 9);
    cout << "| |__| |____) |_| |_ / /  | |__| | |    ____) |";
    gotoxy(21, 10);
    cout << "|_____/|_____/|_____/_/    \\____/|_|   |_____/ ";

    gotoxy(33, 14);
    cout << "|VOLTE LOGO!!!|";

    gotoxy(10, 17);
    exit(0);
}

#endif // INTERFACE_H_INCLUDED
