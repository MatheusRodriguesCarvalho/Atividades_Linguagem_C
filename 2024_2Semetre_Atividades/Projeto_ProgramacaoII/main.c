#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{ int eBomba; int estaAberta; int vizinhos; } tpCelula;

void gravarNomeJogador(char *nomeJogador)
{
    printf("Digite o seu nome: ");
    fflush(stdin);
    fgets(nomeJogador, 50, stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = '\0'; // remove o caractere de nova linha
}





void desenharCampo(tpCelula *Campo, int tamanho)
{
    //system("cls");
    printf("-  ");
    for(int i = 0; i<tamanho;i++)
    {
        if(i >= 10){ printf("%i",i); }
        else{ printf("%i ",i); }
    }
    printf("\n");

    for(int linha = 0; linha < tamanho; linha++)
    {
        if(linha>=10){printf("%i ",linha);}
        else{printf("%i  ",linha);}

        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if ((Campo + coluna + linha * tamanho)->estaAberta == 0)
            {
                printf("%c ", 254);
            }
            else
            {
                if ((Campo + coluna + linha * tamanho)->eBomba == 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("%i ", (Campo + coluna + linha * tamanho)->vizinhos);
                }
            }
        }
        printf("\n");
    }
}

int coordenadaEhValida(int linha, int coluna, int tamanho)
{
    return (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho);
}

int quantBombasVizinhas(tpCelula *Campo, int linha, int coluna, int tamanho)
{
    int quantidade = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(coordenadaEhValida(linha + i, coluna + j, tamanho) && (Campo + (coluna + j) + (linha + i) * tamanho)->eBomba)
            {
                quantidade++;
            }
        }
    }
    return quantidade;
}

// funcao para contar as bombas vizinhas
void contarBombas(tpCelula *Campo, int tamanho)
{
    printf("\n");
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            (Campo + coluna + linha * tamanho)->vizinhos = quantBombasVizinhas(Campo, linha, coluna, tamanho);
            //printf("(%i)", quantBombasVizinhas(Campo, linha, coluna, tamanho));
        }
        //getchar();
    }
}

void posicionarBombas(tpCelula *campo, int tamanho, int quantidadeBombas)
{
    srand(time(NULL));
    for(int i = 1; i <= quantidadeBombas; i++)
    {
        int linha = rand() % tamanho;
        int coluna = rand() % tamanho;
        if((campo + coluna + linha * tamanho)->eBomba == 0)
        {
            (campo + coluna + linha * tamanho)->eBomba = 1;
        }
        else
            i--;
    }
}

// funcao para inicializar a matriz do jogo
void inicializarJogo(tpCelula *campo, int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            (campo + coluna + linha * tamanho)->eBomba = 0;
            (campo + coluna + linha * tamanho)->estaAberta = 0;
            (campo + coluna + linha * tamanho)->vizinhos= 0;
        }
    }
}

void configurarCampo(int * tamanho, int * quantidadeBombas)
{
    char dificuldade;

    printf("\nSelecionar a Dificuldade...");
    do
    {
        printf("\nA - Facil (10x10, 20 Bombas)");
        printf("\nB - Medio (12x12, 30 Bombas)");
        printf("\nC - Dificil (15x15, 40 Bombas)");
        printf("\nDigite sua Escolha:");
        fflush(stdin);
        scanf("%c", &dificuldade);
        dificuldade = toupper(dificuldade);
        system("cls");
        //condicional
    }
    while (dificuldade != 'A' && dificuldade != 'B' && dificuldade != 'C');

    switch (dificuldade)
    {
    case 'A':
        *tamanho = 10;
        *quantidadeBombas = 20;
        break;
    case 'B':
        *tamanho  = 12;
        *quantidadeBombas = 30;
        break;
    case 'C':
        *tamanho  = 15;
        *quantidadeBombas = 40;
        break;
    }

}

void gameLoop(tpCelula *Campo, int tamanho)
{
    int lin, col;
    int continuar = 1;
    desenharCampo(Campo, tamanho);

    while(continuar)
    {
        do{
            printf("Digite a linha:");
            fflush(stdin);
            scanf("%i", &lin);
            printf("Digite a Coluna:");
            fflush(stdin);
            scanf("%i", &col);
            system("cls");
        } while( coordenadaEhValida(lin, col, tamanho) );

        fflush(stdin);
        if( coordenadaEhValida(lin, col, tamanho) )
        {
            if( (Campo + col + lin * tamanho)->eBomba == 0)
            {
                (Campo + col + lin * tamanho)->estaAberta = 1;
            }
            else if( (Campo + col + lin * tamanho)->estaAberta = 1 )
            {
                printf("Coordenada ja foi escolhida! informe outra coordenada.");
                getchar();
                system("cls");
            }
            else
            {
                printf("Voce pisou em uma Bomba. Fim de Jogo");
                continuar = 0;
                getchar();
            }
        }
        else
        {
            printf("Coordenada informada eh invalida!");
            getchar();
            //system("cls");
        }
    }
}

void jogar()
{
    char nomeJogador[50];

    int tamanho = 10;
    int quantidadeBombas = 0;
    configurarCampo(&tamanho, &quantidadeBombas);

    tpCelula Campo[tamanho][tamanho];

    gravarNomeJogador(nomeJogador);
    inicializarJogo(Campo, tamanho);
    posicionarBombas(Campo, tamanho, quantidadeBombas);
    contarBombas(Campo, tamanho);

    gameLoop(Campo, tamanho);

}

// Função para exibir as instruções do jogo
void exibirInstrucoes()
{
    printf("\nInstruções do Jogo:\n");
    printf("Haverá um determinado Numero de Bombas espalhadas pelo Campo.\n");
    printf("Seu objetivo eh Selecionar todas as calulas que nao possuirem bomba.\n");
    printf("Voce precisara escolher uma coordenada de linha e coluna para abrir a celula.\n");
    printf("Os numeros nas celulas abertas indicaram a quantidade de bombas nas celulas ao redor.\n\n");
}

void Menu()
{
    int opcao = 0;

    while (opcao != 3)
    {

        printf("\n---------------------------\n");
        printf("\n BEM VINDO AO CAMPO MINADO \n");
        printf("\n---------------------------\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Instrucoes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            jogar();
            break;
        case 2:
            exibirInstrucoes();
            break;
        case 3:
            printf("Saindo do jogo. Ate logo!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

int main()
{
    Menu();
    return 0;
}
