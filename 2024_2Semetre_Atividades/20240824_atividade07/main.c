#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float HIPOTENUSA(float alt, float bas)
{
    float hipotenusa;
    hipotenusa = sqrt( alt * alt + bas * bas );
    return hipotenusa;
}

int main()
{
    float altura, base;
    printf("Qual eh a altura do triangulo: ");
    scanf("%f", &altura);
    printf("Quanto eh a base do triangulo: ");
    scanf("%f", &base);

    printf("O Valor da Hipotenusa eh de %.2f", HIPOTENUSA(altura, base ));

    return 0;
}
