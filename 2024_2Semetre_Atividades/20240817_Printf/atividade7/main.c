#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%i", &n);

    for(int linha = 1; linha <= n; linha++ ){
        for(int coluna = 1; coluna <= n + 2; coluna++ ){

            if( linha != 1 && linha != n && coluna != 1 && coluna != n+2 )
            {printf(" ");}
            else if( (linha == 1 || linha == n) && ( coluna == 1 || coluna == n+2) )
            {printf("O");}
            else
            {printf("-");}

        }
        printf("\n");
    }
}
