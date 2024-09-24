#include <stdio.h>
#include <stdlib.h>

void mapa_definir (char *mapa, int linha, int coluna)
{
    for (int y = 0; y < linha; y++) //loop no mapa, com o tamanho corrente para definir as posicoes
    {
        for (int x = 0; x < coluna; x++)
        {
            if (y == 0 || x == 0 || y == linha - 1 || x == coluna - 1)
            {
                *mapa = '#';
            }
            else if (x == 2 && y == 2)
            {
                *mapa = 'P';
            }
            else if (x == coluna - 2 && y == linha - 2)
            {
                *mapa = '@';
            }
            else
            {
                *mapa = ' ';
            }
            mapa++;
        }
    }
}

