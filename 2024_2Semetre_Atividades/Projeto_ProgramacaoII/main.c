#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 100


void Ler_Arquivo()
{
    FILE *arq;
    char nome[TAMANHO];
    char buffer[TAMANHO];

    printf("\nDigite o nome do Arquivo (com extensao): ");
    fflush(stdin);
    gets(nome);

    arq = fopen(nome, "r");

    if( arq == NULL)
    {
        printf("\nNao foi possivel criar o arquivo.");
    }
    else
    {
        printf("\nLendo Arquivo %s", nome);


        while( EOF() )
        {

        }

        fclose(arq);
    }


}

void Criar_Arquivo()
{
    FILE *arq;

    arq = fopen("arquivo_teste.txt", "w");

    if( arq == NULL )
    {
        printf("\nNao foi possivel criar o arquivo.");
    }
    else
    {
        printf("\nArquivo criado");
        fclose(arq);
    }

}



void Menu()
{
    int opcao = 0;
    while(opcao != 5)
    {
        printf("\n1. Criar Arquivo");
        printf("\n2. Ler Arquivo");
        printf("\n3. ");
        printf("\n4. ");
        printf("\n5. Sair");
        printf("\nDigite o numero da opcao: ");
        fflush(stdin);
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            Criar_Arquivo();
            break;
        case 2:
            Ler_Arquivo();
            break;
        case 3:
            printf("\nEscrever.");
            break;
        case 4:
            printf("\nConvercao.");
            break;
        case 5:
            printf("\nSair");

            break;
        default:
            printf("a");
            break;
        }
    }
}



int main()
{
    Menu();
    return 0;
}
