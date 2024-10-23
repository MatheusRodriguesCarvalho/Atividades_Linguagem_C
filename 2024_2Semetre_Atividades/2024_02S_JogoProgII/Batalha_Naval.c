#include <stdio.h>
#include <stdlib.h>
#include <locale.h>







void Menu()
{
    int opcao = 0;
    while(opcao != 4)
    {
        system("cls");
        printf("\n+-- Batalha Naval --+\n");
        printf("\n1 - Configurar");
        printf("\n2 - Jogar");
        printf("\n3 - Como Jogar");
        printf("\n4 - Sair");

        printf("Digite o numero da Opcao:");
        fflush(stdin);
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1:
            //funcao
            break;
        case 2:
            //funcao
            break;
        case 3:
            //funcao
            break;
        default
            printf("\nOpcao invalida!");
            break;
        }
        fflush(stdin);
        getchar();
    }
}







int main (void)
{
    Menu();
    return 0;
}
