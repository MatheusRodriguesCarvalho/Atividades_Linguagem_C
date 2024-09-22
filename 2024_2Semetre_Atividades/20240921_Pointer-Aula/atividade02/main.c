#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra[2] = {'a', 'b'}, *px, *py;
    letra[1] = letra[0];
    //letra + 1 = letra;

    px = &letra[0];
    py = px;

    printf("%x -- %c", py, *py); // endereco de letra[0] e valor de letra[0]

}
