#include <stdio.h>
#include <stdlib.h>

float CALCULO(float x, float a, float c, float *res)
{
    *res = ( x * x ) + ( 4.0f * a * c ) - 36.0f;
}

int main()
{
    float x, a, c, res;
    printf("Dado a Expresao [ x^2 + 4 * a * c - 36 ]\n");
    printf("Informe um valor para [ x ]: ");
    scanf("%f", &x);
    printf("Informe um valor para [ a ]: ");
    scanf("%f", &a);
    printf("Informe um valor para [ c ]: ");
    scanf("%f", &c);

     CALCULO(x, a, c, &res);

    printf("O Valor, Resultado da expressao eh %.2f", res);

    return 0;
}
