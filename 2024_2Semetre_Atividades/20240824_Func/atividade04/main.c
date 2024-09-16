#include <stdio.h>
#include <stdlib.h>


#define mes_padrao 30
#define ano_padrao 365

int idade_em_dias(int ano, int mes, int dia)
{
    int idade;
    idade = (ano * ano_padrao) + (mes * mes_padrao) + dia;
    return idade;
}


int main()
{
    int i_ano, i_mes, i_dia;

    printf("Quantos anos voce tem? (em numero) ");
    scanf("%i", &i_ano);

    printf("E quantos messes? (em numero) ");
    scanf("%i", &i_mes);

    printf("E quantos dias? (em numero) ");
    scanf("%i", &i_dia);

    printf("\nEntao voce tem %i dias vividos.", idade_em_dias(i_ano, i_mes, i_dia) );

    return 0;
}
