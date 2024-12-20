#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//#define oceano '#'
//#define barco '*'

/*

BATALHA NAVAL...


CAMPO MINADO??

(jogo de advinhacao, onde ha uma pessoa com caracteristicas predefinidas [olhos, cabelos, roupa...]
 e voce deve advinhar todas as caracteristicas

 estilo purple place
 )

IFORMAÇÃO DOS BARCOS

1. VETOR:

n = ??; //varia de acordo com a dificuldade
tpEmbarcacao Barcos_Player[n];
tpEmbarcacao Barcos_Enemy[n];

funcaoQueDivideAQuantidadeDeBarcosParaCadaUm();
funcaoQuePermitePersonalizarAQuantidade()

*/

typedef struct {int x; int y; int tamanho; char orientacao; } tpEmbacacao;

void GerarArquivoMapa(char *mapa)
{

}

void DesenharMapa(char *MapaJogador, int Dimensao)
{
    printf("\n");
    for(int i = 0; i < Dimensao; i++)
    {
        for(int j = 0; j < Dimensao; j++)
        {
            printf("%c", *(MapaJogador++));
        }
        printf("\n");
    }
}
//--------------------------------------------------------------------------------------------------
void PosicionarEmbarcaoes(char *MapaJogador, tpEmbacacao *Barcos, int QuantidadeBarcos, int Dimensao)
{
    //logica para alocar os barcos nos locais adequados, corrigindo erros e mostrando na tela o mapa
    int cont = QuantidadeBarcos;
    int x = 0, y = 0;

    for(int linha = 0; linha < Dimensao; linha++) //Define todas as regioes do mapa como Oceano
    {
        for(int coluna = 0; coluna < Dimensao; coluna++)
        {
            *(MapaJogador + linha * Dimensao + coluna) = '#';
        }
    }

    while(cont > 0)//enquanto todos os barcos nao forem posicionados adequadamente, noao sai do loop
    {

        DesenharMapa(MapaJogador, Dimensao);
        // depois vai pegar e ler o arquivo, e pegar as das informacoes de uma embarcacao
        reposicionar:
        do{
            printf("\nDigite a coordenada da Linha (1 -> %i): ", Dimensao);
            scanf("%i", &y);
            printf("\nDigite a coordenada da Coluna (1 -> %i): ", Dimensao);
            scanf("%i", &x);
            system("cls");
            if(x > Dimensao || y > Dimensao)
            {
                printf("Valor invalido. Digite novamente!\n");
            }
        }while(x > Dimensao || y > Dimensao);
        
        //Orientacao (vertical / horizontal)


        *(MapaJogador + (y-1) * Dimensao + (x-1)) = 'O';
        //posicao real relativa a percepsao do jogador, "linha 1" para ele, eh a linha 0 pode coiso aqui

        cont--;

    }

}
//--------------------------------------------------------------------------------------------------
void GerarArquivoBarcos(tpEmbacacao *barcos)
{
    FILE * arq;

    arq = fopen("\nza_Listagem_embarcacoes.emb", "wr");

    if ( arq == NULL)
    {
        printf("\nArquivo nao criado / salvo");
    }
    else
    {
        fwrite(barcos, sizeof(tpEmbacacao), 1, arq);
        fclose(arq);
    }
}
//--------------------------------------------------------------------------------------------------
void GerarEmbarcacoes(int QuantidadeBarcos, char *MapaJogador, int Dimensao)
{
    tpEmbacacao BarcosJogador[QuantidadeBarcos];

    printf("\nListagem dos Navios:");
    for(int i = 0; i < QuantidadeBarcos; i++)
    {
        int x = (i + 1) % 3;
        switch(x) // separando os tipos de barcos que haverao no jogo
        {
        case 1:
            printf("\n Embarcacao pequena (1x1)");
            BarcosJogador[i].tamanho = 1;
            break;
        case 2:
            printf("\n Embarcacao media (1x3)");
            BarcosJogador[i].tamanho = 3;
            break;
        case 0:
            printf("\n Embarcacao grande (1x5)");
            BarcosJogador[i].tamanho = 5;
            break;
        }
    }
    //GerarArquivoBarcos(BarcosJogador);
    PosicionarEmbarcaoes(MapaJogador, BarcosJogador, QuantidadeBarcos, Dimensao);
}
//--------------------------------------------------------------------------------------------------
void GerarMapa(char dificuldade)
{
    int Dimensao = 0, QuantidadeBarcos = 0;

    switch (dificuldade)
    {
    case 'A':
        Dimensao = 7;
        QuantidadeBarcos = 3;
        break;
    case 'B':
        Dimensao = 11;
        QuantidadeBarcos = 5;
        break;
    case 'C':
        Dimensao = 15;
        QuantidadeBarcos = 8;
        break;
    }

    char MapaJogador[Dimensao][Dimensao];

    GerarEmbarcacoes(QuantidadeBarcos, MapaJogador, Dimensao);
    GerarArquivoMapa(MapaJogador);

}
//--------------------------------------------------------------------------------------------------
void Configurar()
{
    char dificuldade;

    printf("\nRealocando as posisoes dos Navios...");
    do{
        printf("\nA - Facil (7x7, 3 Barcos)");
        printf("\nB - Medio (11x11, 5 Barcos)");
        printf("\nC - Dificil (15x15, 8 Barcos)");
        printf("\nEscolha a Difiuldade:");
        fflush(stdin);
        scanf("%c", &dificuldade);
        dificuldade = toupper(dificuldade);
        system("cls");
        //condicional
    }while (dificuldade != 'A' && dificuldade != 'B' && dificuldade != 'C');

    GerarMapa(dificuldade);

}



void LerArquivo()
{

}

void ImportarMapa(char *mapa, int tamanho)
{
    FILE *arq;
    arq = fopen("Mapa_embarcacoes.emb", "rb");

    if(arq == NULL)
    {
        printf("\nArquivo do mapa nao foi importado");
    }
    else
    {
        LerArquivo();
        fclose(arq);
    }
}

void Jogar()
{

    int tamanho = 7;
    char mapa[tamanho][tamanho];

    //ImportarMapa(mapa, tamanho);

    /*
    TO DO
    game loop onde:
        mostra o mapa do inimigo (uma 1a vez)
        pergunta ao jogador onde ele quer escolher
        torna a mostrar o mapa do inimigo, onde foi atirado

        //turno do inimigo
        mostra onde ele mirou e o seu mapa
            criar "logica" ou criterios para o inimigo
    */




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
            Jogar();
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
