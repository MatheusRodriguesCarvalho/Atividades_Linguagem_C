#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero:");
    scanf("%i", &n);

    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= x; y++)
        {
            printf("*");
        }
        printf("\n");
    }
}
