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
        if ()
        {
            printf("Erro ao criar o Arquivo Texto_Novo.txt");
        }
        else
        {




            fclose(texto_Novo);
        }
        fclose(texto_Original);
    }
}

int main()
{
    criarCopia(); // por Strings
    //escreverLinha();
    //compararTextos();

    return 0;
}
