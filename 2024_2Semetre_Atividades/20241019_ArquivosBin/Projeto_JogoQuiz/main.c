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


void menu()
{

    int opcao = 0;
    while(opcao != 4)
    {
        setlocale(LC_ALL, "portuguese"); //Configura o texto para portugues brasil

        system("cls");
        printf("\n---   Quiz Espacial   ---\n");
        printf("\n1. Configurar");
        printf("\n2. Jogar");
        printf("\n3. Como Jogar");
        printf("\n4. Sair");

        printf("\nDigite a Opção: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            Configurar();
            break;
        case 2:
            Jogar();
            break;
        case 3:
            //Tutorial();
            break;
        case 4:
            break;
        default:
            printf("Comando Inválido. Digite novamente");
        }
        fflush(stdin);
        getchar();
    }
}

void SalvarPergunta(tpPergunta pergunta)
{

    FILE * arq;
    arq = fopen("banco de dados.qz", "ab");

    if (arq == "NULL")
    {
        printf("Nao deu, chefe. ve ai");
    }
    else
    {
        fwrite(&pergunta, sizeof(pergunta), 1, arq);
        fclose(arq);
    }

    //leitura por bytes
}


void LimparPergunta(tpPergunta *Caixa)
{

    for(int i = 0; i < TAM_P; i++)
    {
        Caixa->pergunta[i] = '\0';
    }
    for(int i = 0; i < TAM_R; i++)
    {
        Caixa->resp1[i] = '\0';
        Caixa->resp2[i] = '\0';
        Caixa->resp3[i] = '\0';
    }

    Caixa->correta = 0;

}

void CriarPergunta()
{
    tpPergunta nova;

    printf("\n\nCriando mentiras...");

    LimparPergunta(&nova);

    printf("\nDigite a Pergunta:");
    fflush(stdin);
    fgets(nova.pergunta, TAM_P, stdin);

    printf("\nDigite a Primeira Resposta:");
    fflush(stdin);
    fgets(nova.resp1, TAM_R, stdin);

    printf("\nDigite a Segunda Resposta:");
    fflush(stdin);
    fgets(nova.resp2, TAM_R, stdin);

    printf("\nDigite a Terceira Resposta:");
    fflush(stdin);
    fgets(nova.resp3, TAM_R, stdin);

    do
    {
        printf("\nDigite qual das Resposta esta correta. 1, 2 ou 3:");
        fflush(stdin);
        scanf("%i", nova.correta);

        if (nova.correta != 1 && nova.correta != 2 && nova.correta != 3)
        {
            printf("Opcao invaida");
        }

    }
    while (nova.correta != 1 && nova.correta != 2 && nova.correta != 3);

    SalvarPergunta(nova);
}

void Configurar()
{
    printf("Configurando...");

    char opcao = ' ';

    while(opcao != 'B' && opcao != 'b')
    {
        system("cls");
        printf("\nA - Configurar as Perguntas.");
        printf("\nB - Voltar ao Menu principal.");

        printf("\nDigite a Opção: ");
        fflush(stdin);
        scanf("%c", &opcao);


        switch (opcao)
        {
        case 'A':
        case 'a':
            CriarPergunta();
            break;
        case 'B':
        case 'b':
            break;
        default:
            printf("\nComando Inválido. Digite novamente");
        }
        fflush(stdin);
        getchar();
    }

}

void Jogar()
{
    printf("Jogando...");
}

int main()
{
    menu();
    return 0;
}
