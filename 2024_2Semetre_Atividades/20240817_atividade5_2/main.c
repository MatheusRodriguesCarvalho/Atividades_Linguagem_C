#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;
    printf("Digite um numero: ");
    scanf("%f",&n);

    for(float linha=0; linha <= n/2; linha++)
    {
        for(float coluna=0; coluna < linha; coluna++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(float linha=n/2; linha > 0; linha--)
    {
        for(float coluna=linha; coluna > 0; coluna--)
        {
            printf("*");
        }

        printf("\n");
    }
}
