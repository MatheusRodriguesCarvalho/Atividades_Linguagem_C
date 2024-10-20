#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_P 100
#define TAM_R 100

typedef struct
{
    char pergunta[TAM_P];
    char resp1[TAM_R];
    char resp2[TAM_R];
    char resp3[TAM_R];
    int correta;
} tpPergunta;

void limparPergunta(tpPergunta *p)
{
    for(int i=0; i<TAM_P; i++)
    {
        p->pergunta[i] = '\0';
    }

    for(int i=0; i<TAM_R; i++)
    {
        p->resp1[i] = '\0';
        p->resp2[i] = '\0';
        p->resp3[i] = '\0';
    }
    p->correta = 0;
}

void salvarPergunta(tpPergunta perg)
{
    FILE * arq;

    arq = fopen("banco_do_quiz.qz", "ab");

    if (arq==NULL)
    {
        printf("\nNão foi possível abrir o arquivo.");
    }
    else
    {
        fwrite(&perg, sizeof(tpPergunta), 1, arq);
        fclose(arq);
    }
}

void criarPergunta()
{
    tpPergunta nova;

    limparPergunta(&nova);

    printf("\n\nCriando pergunta...");

    printf("\nDigite a pergunta:");
    fflush(stdin);
    fgets(nova.pergunta, TAM_P, stdin);

    printf("\nDigite a primeira resposta:");
    fflush(stdin);
    fgets(nova.resp1, TAM_R, stdin);

    printf("\nDigite a segunda resposta:");
    fflush(stdin);
    fgets(nova.resp2, TAM_R, stdin);

    printf("\nDigite a terceira resposta:");
    fflush(stdin);
    fgets(nova.resp3, TAM_R, stdin);

    do{
        printf("\nDigite qual é a alternativa que está correta: 1, 2 ou 3?");
        scanf("%i", &nova.correta);

        if(nova.correta!=1 && nova.correta!=2 && nova.correta!=3)
        {
            printf("\nOpção inválida! Tem que ser 1, 2 ou 3");
        }

    }while(nova.correta!=1 && nova.correta!=2 && nova.correta!=3);

    salvarPergunta(nova);
}

void configurar()
{
    char opcao;

    while(opcao!='B' && opcao!='b'){
        printf("\n\nConfigurando o jogo... ");

        printf("\nA - Criar nova pergunta");
        printf("\nB - Voltar ao menu principal");

        printf("\nDigite uma das opções acima:");
        fflush(stdin);
        scanf("%c", &opcao);

        switch (opcao)
        {
            case 'A':
            case 'a':
                criarPergunta();
                break;
            case 'B':
            case 'b':
                break;
            default:
                printf("\n\nOpção inválida! Tente novamente...");
        }
    }

}

void jogar()
{
    printf("\n\nJogando... ");
}

void menu()
{
    int opcao=0;

    setlocale(LC_ALL, "portuguese"); // Configurar caracteres no padrão português

    while(opcao!=3){
        system("cls");
        printf("\n*** JOGO QUIZ - FEITO EM SALA DE AULA ***\n\n");
        printf("\n1 - Configurar");
        printf("\n2 - Jogar");
        printf("\n3 - Sair");

        printf("\nDigite a opção: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
            case 1:
                configurar();
                break;
            case 2:
                jogar();
                break;
            case 3:
                printf("\n\nEspero que tenha gostado! Até a próxima!!!");
                break;
            default:
                printf("\n\nOpção inválida! Tente novamente...");
        }
        fflush(stdin);
        getchar();
    }
}

int main()
{
    menu();
    return 0;
}
