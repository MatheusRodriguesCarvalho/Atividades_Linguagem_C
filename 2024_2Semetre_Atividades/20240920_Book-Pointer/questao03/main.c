#include <stdio.h>
#include <stdlib.h>

int main()
{
int contador = 10, *temp, soma=0;
//temp = &count;
//*temp = 20;
temp = &soma;
*temp = 5;
printf("contador = %d, temp = %d, soma = %d\n",contador, temp, soma);
}
