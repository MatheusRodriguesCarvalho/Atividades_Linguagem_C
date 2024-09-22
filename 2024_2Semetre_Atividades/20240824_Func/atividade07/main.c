#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void HIPOTENUSA(float bas, float alt, float *hip)
{
    float hipotenusa;
    *hip = sqrt( alt * alt + bas * bas );
}

int main()
{
    float altura, base, hipot;
    printf("Qual eh a altura do triangulo: ");
    scanf("%f", &altura);
    printf("Quanto eh a base do triangulo: ");
    scanf("%f", &base);

    HIPOTENUSA(altura, base, &hipot);
    printf("O Valor da Hipotenusa eh de %.2f", hipot);

    return 0;
}
