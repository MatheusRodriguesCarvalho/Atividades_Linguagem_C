#include <stdio.h>
#include <stdlib.h>

/*






*/

void conversor_tempo(int tempo, int * ano, int * mes, int * dia, int * hora, int * min, int * seg)
{
    *ano = 1;
    *mes = 2;
    *dia = 3;
    *hora = 4;
    *min = 5;
    *seg = 6;
}

int main()
{
    int tempo, ano, mes, dia, hora, minuto, segundo;
    printf("Digite o tempo em Segundos: ");
    scanf("%i", &tempo);

    conversor_tempo(tempo, &ano, &mes, &dia, &hora, &minuto, &segundo);

    printf("Ano: %i / Mes: %i / Dia: %i - ", ano, mes, dia);
    printf("%i:%i:%i", hora, minuto, segundo);

    return 0;
}
