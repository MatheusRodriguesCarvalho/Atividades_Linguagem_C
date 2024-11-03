#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NOME 50

typedef struct{ int eBomba; int estaAberta; int vizinhos; } tpCelula;

typedef struct{ char nome[MAX_NOME]; int pontuacao; int jogadasRealizadas; }
tpJogador;


void limparJogador(tpJogador *j)
{

    for (int i = 0; i < MAX_NOME; i++)
    {
        j->nome[i] = '\0';
    }
    j->jogadasRealizadas = 0;
    j->pontuacao = 0;
}

void gravarNomeJogador(tpJogador *Jogador)
{
    printf("Digite o seu nome: ");
    fflush(stdin);
    fgets(Jogador->nome, MAX_NOME, stdin);
}

void fimDeJogo(tpCelula *Campo, int tamanho, int lin, int col)
{
    system("cls");
    mostrarBombas(Campo, tamanho);
    desenharCampo(Campo, tamanho);
    printf("\nHavia uma bomba na cordenada %ix%i\n", lin, col);
    printf("E voce pisou nela. Fim de Jogo\n");
}

//Gerando o relatorio em aruivo txt
void gerarRelarotio(int celulasRestantes, tpJogador *Jogador)
{
    int pontuacao = (200 - celulasRestantes) * Jogador->jogadasRealizadas;

    FILE *relatorio;
    relatorio = fopen("Relatorio.rlt", "wb");

    if(relatorio == NULL)
    {
        printf("\nNao foi possivel Gerar o Relatorio!");
    }
    else
    {
        printf("ok");
        fprintf(relatorio, "\nJogador: ");
        fwrite(Jogador->nome, MAX_NOME, 1, relatorio);
        fprintf(relatorio, "\nJogadas Realizadas:  ");
        fprintf(relatorio, "%i \n", Jogador->jogadasRealizadas);
        fprintf(relatorio, "\nPontuacao:  ");
        fprintf(relatorio, "%i \n", pontuacao);
        printf("ok2");

        fclose(relatorio);
    }

}

void desenharCampo(tpCelula *Campo, int tamanho)
{
    //system("cls");
    printf("\n-  ");
    for(int i = 0; i<tamanho;i++)
    {
        if(i >= 10){ printf("%i",i); }
        else{ printf("%i ",i); }
    }
    printf("\n\n");

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

void mostrarBombas(tpCelula *Campo, int tamanho)
{

    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if( (Campo + coluna + linha * tamanho)->eBomba)
            {
                (Campo + coluna + linha * tamanho)->estaAberta = 1;
            }
        }
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

void gameLoop(tpCelula *Campo, int tamanho, int quantidadeBombas)
{
    int lin, col;
    int continuar = 1;
    //algumas estatisticas
    int celulasRestantes = tamanho * tamanho - quantidadeBombas;
    tpJogador Jogador;
    limparJogador(&Jogador);
    
    while(continuar)
    {
        system("cls");
        desenharCampo(Campo, tamanho);
        printf("\nHa %i espacos livres.", celulasRestantes);
        printf("\nDigite a linha:");
        fflush(stdin);
        scanf("%i", &lin);
        printf("Digite a Coluna:");
        fflush(stdin);
        scanf("%i", &col);
        fflush(stdin);

        if( coordenadaEhValida(lin, col, tamanho) )
        {
            Jogador.jogadasRealizadas++;
            if( (Campo + col + lin * tamanho)->eBomba)
            {
                fimDeJogo(Campo, tamanho, lin, col);
                gravarNomeJogador(&Jogador);
                gerarRelarotio(celulasRestantes, &Jogador);

                continuar = 0;
                getchar();
                system("cls");
            }
            else
            {
                if( (Campo + col + lin * tamanho)->estaAberta)
                {
                    printf("\nCoordenada ja foi escolhida!");
                    printf("\nInforme outra coordenada.\n");
                    getchar();
                }
                else
                {
                    celulasRestantes--;
                    (Campo + col + lin * tamanho)->estaAberta = 1;
                }
            }
        }
        else
        {
            printf("Coordenada informada eh invalida!");
            getchar();
        }
    }
}

void jogar()
{

    int tamanho = 10;
    int quantidadeBombas = 0;
    configurarCampo(&tamanho, &quantidadeBombas);

    tpCelula Campo[tamanho][tamanho];

    inicializarJogo(Campo, tamanho);
    posicionarBombas(Campo, tamanho, quantidadeBombas);
    contarBombas(Campo, tamanho);

    gameLoop(Campo, tamanho, quantidadeBombas);

}

// Função para exibir as instruções do jogo
void exibirInstrucoes()
{
    system("cls");
    printf("\nInstruções do Jogo:\n");
    printf("Haverá um determinado Numero de Bombas espalhadas pelo Campo.\n");
    printf("Seu objetivo eh Selecionar todas as calulas que nao possuirem bomba.\n");
    printf("Voce precisara escolher uma coordenada de linha e coluna para abrir a celula.\n");
    printf("Os numeros nas celulas abertas indicaram a quantidade de bombas nas celulas ao redor.\n\n");
    getchar();
}

void Menu()
{
    int opcao = 0;

    while (opcao != 3)
    {
        system("cls");
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
