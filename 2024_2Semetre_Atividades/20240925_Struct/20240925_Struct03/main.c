#include <stdio.h>
#include <stdlib.h>

/*
Esquema de estruturas aninhadas-

continuar:
https://www.geeksforgeeks.org/structures-c/
--Structure Pointer in C

https://www.programiz.com/c-programming/c-structures
*/
struct filho
{
    int x;
    int y;
};

struct pai
{
    int x;
    struct filho filho;
};

int main()
{
    struct pai pai;
    pai.x = 10;
    printf("pai.x = %d\n", pai.x);
    pai.filho.x = 15;
    printf("pai.filho.x = %d\n", pai.filho.x);
    pai.filho.y = 20;
    printf("pai.filho.y = %d\n", pai.filho.y);
}
