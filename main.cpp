#include <iostream>
#include "gconio.h"
#include <windows.h>
#include "interface.h"
#include "Menu_setas.h"
#include "usuario.h"

using namespace std;

int main()
{
    Usuario *usuario = new Usuario;
    menu_principal(usuario);
    // menu_setas_principal();
    getch();
    // tela_final();
    return 0;
}
