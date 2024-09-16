#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, metade;
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

/*
int main()
{
    float numero;
    float med;
    printf("Digite um numero: ");
    scanf("%f", &numero);

    for(float linha = 1; linha <= numero; linha++)
    {
        //med = abs(linha - numero / 2);
        med = numero - abs(numero / 2 - linha) - numero / 2 + 1;

        for(float coluna = 0; coluna < med; coluna++)
        {
            printf("*");
        }

        printf("     %.2f",med);
        printf("\n");

    }
}
*/
/*

numero= 5

med = numero - abs(numero / 2 - linha);

linha   numero	med
0       2,5 	2,5
1       2,5	    1,5
2   	2,5 	0,5
3	    2,5 	0,5
4   	2,5 	1,5

5	    2,5     2,5


numero= 6
med = numero - abs(numero / 2 - linha) - numero / 2;

linha   numero	med
0       3   	3
1       3   	4
2       3   	5
3       3   	6
4       3   	5
5       3   	4

6       3   	3


*/

