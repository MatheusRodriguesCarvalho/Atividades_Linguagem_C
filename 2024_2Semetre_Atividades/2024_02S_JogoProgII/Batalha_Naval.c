#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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

void GerarArquivo()
{
    //a
}

void GerarEmbarcacoes(int QuantidadeBarcos, char *Jogador, char *Inimigo)
{




    tpEmbacacao BarcosJogador[QuantidadeBarcos];
    tpEmbacacao BarcosInimigo[QuantidadeBarcos];



    GerarArquivo(&BarcosJogador, &BarcosInimigo);
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
        tamanho = 7;
        QuantidadeBarcos = 3;
        break;
    case 'C':
        tamanho = 7;
        QuantidadeBarcos = 3;
        break;
    }
    char MapaJogador[tamanho][tamanho];
    char MapaInimigo[tamanho][tamanho];

    GerarEmbarcacoes(QuantidadeBarcos, MapaJogador, MapaInimigo);

}

void Configurar()
{
    char alocacao, dificuldade;

    printf("\nRealocando as posisoes dos Navios...");
    do{
        printf("\nDeseja Aloacar Manualmente (M) ou Automaticamente (A)?");
        fflush(stdin);
        scanf("%c", &alocacao);
        alocacao = Toupper(alocacao);
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
        dificuldade = Toupper(dificuldade);
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
