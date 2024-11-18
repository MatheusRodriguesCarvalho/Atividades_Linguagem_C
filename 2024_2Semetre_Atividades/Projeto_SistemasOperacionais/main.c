#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 100

/*
O programa preccisa:
-Criar um arquivo
-Ler um arquivo
-Escrever um arquivo
- ...

*/

void String_Cleaner(char * s)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        *(s + i) = '\0';
    }
}


void Escrever_Arquivo()
{
    FILE *arq;
    char buffer[TAMANHO];

    String_Cleaner(buffer);
    printf("\nDigite o nome do Arquivo (com extensao): ");
    fflush(stdin);
    gets(buffer);

    char escolha = ' ';
    printf("\nDeseja Sobrescrever ou Adicionar o texto ao Arquivo (Digite S ou A)? ");
    scanf("%c", &escolha);
    escolha = toupper(escolha);
    switch (escolha)
    {
    case 'S':
        arq = fopen(buffer, "w");
        break;
    case 'A':
        arq = fopen(buffer, "a");
        break;
    default:
        printf("\nOpcao Invalida.");
        arq = NULL;
        system("cls");
        break;
    }

    if ( arq == NULL)
    {
        printf("\nNao foi possivel abrir o Arquivo.");
    }
    else
    {
        char texto[TAMANHO];

        printf("\nEscreva um texto de ate %i caracteres (digite .. para sair): ", TAMANHO);
        fflush(stdin);
        fgets(texto, TAMANHO, stdin);

        while( texto[0] != '.' && texto[1] != '.')
        {
            fputs(texto, arq);
            String_Cleaner(texto);

            printf("\nEscreva um texto de ate %i caracteres (digite .. para sair): ", TAMANHO);
            fflush(stdin);
            fgets(texto, TAMANHO, stdin);
        }
        fclose(arq);
    }
}

void Ler_Arquivo()
{
    FILE *arq;
    char buffer[TAMANHO];

    String_Cleaner(buffer);
    printf("\nDigite o nome do Arquivo (com extensao): ");
    fflush(stdin);
    gets(buffer);

    arq = fopen(buffer, "r");

    if( arq == NULL)
    {
        printf("\nNao foi possivel criar o arquivo.");
    }
    else
    {
        String_Cleaner(buffer);
        fgets(buffer, TAMANHO, arq);
        printf("%s", buffer);
        while ( !feof(arq) )
        {
            fgets(buffer, TAMANHO, arq);
            printf("%s", buffer);
        }

        fclose(arq);
    }


}

void Criar_Arquivo()
{
    FILE *arq;
    char buffer[TAMANHO];

    String_Cleaner(buffer);
    printf("\nDigite o nome do Arquivo (com extensao): ");
    fflush(stdin);
    fgets(buffer, TAMANHO, stdin);

    int posi = strrchr(buffer, '\n');

    buffer[posi] = '\0';

    arq = fopen(buffer, "w");

    if( arq == NULL )
    {
        printf("\nNao foi possivel criar o arquivo.");
        printf("-- %s --", buffer);
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
    //char arquivo[TAMANHO];

    while(opcao != 9)
    {
        printf("\n1. Criar Novo Arquivo (Sobrescrever)");
        printf("\n2. Ler Arquivo");
        printf("\n3. Escrever no Arquivo");
        printf("\n4. ");
        printf("\n9. Sair");
        printf("\n\nDigite o numero da opcao: ");
        fflush(stdin);
        scanf("%i", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            Criar_Arquivo();
            break;
        case 2:
            Ler_Arquivo();
            break;
        case 3:
            Escrever_Arquivo();
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 9:
            printf("\nSaindo.");
            break;
        default:
            printf("\nDigito Invalido!!\n");
            break;
        }
    }
}


int main()
{
    Menu();
    return 0;
}
