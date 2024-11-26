#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 100

void String_Cleaner(char * buffer) //Limpa todo o lixo da String
{
    for (int i = 0; i < TAMANHO; i++)
    {
        *(buffer + i) = '\0';
    }
}
void Get_Name(char * buffer, int modo) //Pergunta e Armazena o nome do arquivo
{
    //0 - pegar arquivo, 1 - pegar novo arquivo, 2 - refere a exclusao
    switch (modo)
    {
    case 0:
        printf("\nDigite o nome do Arquivo (com extensao): ");
        break;
    case 1:
        printf("\nDigite o novo nome do Arquivo (com extensao): ");
        break;
    case 2:
        printf("\nDigite o nome do Arquivo que sera excluido (com extensao): ");
        break;
    default:
        printf("\nNenhuma opcao foi selecionada.");
        break;
    }
    fflush(stdin);
    fgets(buffer, TAMANHO, stdin);
}
void FindDelete_Enter(char * buffer) //Retira o "\n" da string;
{
    int pos = strcspn(buffer, "\n");
    buffer[pos] = '\0';
}
void Get_FileName(char * buffer, int modo)
{
    String_Cleaner(buffer);
    Get_Name(buffer, modo);
    FindDelete_Enter(buffer);
}

void Criar_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    Get_FileName(nomeArquivo, 0);
    arq = fopen(nomeArquivo, "a");

    if( arq == NULL )
    {
        printf("\nNao foi possivel criar o arquivo '%s'", nomeArquivo);
    }
    else
    {
        printf("\nArquivo '%s' criado", nomeArquivo);
        fclose(arq);
    }
    getchar();
}

void Ler_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    Get_FileName(nomeArquivo, 0);
    arq = fopen(nomeArquivo, "r");

    if( arq == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo '%s'", nomeArquivo);
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
    printf("\nRetornando...");
    getchar();
}

void Escrever_Arquivo()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    Get_FileName(nomeArquivo, 0);

    if ( arq == NULL)
    {
        printf("\nNao foi possivel abrir o Arquivo '%s'", nomeArquivo);
    }
    else
    {
        char texto[TAMANHO];
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
    printf("\nRetornando...");
    getchar();
}

void Renomear_Arquivo()
{
    char nomeAntigo[TAMANHO];
    char nomeNovo[TAMANHO];

    Get_FileName(nomeAntigo, 0);
    Get_FileName(nomeNovo, 1);

    if (rename(nomeAntigo, nomeNovo) == 0)
    {
        printf("\nArquivo renomeado com sucesso de: '%s' para '%s'.\n", nomeAntigo, nomeNovo);
    }
    else
    {
        perror("\nNao foi possivel renomear o arquivo...");
    }
    getchar();
}

void Copiar_Arquivo()
{
    FILE *arq;
    char nomeOrigem[TAMANHO];

    Get_FileName(nomeOrigem, 0);
    arq = fopen(nomeOrigem, "r");

    if( arq == NULL )
    {
        printf("\nNao foi possivel localizar o Arquivo '%s'", nomeOrigem);
    }
    else
    {
        FILE *newArq;
        char nomeDestino[TAMANHO];
        Get_FileName(nomeDestino, 1);
        newArq = fopen(nomeDestino, "w");

        if ( newArq == NULL)
        {
            printf("\nNao foi possivel copiar o Arquivo '%s'", nomeDestino);
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
            fclose(newArq);
            printf("\nArquivo '%s' Copiado com Sucesso para '%s'", nomeOrigem, nomeDestino);
        }
        fclose(arq);
    }
    getchar();
}

void Excluir_Arquivo()
{
    char nomeArquivo[TAMANHO];
    Get_FileName(nomeArquivo, 2);

    if( remove(nomeArquivo) == 0)
    { printf("\n'%s' foi excluido com Sucesso!", nomeArquivo); }
    else
    { printf("\nOcorreu um Erro na exclusao do Arquivo '%s'", nomeArquivo); }
    getchar();
}

void Excluir_Linha()
{
    FILE *arq;
    char nomeArquivo[TAMANHO];

    Get_FileName(nomeArquivo, 0);
    arq = fopen(nomeArquivo, "a+");

    if( arq == NULL)
    {
        printf("\nNao foi possivel localizar o arquivo '%s'", nomeArquivo);
    }
    else
    {
        FILE *temp;
        char tempName[TAMANHO] = "temporary_File_To_Hold_The_Text_4709_1.txt";
        temp = fopen(tempName, "a+");
        if( temp == NULL)
        {
            printf("\nNao foi possivel criar o arquivo '%s'", tempName);
        }
        else
        {
            char text[TAMANHO];
            int linha; int cont = 1;
            printf("\nQual linha deseja excluir? ");
            scanf("%i", &linha);

            String_Cleaner(text);
            fgets(text, TAMANHO, arq);
            while ( !feof(arq) )
            {
                if ( linha != cont)
                {
                    fputs(text, temp);
                    fgets(text, TAMANHO, arq);
                }
                else
                {
                    fgets(text, TAMANHO, arq);
                }
                cont += 1;
            }

            fclose(temp);
            fclose(arq);
            printf("\nLinha %i, do Arquivo '%s' foi Excluida", linha, nomeArquivo);

            remove(nomeArquivo);
            rename(tempName, nomeArquivo);
        }
        fclose(arq);
    }
    getchar();
}


void Menu()
{
    char opcao = '0';
    //char arquivo[TAMANHO];

    while(opcao != '9')
    {
        system("cls");
        printf("\n1. %c Criar Novo Arquivo (Sobrescrever)", 245);
        printf("\n2. %c Leitura de Arquivo", 169);
        printf("\n3. %c Escrever / Sobrescrever no Arquivo", 175);
        printf("\n----------------------------------------");
        printf("\n4. %c Renomear Arquivo", 171);
        printf("\n5. %c Copiar Arquivo", 184);
        printf("\n---------------------");
        printf("\n6. %c Excluir Arquivo", 88);
        printf("\n7. %c Excluir Linha", 207);
        printf("\n-----------------");
        printf("\n9. %c Sair", 254);
        printf("\n\nDigite o numero da opcao: ");
        fflush(stdin);
        scanf("%c", &opcao);
        system("cls");

        switch (opcao)
        {
        case '1':
            Criar_Arquivo();
            break;
        case '2':
            Ler_Arquivo();
            break;
        case '3':
            Escrever_Arquivo();
            break;
        case '4':
            Renomear_Arquivo();
            break;
        case '5':
            Copiar_Arquivo();
            break;
        case '6':
            Excluir_Arquivo();
            break;
        case '7':
            Excluir_Linha();
            break;
        case '9':
            printf("\nSaindo.");
            break;
        default:
            printf("\nDigito Invalido!!\n");
            system("pause");
            break;
        }
    }
}

int main()
{
    Menu();
    return 0;
}
