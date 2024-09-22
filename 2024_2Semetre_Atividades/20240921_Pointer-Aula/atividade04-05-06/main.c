#include <stdio.h>
#include <stdlib.h>

/*06 - qual o problema no programa a seguir?*/
int main()
{
    int x, *p;
    x = 10;
    *p = x;/*o problema esta nessa linha, pois:
    1 - o ponteiro nao esta a fazer referencia a nenhuma outra variavel.
    2 - seria preciso atribuir um endereco de memoria ao ponteiro, nao o proprio valor da variavel.
    ajuste sugerido: p = &x; (thumbs up)
    */
    printf("Valor: %d\n", *p);
}

/*
04 - diferenca entre:

p++;
Este esta "movendo" / incrementando o endereco de MEMORIA em uma Unidade,
fazendo com que a referencia associada ao ponteiro mude.

(*p)++;
Esta incrementando o VALOR do qual o ponteiro esta apontando em uma Unidade.

*(p++);
Ira "pegar" o VALOR que o ponteiro aponta, incrementando uma Unidade no endereco de Memoria.
*/

/*
05 - o que dizer de *(p + 10) ?

o ponteiro ira apontar para uma valor em um endereco de memoria que esteja a 10 "passos" a "frente"
em relacao ao endereco de memoria que estiver atribuido na variavel p.
*/
