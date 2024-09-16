#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero:");
    scanf("%i", &n);

    for(int x = n; x > 0; x--)
    {

        for(int y = x; y > 0; y--)
        {
            printf("-");
        }


        printf("*");


        for(int y = 0; y < (n-x); y++)
        {
            printf("-*");
        }

        printf("\n");
    }
}
