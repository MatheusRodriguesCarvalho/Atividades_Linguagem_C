#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 100

void String_Cleaner(char * buffer)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        *(buffer + i) = '\0';
    }
}
void Get_FileName(char * buffer, int modo)
{
    //0 - pegar arquivo, 1 - pegar novo arquivo
    switch (modo)
    {
    case 0:
        printf("\nDigite o nome do Arquivo (com extensao): ");
        break;
    case 1:
        printf("\nDigite o novo nome do Arquivo (com extensao): ");
        break;
    default:
        printf("\nNenhuma opcao foi selecionada.");
        break;
    }
    fflush(stdin);
    fgets(buffer, TAMANHO, stdin);
}
void FindDelete_Enter(char * buffer)
{
    int pos = strcspn(buffer, "\n");
    buffer[pos] = '\0';
}


void Criar_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    String_Cleaner(nomeArquivo);
    Get_FileName(nomeArquivo, 0);
    FindDelete_Enter(nomeArquivo);

    arq = fopen(nomeArquivo, "w");

    if( arq == NULL )
    {
        printf("\nNao foi possivel criar o arquivo.");
        printf("-- %s --", nomeArquivo);
    }
    else
    {
        printf("\nArquivo criado");
        fclose(arq);
    }

}

void Ler_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    String_Cleaner(nomeArquivo);
    Get_FileName(nomeArquivo, 0);
    FindDelete_Enter(nomeArquivo);

    arq = fopen(nomeArquivo, "r");

    if( arq == NULL)
    {
        printf("\nNao foi possivel criar o arquivo.");
    }
    else
    {
        char buffer[TAMANHO];
        String_Cleaner(buffer);
        fgets(buffer, TAMANHO, arq);
        while ( !feof(arq) )
        {
            printf("%s", buffer);
            fgets(buffer, TAMANHO, arq);
        }
        fclose(arq);
    }
}

void Escrever_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    String_Cleaner(nomeArquivo);
    Get_FileName(nomeArquivo, 0);
    FindDelete_Enter(nomeArquivo);

    char escolha = ' ';
    printf("\nDeseja Sobrescrever ou Adicionar o texto ao Arquivo (Digite S ou A)? ");
    scanf("%c", &escolha);
    escolha = toupper(escolha);
    switch (escolha)
    {
    case 'S':
        arq = fopen(nomeArquivo, "w");
        break;
    case 'A':
        arq = fopen(nomeArquivo, "a");
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

void Renomear_Arquivo()
{
    char nomeAntigo[TAMANHO];
    char nomeNovo[TAMANHO];

    String_Cleaner(nomeAntigo);
    Get_FileName(nomeAntigo, 0);
    FindDelete_Enter(nomeAntigo);

    String_Cleaner(nomeNovo);
    Get_FileName(nomeNovo, 1);
    FindDelete_Enter(nomeNovo);

    if (rename(nomeAntigo, nomeNovo) == 0)
    {
        printf("Arquivo renomeado com sucesso de: '%s' para '%s'.\n", nomeAntigo, nomeNovo);
    }
    else
    {
        perror("Nao foi possivel renomear o arquivo...");
    }
}

void Copiar_Arquivo()
{
    FILE *arq;
    FILE *newArq;
    char nomeOrigem[TAMANHO];
    char nomeDestino[TAMANHO];

    String_Cleaner(nomeOrigem);
    Get_FileName(nomeOrigem, 0);
    FindDelete_Enter(nomeOrigem);

    arq = fopen(nomeOrigem, "r");

    String_Cleaner(nomeDestino);
    Get_FileName(nomeDestino, 1);
    FindDelete_Enter(nomeDestino);

    newArq = fopen(nomeDestino, "w");

    if( arq == NULL && newArq == NULL )
    {
        printf("\nNao foi possivel copiar o Arquivo.");
    }
    else
    {

        char buffer[TAMANHO];
        String_Cleaner(buffer);
        fgets(buffer, TAMANHO, arq);
        while ( !feof(arq) )
        {
            fputs(buffer, newArq);
            fgets(buffer, TAMANHO, arq);
        }

        fclose(arq);
        fclose(newArq);
    }
}

void Excluir_Arquivo()
{

}

void Converter_Arquivo()
{

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
        printf("\n4. Renomear Arquivo");
        printf("\n5. Copiar Arquivo");
        printf("\n6. Excluir Arquivo (excluir linha)");
        printf("\n7. Converter Arquivo");
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
            Renomear_Arquivo();
            break;
        case 5:
            Copiar_Arquivo();
            break;
        case 6:
            Excluir_Arquivo();
            break;
        case 7:
            Converter_Arquivo();
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
