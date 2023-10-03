#include <iostream>
#include "gconio.h"
#include <windows.h>
#include "interface.h"
#include "Menu_setas.h"
#include "usuario.h"
#include <string.h>
#include <ctime>

#define MAX_GASTOS 10

using namespace std;

int main()
{
    Usuario *usuario = new Usuario;
    Gastos gastos[MAX_GASTOS];

    if (arquivoContemDados())
    {
        importarUsuarioDoArquivo(usuario);

        cout << "Bem Vindo(a) " << usuario->nome << endl;
        cout << "Por favor digite sua senha para acessar a sua carteirinha!" << endl;
        cout << "Esqueceu sua senha?" << endl;
        cout << "Digite 00 caso tenha esquecido sua senha" << endl;

        string opcao;

        while (true)
        {
            getline(cin, opcao);
            if (opcao == "00")  //passível a modificações
            {
                cadastrarUsuario(usuario);
                system("CLS");
                break;
            }
            else
            {
                if (usuario->senha == opcao)
                {
                    system("CLS");
                    cout << "Logado com sucesso. Utilize a sua carteirinha a vontade!" << endl;
                    break;
                }
                else
                {
                    system("CLS");
                    cout << "Senha incorreta! Digite sua senha novamente. Digite 00 caso tenha esquecido sua senha" << endl;
                    continue;
                }
            }
        }
    }
    else
    {
        cadastrarUsuario(usuario);
    }

    

    menu_principal(usuario, gastos);
    // menu_setas_principal();

    getch();
    // tela_final();

    delete usuario;

    return 0;
}
