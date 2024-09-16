#include <stdio.h>
#include <stdlib.h>

#define pi 3.1416

float calc_volume_esfera(float raio)
{
    float volume;
    volume = (4 * pi * raio * raio * raio) / 3;
    return volume;
}

int main()
{
    float x;
    printf("Qual eh o raio da esfera: ");
    scanf("%f",&x);

    x = calc_volume_esfera(x);

    printf("O Volume dessa esfera eh %0.2f qualquer coisa ³", x);

    return 0;
}
