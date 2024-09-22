#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valores[3][3] = { { 1, 2, 3 }, { 4, 5, 6 } , { 7, 8, 9 } };
    //mesmo em uma suposta matriz, ele aloca os valores na memoria na sequencia da declaracao / atribuicao
    int i, j;
    int *iptr;

    iptr = &valores[0][0];

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d", *iptr);
            iptr ++;
        }
        printf("\n");
    }
}

/*
o printf sera de:
123
456
789
*/
