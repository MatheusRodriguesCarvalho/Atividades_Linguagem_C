#include <stdio.h>
#include <stdlib.h>

void conversor_tempo(int tempo, int * ano, int * mes, int * dia, int * hora, int * min, int * seg)

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

void conversor_tempo(int tempo, int * ano, int * mes, int * dia, int * hora, int * min, int * seg)
{
    *ano = (int) (tempo / 31104000);
    *mes = (int) ((tempo % 31104000) / 2592000);
    *dia = (int) (((tempo % 31104000) % 2592000) / 86400);
    *hora = (int) ((((tempo % 31104000) % 2592000) % 86400) / 3600);
    *min = (int) (((((tempo % 31104000) % 2592000) % 86400) % 3600) / 60);
    *seg = (int) (((((tempo % 31104000) % 2592000) % 86400) % 3600) % 60);
}

/*
ano - 12 meses          31.104.000
mes - 30 dias           2.592.000
dia - 24 horas          86.400
hora - 60 minutos       3.600
minuto - 60 segundos    60
segundo - segundo       1
*/
