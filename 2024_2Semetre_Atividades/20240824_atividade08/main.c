#include <stdio.h>
#include <stdlib.h>

float CALCULO(float x, float a, float c)
{
    float expresao;
    expresao = ( x * x ) + ( 4 * a * c ) - 36;
    return expresao;
}

int main()
{
    float x, a, c;
    printf("Dado a Expresao [ x^2 + 4 * a * c - 36 ]\n");
    printf("Informe um valor para [ x ]: ");
    scanf("%f", &x);
    printf("Informe um valor para [ a ]: ");
    scanf("%f", &a);
    printf("Informe um valor para [ c ]: ");
    scanf("%f", &c);

    printf("O Valor, Resultado da expressao eh %.2f", CALCULO(x, a, c));

    return 0;
}
