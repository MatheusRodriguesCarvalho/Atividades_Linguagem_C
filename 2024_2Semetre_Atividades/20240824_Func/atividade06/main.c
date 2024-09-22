#include <stdio.h>
#include <stdlib.h>

float Reajuste_Salarial(float salario, float percentual)
{
    float salarioAjustado;
    salarioAjustado = salario * (1 + (percentual / 100));
    return salarioAjustado;
}

int main()
{
    float salario, ajuste;
    printf("Qual o salario que sera ajustado: R");
    scanf("%f", &salario);
    printf("E o percentual do ajuste (em Porcentagem): ");
    scanf("%f",&ajuste);

    printf("O salario ajustado eh de R %.2f", Reajuste_Salarial(salario, ajuste) );

    return 0;
}
