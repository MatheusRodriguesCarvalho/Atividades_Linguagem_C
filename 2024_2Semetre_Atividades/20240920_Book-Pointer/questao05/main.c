#include <stdio.h>
#include <stdlib.h>

int main()
{
char c = 'T', d = 'S';
char *p1 = &c;
char *p2 = &d;
char *p3;

p3 = &d;
printf("%c\n\n",*p3);// retorno: S

p3 = p1;
printf("%c\n\n",*p3);// retorno: T

*p1 = *p2;
printf("%c\n\n",*p1);// retorno: S

}
