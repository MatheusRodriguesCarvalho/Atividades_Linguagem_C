#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 100
#define MAX_QUESTOES 50

typedef struct{
    char pergunta[TAM];
    char resp1[TAM];
    char resp2[TAM];
    char resp3[TAM];
    int correta;
}tQuestao;

void limparQuestao(tQuestao *q)
{
    for(int i=0; i<TAM; i++)
    {
        q->pergunta[i]='\0';
        q->resp1[i]='\0';
        q->resp2[i]='\0';
        q->resp3[i]='\0';
    }
    q->correta = 0;
}

void gravarQuestaoNoArquivo(tQuestao q)
{
    FILE *arq;

    arq = fopen("bancoquestoes.qz", "ab");

    if(arq == NULL)
    {
        printf("\n\nERRO - N�o foi poss�vel abrir o arquivo.");
    }
    else
    {
        fwrite(&q, sizeof(tQuestao),1, arq);

        fclose(arq);
    }
}

void configurarQuestao()
{
    tQuestao nova_questao;

    limparQuestao(&nova_questao);

    printf("\nInserindo NOVA quest�o no jogo...\n");

    printf("\n\nDigite a pergunta: ");
    fflush(stdin);
    fgets(nova_questao.pergunta, TAM, stdin);

    printf("\n\nDigite a 1a op��o de resposta: ");
    fflush(stdin);
    fgets(nova_questao.resp1, TAM, stdin);

    printf("\n\nDigite a 2a op��o de resposta: ");
    fflush(stdin);
    fgets(nova_questao.resp2, TAM, stdin);

    printf("\n\nDigite a 3a op��o de resposta: ");
    fflush(stdin);
    fgets(nova_questao.resp3, TAM, stdin);

    do{
        printf("\n\nQual das respostas � a correta (1, 2 ou 3): ");
        scanf("%d", &nova_questao.correta);

    }while(!((nova_questao.correta == 1) || (nova_questao.correta == 2) || (nova_questao.correta == 3)));

    gravarQuestaoNoArquivo(nova_questao);
}

void configurar()
{
    char opcaoConfig;

    while(!(opcaoConfig=='B' || opcaoConfig=='b'))
    {
        system("cls");
        printf("\nConfigurando o Jogo...");

        printf("\nA) Configurar uma nova quest�o no banco de quest�es.");
        printf("\nB) Voltar para o menu principal.");

        printf("\nEscolha uma das op��es acima: ");
        fflush(stdin);
        scanf("%c", &opcaoConfig);

        switch (opcaoConfig)
        {
            case 'a':
            case 'A':
                configurarQuestao();
                break;
            case 'b':
            case 'B':
                break;
            default:
                printf("\n\nOp��o inv�lida.");
        }
        fflush(stdin);
        getchar();
    }
}

void carregarQuestoes(tQuestao *vet, int *qtdVet)
{
    FILE * arq;
    *qtdVet = 0;

    arq = fopen("bancoquestoes.qz", "rb");

    if(arq==NULL)
    {
        printf("\n\nERRO - N�o foi poss�vel abrir o arquivo.");
    }
    else
    {
        fread(&vet[*qtdVet], sizeof(tQuestao), 1, arq);

        while(!feof(arq) && (*qtdVet)<MAX_QUESTOES )
        {
            (*qtdVet)++;
            fread(&vet[*qtdVet], sizeof(tQuestao), 1, arq);
        }

        fclose(arq);
    }

}

int responderQuestao(tQuestao q)
{
    int acertou=0, resp;

    printf("\n%s", q.pergunta);
    printf("\n1) %s", q.resp1);
    printf("\n2) %s", q.resp2);
    printf("\n3) %s", q.resp3);

    printf("Qual � a resposta correta? (1, 2 ou 3)");
    scanf("%i", &resp);

    if (resp == q.correta)
    {
        acertou = 1;
        printf("\nParab�ns! Voc� acertou a quest�o!");
    }
    else
    {
        printf("\nSinto muito.... voc� errou a quest�o.");
    }

    return acertou;
}

void jogar()
{
    tQuestao questoes[MAX_QUESTOES];
    int qtdQuestoesConfig = 0;
    int nroAcertos = 0;

    printf("\nJogando...");

    carregarQuestoes(questoes, &qtdQuestoesConfig);

    for(int i=0; i<qtdQuestoesConfig; i++)
    {
        if(responderQuestao(questoes[i]))
        {
            nroAcertos++;
        }
    }

    printf("\n\n\nFIM DE JOGO! - Seu percentual de acertos = %.1f%%", ((float)nroAcertos/(float)qtdQuestoesConfig)*100.0f);

    fflush(stdin);
    getchar();
}

void menu()
{
    int opcao=0;

    while(opcao!=3)
    {
        system("cls");
        printf("\n\n*************** JOGO QUIZ ***************\n\n");

        printf("1) Configurar quest�es\n");
        printf("2) Jogar\n");
        printf("3) Sair\n");

        printf("\n\nEscolha uma das op��es acima: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                configurar();
                break;
            case 2:
                jogar();
                break;
            case 3:
                printf("\nAt� mais! Volte novamente quando puder...");
                break;
            default:
                printf("\nOp��o Inv�lida!\n");
        }
    }


}

int main()
{
    setlocale(LC_ALL, "portuguese");

    menu();

    return 0;
}
