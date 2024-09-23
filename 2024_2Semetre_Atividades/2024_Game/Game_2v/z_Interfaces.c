#include <stdio.h>
#include <stdlib.h>
#include<windows.h>


void tela_limpar () //Limpa a tela
{
  system("cls");
}

void tela_pausar () //Pausa a tela
{
    system("Pause");
}

void texto_introducao () //Apresenta o contexto do jogo
{
    printf ("\nBusque pelo artefato, perdido no subsolo...\n");
    sleep(1);
    printf ("\nDesca os niveis...\n");
    sleep(1);
    printf ("\nEvite os inimigos, ou nao...\n");
    sleep(1);
    printf ("\nChegue no final...\n");
    sleep(1);
    tela_limpar ();
}

void texto_sair () //Apresenta o contexto do jogo
{
    printf ("\nEntao se vire...\n");
    sleep(1);
    printf ("\nE nao retorne...\n");
}

void texto_desistir () //Apresenta o contexto do jogo
{
    printf ("\nNunca foi para ser...\n");
    sleep(1);
}


void menu ()
{
    printf("---------------------------\n");
    printf("          Fightgeon        \n");
    printf("---------------------------\n");
    printf("                           \n");
    printf("          1 - Jogar \n");
    printf("           2 - Manual \n");
    printf("           3 - Outros \n");
    printf("          x - Sair \n\n");
    printf("Selecione sua opcao: ");
}
