#include <stdio.h>
#include <stdlib.h>

void escreverCaractere()
{
    FILE * arq;
    arq = fopen("arquivo_01.txt", "a");

    if (arq == NULL)
    {
        printf("Ocorreu um Error ao abrir o arquivo!");
    }
    else
    {
        char carac;
        printf("Digite o caractere que ira armazenar: ");
        fflush(stdin);
        scanf("%c", &carac);

        while(carac != '1')
        {
            fputc(carac, arq);
            printf("Digite o caractere que ira armazenar: ");
            fflush(stdin);
            scanf("%c", &carac);
        }

        fclose(arq);
    }


}

int main()
{
    escreverCaractere();
}

/*
Manipulacao de arquivos:
em essencia, manipular arquivos


FILE *p;
p = fopen();//retorna o endereco da memoria RAM
-por conta disso que eh preciso atribuir esse valor a um ponteiro

modo de Abertura:
-r (leitura), w (escrita), a (anexa, se existe, ou cria se nao existe)

//exemplo
FILE *arq;
arq = fopen("arquivo1.dat", "w");
obs:
-se nao especificado o caminho, ele cria o arquivo no mesmo diretorio do executavel desse programa
-se fopen retornar NULL, significa que nao foi encontrado o caminho

mkdir("diretorio");
-para criar "pastas"

fclose(arq);
obs:
-retira da memoria RAM e salva no HD
-nao deixar os arquivos muito tempo aberto por muito tempo, pos se torna mais sucetivel para que ele fique corronpido

ferror(FILE *arq);
-verifica se houve algum error

fputc(char ch, FILE *arq);
-serve para colocar um caractere no arquivo

int fgetc(FILE *arq);
-representacao de caractere por numero pela tabela ASCII
-le o arquivo, especificamente, um caractere

feof(arq); function end of file
-verifica se e fim de arquivo
-ou EOF, que e o caracte fim de arquivo

fputs(char *cadeia, FILE *arq);
-escreve ate onde ha um '\0'

fgets(char *cadeia, int tam, FILE *arq);
-le o vetor do texto


*/
