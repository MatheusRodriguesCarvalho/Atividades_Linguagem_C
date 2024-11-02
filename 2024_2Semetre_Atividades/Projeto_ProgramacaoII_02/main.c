#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
} Celula;

void solicitarNomeJogador(char *nomeJogador) {
    printf("Digite o seu nome: ");
    fgets(nomeJogador, 50, stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = '\0'; // remove o caractere de nova linha
}

// funcao para inicializar a matriz do jogo
void inicializarJogo(Celula jogo[10][10], int tam){
    for(int l = 0; l < tam; l++){
        for(int c = 0; c < tam; c++){
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}

// funcao sortear n bombas
void sortearBombas(Celula jogo[10][10], int tam, int n){
    srand(time(NULL));
    for(int i = 1; i <= n; i++){
        int l = rand() % tam;
        int c = rand() % tam;
        if(jogo[l][c].eBomba == 0){
            jogo[l][c].eBomba = 1;
        }
        else
            i--;
    }
}

/*
    Função que diz se um par de coordenadas é válido ou não
    1 - é válido
    0 - não é válido
*/
int coordenadaEhValida(int l, int c, int tam){
    return (l >= 0 && l < tam && c >= 0 && c < tam);
}

/*
    Função que retorna a quantidade de bombas na vizinhança de l c
    n - quantidade de bombas
*/
int quantBombasVizinhas(Celula jogo[10][10], int l, int c, int tam){
    int quantidade = 0;
    if(coordenadaEhValida(l - 1, c, tam) && jogo[l-1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida(l + 1, c, tam) && jogo[l+1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida(l, c + 1, tam) && jogo[l][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida(l, c - 1, tam) && jogo[l][c-1].eBomba)
        quantidade++;
    return quantidade;
}

// funcao para contar as bombas vizinhas
void contarBombas(Celula jogo[10][10], int tam){
    for(int l = 0; l < tam; l++){
        for(int c = 0; c < tam; c++)
            jogo[l][c].vizinhos = quantBombasVizinhas(jogo, l, c, tam);
    }
}

// funcao para imprimir o jogo
void imprimir(Celula jogo[10][10], int tam){
    printf("\n\n\t    ");
    for(int l = 0; l < tam; l++)
        printf(" %d  ", l); // índices das colunas
    printf("\n\t   -----------------------------------------\n");
    for(int l = 0; l < tam; l++){
        printf("\t%d  |", l); // índices das linhas
        for(int c = 0; c < tam; c++){
            if(jogo[l][c].estaAberta){
                if(jogo[l][c].eBomba)
                    printf(" * ");
                else
                    printf(" %d ", jogo[l][c].vizinhos);
            }
            else
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}

// funcao para abrir a coordenada digitada pelo usuário
void abrirCelula(Celula jogo[10][10], int l, int c, int tam){
    if(coordenadaEhValida(l, c, tam) && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if(jogo[l][c].vizinhos == 0){
            abrirCelula(jogo, l-1, c, tam);
            abrirCelula(jogo, l+1, c, tam);
            abrirCelula(jogo, l, c+1, tam);
            abrirCelula(jogo, l, c-1, tam);
        }
    }
}

/*
    Função para verificar vitória
    n > 0 - não ganhou ainda
    0 - ganhou
*/
int ganhou(Celula jogo[10][10], int tam){
    int quantidade = 0;
    for(int l = 0; l < tam; l++){
        for(int c = 0; c < tam; c++){
            if(jogo[l][c].estaAberta == 0 && jogo[l][c].eBomba == 0)
                quantidade++;
        }
    }
    return quantidade;
}

// Procedimento jogar que faz a leitura das coordenadas
void jogar(Celula jogo[10][10], int tam, char *nomeJogador){
    int linha, coluna;

    do{
        imprimir(jogo, tam);
        do{
            printf("\nDigite as coordenadas de linha e coluna: ");
            scanf("%d%d", &linha, &coluna);

            if(coordenadaEhValida(linha, coluna, tam) == 0 || jogo[linha][coluna].estaAberta == 1)
                printf("\nCoordenada invalida ou ja aberta!");
        }while(coordenadaEhValida(linha, coluna, tam) == 0 || jogo[linha][coluna].estaAberta == 1);

        abrirCelula(jogo, linha, coluna, tam);
    }while(ganhou(jogo, tam) != 0 && jogo[linha][coluna].eBomba == 0);

    if(jogo[linha][coluna].eBomba == 1)
        printf("\n\tQue pena, %s! Voce perdeu!!!\n", nomeJogador);
    else
        printf("\n\tPARABENS, %s! VOCE GANHOU!!!\n", nomeJogador);

    imprimir(jogo, tam);
}

// Função para exibir o menu e retornar a opção escolhida
int exibirMenu() {
    int opcao;
    printf("\n░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("\n BEM VINDO AO CAMPO MINADO \n");
    printf("\n░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Instruções\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // limpar buffer
    return opcao;
}

// Função para exibir as instruções do jogo
void exibirInstrucoes() {
    printf("\nInstruções do Jogo:\n");
    printf("1. O objetivo é abrir todas as células que não têm bombas.\n");
    printf("2. Escolha uma célula digitando sua linha e coluna.\n");
    printf("3. Se abrir uma célula com uma bomba, você perde o jogo.\n");
    printf("4. Os números nas células indicam a quantidade de bombas nas células vizinhas.\n\n");
}

int main() {
    int tam = 10;
    char nomeJogador[50];
    Celula jogo[10][10];
    int opcao;

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                solicitarNomeJogador(nomeJogador);
                inicializarJogo(jogo, tam);
                sortearBombas(jogo, tam, 20);
                contarBombas(jogo, tam);
                jogar(jogo, tam, nomeJogador);
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

    } while (opcao != 3);

    return 0;
}
