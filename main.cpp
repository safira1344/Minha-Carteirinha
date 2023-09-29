#include <iostream>
#include "gconio.h"
#include <windows.h>
#include "interface.h"
#include "Menu_setas.h"
#include "usuario.h"

using namespace std;

int main()
{
    Usuario *usuarios[MAX_USUARIOS];
    menu_principal(usuarios);
    // menu_setas_principal();
    getch();
    // tela_final();
    return 0;
}
