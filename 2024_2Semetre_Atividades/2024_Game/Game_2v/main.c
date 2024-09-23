#include <stdio.h>
#include <stdlib.h>

#define MAP_SPACE ' '


int main(void)
{
    game_loop();
}

void game_loop ()
{

    char jogo;
    while(jogo != 'x')
    {
        menu();
        fflush(stdin);
        jogo = tolower(getchar());
        tela_limpar();

        switch (jogo)
        {
        case '1':
            game_jogar();
            break;
        case '2':
            game_tutorial();
            break;
        case '3':
            game_outros();
            break;
        case 'x':
            texto_sair();
            break;
        default:
            printf("Opcao invalida.");
            break;
        }
        printf("\n");
        tela_pausar();
        tela_limpar();
    }
}


void game_jogar()
{
    printf("Jogando");
    texto_introducao();
}

void game_tutorial()
{
    printf("Tutoriando");
}

void game_outros()
{
    printf("Outrando");
}
