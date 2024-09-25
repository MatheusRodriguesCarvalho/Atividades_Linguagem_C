#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char tipo[20];
    int quantidade;
} alimento;
/*
eh criado uma estrutura como um tipo de variavel=
*/

int main()
{
    alimento uva;
    /*
    apenas sendo preciso utilizar o "typedef" como
    um tipo de variavel para "instanciar" a classe
    em variavel.
    */

    //uva.tipo = "Fruta"; Retorna erro
    strcpy(uva.tipo, "Fruta");
    /*
    STRingCoPY(); ira copiar / atribuir um texto a um
    vetor, sendo preciso que o vetor tenha espaco
    suficiente para alocar o texto.
    */
    uva.quantidade = 5;
    printf("%s: ", uva.tipo);
    printf("%d Quantidade(s)", uva.quantidade);

}
