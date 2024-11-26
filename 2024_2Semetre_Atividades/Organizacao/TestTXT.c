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
void Verify_Txt(char * buffer)
{
    int *pos = strstr(buffer, ".txt");
    printf("%x\n\n", pos);
}
void Get_FileName(char * buffer, int modo)
{
    String_Cleaner(buffer);
    Get_Name(buffer, modo);
    FindDelete_Enter(buffer);
    Verify_Txt(buffer);
}

int main()
{
    char texto[TAMANHO];

    Get_FileName(texto, 0);
    printf("%s", texto);

    return 0;
}

