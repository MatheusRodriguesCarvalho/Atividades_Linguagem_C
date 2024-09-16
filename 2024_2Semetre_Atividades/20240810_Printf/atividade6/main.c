#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, metade;
    printf("Digite um numero: ");
    scanf("%f",&n);

    metade = n/2;

    /*
    n=5
    metade=2.5 -> 2
    */

    for(float linha=0; linha < metade; linha++)
    {
        for(float coluna=0; coluna < linha; coluna++)
        {
            printf(" ");
        }
        printf("O");
        printf("\n");
    }

    //printf("----\n");
    //if( (int)(n) % 2 == 1 ) { metade -= 0.5; }

    for(float linha = metade-1; linha >= 0; linha--)
    {
        for(float coluna = linha; coluna >= 1; coluna--)
        {
            printf(" ");
        }

        printf("O");
        printf("\n");
    }
}
