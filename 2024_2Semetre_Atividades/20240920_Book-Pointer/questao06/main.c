#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int i;
    int k;
    i = 42;
    k = i;
    p = &i;

    //k = 75;
    //*k = 75;
    //p = 75;
    *p = 75;

    printf("%i\n", i);
}
