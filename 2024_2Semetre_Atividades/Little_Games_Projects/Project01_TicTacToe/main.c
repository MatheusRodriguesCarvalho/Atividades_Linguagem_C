#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int main()
{
    game_start();
    return 0;
}

void game_start()
{
    printf("You are going to be X.\n");
    printf("Have fun.\n");
    system("Pause");
    system("cls");

    srand(time(NULL));

    char firstMove = ' ';
    int playing = 1;
    char game_grid[SIZE][SIZE] =
    {
        {' ', '0', '1', '2'},
        {'0', '#', '#', '#' },
        {'1', '#', '#', '#' },
        {'2', '#', '#', '#' }
    };

    who_gonna_start(&firstMove);

    while(playing == 1)
    {
        printf("\n\nObnoxius random text\n\n");
        grid_draw(game_grid);

        the_move(firstMove, game_grid);

        system("Pause");

        //playing = 0;
    }
}

void grid_draw(char *m) //it takes the TTTGrid and draws it
{
    for(int x = 0; x < SIZE; x++)
    {
        for(int y = 0; y < SIZE; y++)
        {
            printf("%c ", *m);
            m++;
        }
        printf("\n");
    }
}
void who_gonna_start(char *choice) //it'll decide who gonna start playing the game
{
    int a = 0;
    while(a == 0) //ponto de melhora
    {
        printf("Chose Head(h) or Tails(t)? ");
        fflush(stdin);
        *choice = toupper(getchar());
        system("cls");

        if ( (*choice == 'H') || (*choice == 'T') )
        {
            a = 1;
        }
        else
        {
            printf("Wrong input. Do it again, and do it right\n");
        }
    }
    a = valor_aleatorio(2);
    printf("Who starts playing is.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    if (a == 0)
    {
        printf(" The player (you)\n\n");
        *choice = 'P';
    }
    else
    {
        printf(" Your oponente (not you)\n\n");
        *choice = 'O';
    }
    system("Pause");
}
int valor_aleatorio(int valor_maximo)
{
    int probabilidade = rand() % valor_maximo;
    return probabilidade;
}

void the_move(char first, char *grid)
{

}
