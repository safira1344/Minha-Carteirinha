#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void moldurinha(int l, int m, int x, int y, int colorFundo, int colorMoldura);
void retangulos(int color, int x, int y, int l, int c);
void tela_incial();

using namespace std;

void cabecalho()
{
    moldurinha(0,155,0,39,MAGENTA,WHITE);

    moldurinha(30,120,8,30,WHITE, BLACK);

    gotoxy(55, 10);
    cout<<"   ___          _           _   ";
    gotoxy(55, 11);
    cout<<"  / __\\__ _  __| | __ _ ___| |_ _ __ ___ ";
    gotoxy(55, 12);
    cout<<" / /  / _` |/ _` |/ _` / __| __| '__/ _ \\ ";
    gotoxy(55, 13);
    cout<<"/ /__| (_| | (_| | (_| \__ \\  |_| | | (_) |";
    gotoxy(55, 14);
    cout<<"\\____/\\__,_|\\__,_|\__,_|___/\\___|_|  \\___/";
}

void tela_incial()
{
    textbackground(MAGENTA);
    system("cls");
    moldurinha(0,155,0,39, MAGENTA, WHITE);

    gotoxy(45,9);
    cout <<" _           _  _  _  _  _           _  _           _        _  ";
    gotoxy(45,10);
    cout <<"(_) _     _ (_)(_)(_)(_)(_) _       (_)(_)         (_)     _(_)_     ";
    gotoxy(45,11);
    cout << "(_)(_)   (_)(_)   (_)   (_)(_)_     (_)(_)         (_)   _(_) (_)_   ";
    gotoxy(45,12);
    cout <<"(_) (_)_(_) (_)   (_)   (_)  (_)_   (_)(_) _  _  _ (_) _(_)     (_)_ ";
    gotoxy(45,13);
    cout <<"(_)   (_)   (_)   (_)   (_)    (_)_ (_)(_)(_)(_)(_)(_)(_) _  _  _ (_)";
    gotoxy(45,14);
    cout <<"(_)         (_)   (_)   (_)      (_)(_)(_)         (_)(_)(_)(_)(_)(_)";
    gotoxy(45,15);
    cout <<"(_)         (_) _ (_) _ (_)         (_)(_)         (_)(_)         (_)";
    gotoxy(45,16);
    cout <<"(_)         (_)(_)(_)(_)(_)         (_)(_)         (_)(_)         (_)";

    gotoxy(2,19);
    cout<<"   _  _  _            _        _  _  _  _    _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _     _  _  _  _           _  _           _        _  ";
    gotoxy(2,20);
    cout<<" _(_)(_)(_)  _      _(_)_     (_)(_)(_)(_) _(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_) _ (_)(_)(_)(_) _       (_)(_)         (_)     _(_)_   ";
    gotoxy(2,21);
    cout<<"(_)         (_)   _(_) (_)_   (_)         (_)     (_)      (_)               (_)   (_)         (_)   (_)   (_)(_)_     (_)(_)         (_)   _(_) (_)_  ";
    gotoxy(2,22);
    cout<<"(_)             _(_)     (_)_ (_) _  _  _ (_)     (_)      (_) _  _          (_)   (_) _  _  _ (_)   (_)   (_)  (_)_   (_)(_) _  _  _ (_) _(_)     (_)_ ";
    gotoxy(2,23);
    cout<<"(_)            (_) _  _  _ (_)(_)(_)(_)(_)        (_)      (_)(_)(_)         (_)   (_)(_)(_)(_)      (_)   (_)    (_)_ (_)(_)(_)(_)(_)(_)(_) _  _  _ (_)";
    gotoxy(2,24);
    cout<<"(_)          _ (_)(_)(_)(_)(_)(_)   (_) _         (_)      (_)               (_)   (_)   (_) _       (_)   (_)      (_)(_)(_)         (_)(_)(_)(_)(_)(_)";
    gotoxy(2,25);
    cout<<"(_) _  _  _ (_)(_)         (_)(_)      (_) _      (_)      (_) _  _  _  _  _ (_) _ (_)      (_) _  _ (_) _ (_)         (_)(_)         (_)(_)         (_)";
    gotoxy(2,26);
    cout<<"   (_)(_)(_)   (_)         (_)(_)         (_)     (_)      (_)(_)(_)(_)(_)(_)(_)(_)(_)         (_)(_)(_)(_)(_)         (_)(_)         (_)(_)         (_)";



}

void confirmar()
{
    int chave = 0;
    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(70,29);
    cout << "PRESSIONE ENTER";
    while(chave!=224 && chave!=13)
    {
        gotoxy(70,30);
        textbackground(MAGENTA);
        std :: cout <<"            ";
        gotoxy(70,30);
        chave = getch();
    }
}


void perfumaria_menu_principal(int cor)//tururu
{
    SetConsoleOutputCP(65001); // para permitir acentuação

    gotoxy(66, 14);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "VER MINHA CARTEIRINHA";

    gotoxy(72, 19);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "RELATÓRIO";

    gotoxy(71, 24);
    textbackground(cor);
    textcolor(BLACK);
    cout << "NOTIFICAÇÕES";

    gotoxy(71, 29);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "MEU PERFIL";

    gotoxy(74, 34);
    textbackground(WHITE);
    textcolor(BLACK);
    cout << "SAIR";
}

void perfumariaMenuPerfil()
{
    SetConsoleOutputCP(65001); // para permitir acentuação

    gotoxy(64,24);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"ATUALIZAR USUÁRIO E SENHA";
    gotoxy(70,29);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"APAGAR USUÁRIO";
    gotoxy(74,34);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"VOLTAR";
}

void perfumariaMenuCarteirinha()
{
    gotoxy(70,24);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"EDITAR DADOS";
    gotoxy(69,29);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"ADICIONAR DADOS";
    gotoxy(74,34);
    textbackground(WHITE);
    textcolor(BLACK);
    cout<<"VOLTAR";

}

void interfaceMenuSecundario()
{
    moldurinha(0, 155, 0, 39, MAGENTA, WHITE);

    retangulos(BLACK, 52, 24, 3, 50);
    retangulos(WHITE, 51, 23, 3, 50);

    retangulos(BLACK, 52, 29, 3, 50);
    retangulos(WHITE, 51, 28, 3, 50);

    retangulos(BLACK, 52, 34, 3, 50);
    retangulos(WHITE, 51, 33, 3, 50);
}

void interface_menu(int n)
{

    moldurinha(0, 155, 0, 39, MAGENTA, WHITE);

    retangulos(BLACK, 52, 14, 3, 50);
    retangulos(WHITE, 51, 13, 3, 50);

    retangulos(BLACK, 52, 19, 3, 50);  // sombra do retângulo
    retangulos(WHITE, 51, 18, 3, 50); // retângulo branco

    retangulos(BLACK, 52, 24, 3, 50);
    retangulos(n, 51, 23, 3, 50);

    retangulos(BLACK, 52, 29, 3, 50);
    retangulos(WHITE, 51, 28, 3, 50);

    retangulos(BLACK, 52, 34, 3, 50);
    retangulos(WHITE, 51, 33, 3, 50);
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

void moldurinha(int l, int m, int x, int y, int colorFundo, int colorMoldura)
{
    // Configura o console para modo de saída de caractere estendido
    SetConsoleOutputCP(437);
    int i, j;
    textbackground(colorFundo);
    for (i = x + 1; i < y; i++)
    {
        gotoxy(l + 1, i);
        for (j = l + 1; j < m; j++)
            cout << " ";
    }
    textcolor(colorMoldura);
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
