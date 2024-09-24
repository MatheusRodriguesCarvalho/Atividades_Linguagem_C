#include <stdio.h>
#include <stdlib.h>

#define MAP_SPACE ' '
#define MAX_LINHA 20
#define MAX_COLUNA 20


int main(void)
{
    game_loop();
}

void game_loop ()
{

    char jogo;
    while(jogo != 'x') //DO{}WHILE()
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
            //texto_sair();
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
    printf("Jogando\n\n");
    //texto_introducao();

    struct iJogador{
        int vidaCorrente;
        int vidaMaxima;
        int forca;
        char escolha;
    };

    struct iJogador teste;

    char jogo_mapa[MAX_COLUNA][MAX_LINHA];
    int mapa_coluna = 30, mapa_linha = 8;

    mapa_definir(&jogo_mapa, mapa_linha, mapa_coluna);
    mapa_desenhar(&jogo_mapa, mapa_linha, mapa_coluna);

    jogador_movimentacao(&teste.escolha);

    printf("escolha foi: %c", teste.escolha);


}

void game_tutorial()
{
    printf("Tutoriando");
}

void game_outros()
{
    printf("Outrando");
}
