#include <stdio.h>
#include <stdlib.h>

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

    char firstMove = ' ';
    int playing = 1;
    char game_grid[4][4] =
    {
        {' ', '0', '1', '2'},
        {'0', '#', '#', '#' },
        {'1', '#', '#', '#' },
        {'2', '#', '#', '#' }
    };

    while(playing == 1)
    {
        who_play(&firstMove);
        grid_draw(game_grid);

        playing = 0;
    }



}

void grid_draw(char *m)
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            printf("%c ", *m);
            m++;
        }
        printf("\n");
    }
}


void who_play(char *choice)
{
    while((*choice != 'h') || (*choice != 't'))
    {
        printf("Chose Head(h) or Tails(t)? ");
        fflush(stdin);
        *choice = getchar();
        //system("cls");
    }

    printf("you did it.");
}


