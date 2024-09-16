#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero: \n");
    scanf("%i",&n);

    for(int linha=1; linha <= n; linha++)
    {

        int metade;
        metade = n/2 - abs(linha - n/2);

        //n = 6
        //n/2 = 3

        //linha = 4
        //linha - n/2 = 4-3=1
        //1

        //metade = n/2 - abs(linha - n/2);
        //


        for(int coluna=1; coluna <= metade; coluna++)
        {
            printf("*");
        }
        printf("\n");
    }
}
