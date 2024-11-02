#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>



typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
} Celula;












// Função para exibir o menu e retornar a opção escolhida
int exibirMenu() {
    int opcao;
    printf("\n---------------------------\n");
    printf("\n BEM VINDO AO CAMPO MINADO \n");
    printf("\n---------------------------\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Instruções\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // limpar buffer
    return opcao;
}

int main() {

    setlocale(LC_ALL, "portuguese"); 
    
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

