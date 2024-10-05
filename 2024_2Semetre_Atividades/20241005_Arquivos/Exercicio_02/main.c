#include <stdio.h>
#include <stdlib.h>

#define Tamanho 100

/*
1 - Considere um arquivo tipo texto ja gerado.
2 - gere um novo arquivo com uma linha nova, com dados
lidos do teclado, entre a terceira e a quarta linha
desse texto.
3 - Mostre o conteudo do arquivo original e do novo
*/

void EscreverEntreLinhas()
{
    FILE *texto_Original;
    FILE *texto_Novo;
    char linha[Tamanho];
    int contagem = 0;

    texto_Original = fopen("Texto_Original.txt", "r");
    if (texto_Original == NULL)
    {
        printf("Erro ao abrir o Arquivo Texto_Original.txt");
    }
    else
    {
        texto_Novo = fopen("Texto_Novo.txt", "w");
        if (texto_Novo == NULL)
        {
            printf("Erro ao criar o Arquivo Texto_Novo.txt");
        }
        else
        {
            while( !feof(texto_Original) )
            {
                fgets(linha, Tamanho, texto_Original);
                contagem++;
                fputs(linha, texto_Novo);
                if(contagem == 3)
                {
                    printf("Digite um nola linha: ");
                    fflush(stdin);
                    fgets(linha, Tamanho, stdin);
                    fputs(linha, texto_Novo);
                }
            }
            fputs(linha, texto_Novo);

            fclose(texto_Novo);
        }
        fclose(texto_Original);
    }
}

int main()
{
    EscreverEntreLinhas();
    //criarCopia(); // por Strings
    //escreverLinha();
    //compararTextos();

    return 0;
}

/*

void criarCopia()
{
    FILE *texto_Original;
    FILE *texto_Novo;
    char linha[Tamanho];

    texto_Original = fopen("Texto_Original.txt", "r");
    if (texto_Original == NULL)
    {
        printf("Erro ao abrir o Arquivo Texto_Original.txt");
    }
    else
    {
        texto_Novo = fopen("Texto_Novo.txt", "w");
        if (texto_Novo == NULL)
        {
            printf("Erro ao criar o Arquivo Texto_Novo.txt");
        }
        else
        {
            fgets(linha, Tamanho, texto_Original);
            while( !feof(texto_Original))
            {
                fputs(linha, texto_Novo); // fputs(" teste ", texto_Novo);
                fgets(linha, Tamanho, texto_Original);
            }
            fputs(linha, texto_Novo);

            fclose(texto_Novo);
        }
        fclose(texto_Original);
    }
}

void escreverLinha()
{
    FILE *texto_Novo;
    char linha[Tamanho];

    texto_Novo = fopen("Texto_Novo.txt", "r+");
    if (texto_Novo == NULL)
    {
        printf("Erro ao abrir o Arquivo Texto_Novo.txt");
    }
    else
    {
        fgets(linha, Tamanho, stdin);
        for (int i = 1; !feof(texto_Novo); i++)
        {
            if (i == 3)
            {
                fputs(linha, texto_Novo);
            }
        }

        fclose(texto_Novo);
    }
}

*/
