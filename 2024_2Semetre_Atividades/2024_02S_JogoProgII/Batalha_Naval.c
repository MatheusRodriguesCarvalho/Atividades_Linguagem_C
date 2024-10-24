#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*

IFORMAÇÃO DOS BARCOS

1. VETOR:

n = ??; //varia de acordo com a dificuldade
tpEmbarcacao Barcos_Player[n];
tpEmbarcacao Barcos_Enemy[n];

funcaoQueDivideAQuantidadeDeBarcosParaCadaUm();
funcaoQuePermitePersonalizarAQuantidade()

*/

typedef struct {int x; int y; int tamanho; char orientacao; } tpEmbacacao;

void GerarArquivo(tpEmbacacao *teste)
{
    FILE * arq;

    arq = fopen("barcos_jogador.emb", "a");

    if ( arq == NULL)
    {
        printf("Arquivo nao criado / salvo");
    } else
    {
        fwrite(&teste, sizeof(tpEmbacacao), 1, arq);
        fclose(arq);
    }


}

void GerarEmbarcacoes(int QuantidadeBarcos, char *Jogador, char *Inimigo, int tamanho)
{
    tpEmbacacao BarcosJogador[QuantidadeBarcos];
    tpEmbacacao BarcosInimigo[QuantidadeBarcos];

    for(int i = 0; i < QuantidadeBarcos; i++)
    {

        int x = 1;
        x = (i + 1) % 3;

        switch(x)
        {
        case 1:
            printf("\nembarcacao pequena");
            BarcosJogador[i].tamanho = 1;
            break;
        case 2:
            printf("\nembarcacao media");
            BarcosJogador[i].tamanho = 3;
            break;
        case 0:
            printf("\nembarcacao grande");
            BarcosJogador[i].tamanho = 5;
            break;
        }
    }

    GerarArquivo(BarcosJogador);
}

void GerarMapa(char metodo, char dificuldade)
{
    int tamanho = 0, QuantidadeBarcos  = 0;
    switch (dificuldade)
    {
    case 'A':
        tamanho = 7;
        QuantidadeBarcos = 3;
        break;
    case 'B':
        tamanho = 11;
        QuantidadeBarcos = 5;
        break;
    case 'C':
        tamanho = 15;
        QuantidadeBarcos = 8;
        break;
    }
    char MapaJogador[tamanho][tamanho];
    char MapaInimigo[tamanho][tamanho];

    GerarEmbarcacoes(QuantidadeBarcos, MapaJogador, MapaInimigo, tamanho);

}

void Configurar()
{
    char alocacao, dificuldade;

    printf("\nRealocando as posisoes dos Navios...");
    do{
        printf("\nDeseja Aloacar Manualmente (M) ou Automaticamente (A)?");
        fflush(stdin);
        scanf("%c", &alocacao);
        alocacao = toupper(alocacao);
        system("cls");
        //condicional
    }while (alocacao != 'M' && alocacao != 'A');
    do{
        printf("\nA - Facil (7x7, 3 Barcos)");
        printf("\nB - Medio (11x11, 5 Barcos)");
        printf("\nC - Dificil (15x15, 8 Barcos)");
        printf("\nZ - Detalhamento...");
        printf("\nEscolha a Difiuldade:");
        fflush(stdin);
        scanf("%C", &dificuldade);
        dificuldade = toupper(dificuldade);
        system("cls");
        //condicional
    }while (dificuldade != 'A' && dificuldade != 'B' && dificuldade != 'C');

    GerarMapa(alocacao, dificuldade);

}
void Menu()
{
    int opcao = 0;
    while(opcao != 4)
    {
        system("cls");
        printf("\n+-- Batalha Naval --+\n");
        printf("\n1 - Configurar");
        printf("\n2 - Jogar");
        printf("\n3 - Como Jogar");
        printf("\n4 - Sair");

        printf("\nDigite o numero da Opcao:");
        fflush(stdin);
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1:
            Configurar();
            break;
        case 2:
            //funcao
            break;
        case 3:
            //funcao
            break;
        case 4:
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
        fflush(stdin);
        getchar();
    }
}
int main (void)
{
    Menu();
    return 0;
}
