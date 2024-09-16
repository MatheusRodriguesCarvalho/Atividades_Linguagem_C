#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero:");
    scanf("%i", &n);

    for(int x = 0; x < n; x++)
    {

        for(int y = 0; y < x; y++)
        {
            printf("-");
        }

        printf("*");

        for(int y = 1; y < (n-x); y++)
        {
            printf("-*");
        }

        printf("\n");
    }
}
