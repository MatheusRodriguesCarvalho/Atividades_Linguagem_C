#include <stdio.h>
#include <stdlib.h>

int identificarQuadrante(float x, float y)
{
    int quadrante;

    if (x >= 0)
    {
        if (y >= 0)
        { quadrante = 1; }
        else
        { quadrante = 4; }
    }
    else
    {
        if (y >= 0)
        { quadrante = 2; }
        else
        { quadrante = 3; }
    }
    return quadrante;
}

int main()
{
    float x, y;
    printf("Digite a coordenada de X:");
    scanf("%f", &x);
    printf("Digite a coordenada de Y:");
    scanf("%f", &y);

    printf("O quadrante em que o esse ponto de localiza eh o %i. Quadrante",
           identificarQuadrante(x, y) );

    return 0;
}
