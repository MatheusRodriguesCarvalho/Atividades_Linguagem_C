#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int eBomba;
    int estaAberta;
    int vizinhos;
} tpCelula;

void gravarNomeJogador(char *nomeJogador)
{
    printf("Digite o seu nome: ");
    fgets(nomeJogador, 50, stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = '\0'; // remove o caractere de nova linha
}





void desenharCampo(tpCelula *Campo, int tamanho)
{
    system("cls");
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if ((Campo + coluna + linha * tamanho)->estaAberta == 0)
            {
                printf("%i", Campo->vizinhos);
            }
            else if ((Campo + coluna + linha * tamanho)->eBomba == 1)
            {
                printf("*");
            }
            else
            {
                printf("%c", 254);
            }

        }
        printf("\n");
    }
}





int coordenadaEhValida(int linha, int coluna, int tamanho){
    return (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho);
}

int quantBombasVizinhas(tpCelula *Campo, int linha, int coluna, int tamanho){
    int quantidade = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(coordenadaEhValida(linha + i, coluna + j, tamanho) && (Campo + (coluna + i) + (linha + j) * tamanho)->eBomba)
            {
                quantidade++;
            }
        }
    }
    return quantidade;
}


// funcao para contar as bombas vizinhas
void contarBombas(tpCelula *Campo, int tamanho){
    for(int linha = 0; linha < tamanho; linha++){
        for(int coluna = 0; coluna < tamanho; coluna++)
            (Campo + coluna + linha * tamanho)->vizinhos = quantBombasVizinhas(Campo, linha, coluna, tamanho);
            printf("(%i)", quantBombasVizinhas(Campo, linha, coluna, tamanho));
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

    desenharCampo(Campo, tamanho);

}

// Função para exibir as instruções do jogo
void exibirInstrucoes()
{
    printf("\nInstruções do Jogo:\n");
    printf("1. O objetivo é abrir todas as células que não têm bombas.\n");
    printf("2. Escolha uma célula digitando sua linha e coluna.\n");
    printf("3. Se abrir uma célula com uma bomba, você perde o jogo.\n");
    printf("4. Os números nas células indicam a quantidade de bombas nas células vizinhas.\n\n");
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
        printf("2. Instruções\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
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
