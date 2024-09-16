#include <stdio.h>
#include <stdlib.h>

float calc_pesoIdeal_Masc(float altura)
{
    float peso;
    peso = (72.7 * altura) - 58;
    return peso;
}

float calc_pesoIdeal_Femi(float altura)
{
    float peso;
    peso = (62.1 * altura) - 44.7;
    return peso;
}

int main()
{
    char sexo = ' ';
    float altura, pesoIdeal;

    while( sexo != 'M' || sexo != 'F')
    {
        printf("Eres do sexo Masculino(M) ou Feminino(F): ");
        scanf(" %c", &sexo);

        switch(sexo)
        {
            case 'M':
                printf("Qual a altura desse macho? ");
                scanf("%f", &altura);
                pesoIdeal = calc_pesoIdeal_Masc(altura);
                printf("O Peso ideal para esse Homem eh %.2f Kg", pesoIdeal );
                return;
                break;
            case 'F':
                printf("Qual a altura desa Beldade? ");
                scanf("%f", &altura);
                printf("O Peso ideal para essa Mulher eh %.2f Kg",calc_pesoIdeal_Femi(altura) );
                return;
                break;
            default:
                system("cls");
                printf("Comando Invalido.\n\n");
                break;
        }
        sexo = 'a';

    }

    printf("Hello world!\n");



    return 0;
}
