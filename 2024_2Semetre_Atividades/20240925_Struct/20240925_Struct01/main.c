#include <stdio.h>
#include <stdlib.h>


struct modelo
{
    int inteiro;
    float flutuante;
    char caractere;
} /*valores (um ou mais)*/;
/*
e possivel "instanciar" ou criar o "objeto" direto na
struct, e isso não inpediria, supostamente, de criar
mais instancias para essa "classe" posteriormente.

ou declarar uma variavel na estrutura
*/


int main()
{
    struct modelo valores = {5, 5.5, 'd'};
    /*
    Ou ao declarar um "nome" para a struct, eu meio que
    faco uma instancia da "classe", podendo utilizar
    todas as variavel nela contida
    */

    //printf("%d\n", valores.inteiro);
    valores.inteiro = 10;
    printf("%d\n", valores.inteiro);
    valores.inteiro = 20;
    printf("%d\n", valores.inteiro);
}
