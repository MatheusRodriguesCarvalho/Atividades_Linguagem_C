#include <stdio.h>
#include <stdlib.h>

void troca(int *pa, int *pb);

int main()
{
    int x[5]={0,1,2,3,4};
    troca(x+1, x+4);
    for(int i=0; i<5; i++)
    {
        printf("%i",x[i]);
    }
    /*
    printf("\n\n-- %i -- %p -- %d", *x, x, x);
    printf("\n-- %i -- %p -- %d", x+1, *x+1, x+1);
    printf("\n-- %i -- %p -- %d", x+2, x+2, *x+2);
    printf("\n-- %i -- %p -- %d", *x+3, x+3, x+3);
    printf("\n-- %i -- %p -- %d", x+4, *x+4, x+4);
    */
}

void troca(int *pa, int *pb)
{
    int t;
    t = *pa; *pa = *pb; *pb = t;
}
