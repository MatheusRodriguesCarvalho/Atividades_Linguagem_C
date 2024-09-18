/*
TO EDIT LATER!!
It's was made outside the repository at this stage, by me, who didn't know about some nice pratice
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>


//Informacoes do MAPA
#define MAX_COLUNA 100
#define MAX_LINHA 50
#define MAP_SPACE ' '

int mapa_max_coluna, mapa_max_linha; //sera o tamanho vigente do mapa
char MAPA[MAX_COLUNA][MAX_LINHA]; //criacao do mapa, no tamanho maximo possivel
int y, x, andar; //algumas variaveis de utilizacao livre
int aleatorio, condicao = 0, acao_realizada; //algumas variaveis de utilizacao livre
int sx = 3, sy = 3; //posicao x e y da saida

//Informacoes do JOGADOR
int px, py; //posicao do jogador
int p_life[2]; //Indice 0: vida corrente | Indice 1: vida maxima
int p_forc, abates; //Outros status artibutos
char comando; //variavel da acao do jogador

//Informacoes do INIMIGO
#define INIMIGOS_QUANTIDADE 10 //sobre quantos inimigos haverao
#define INIMIGOS_ATRIBUTOS 5 //sobre quantas informacoes os inimigos terao
#define INIMIGOS_IMAGEM 'I'

int inimigos[INIMIGOS_QUANTIDADE][INIMIGOS_ATRIBUTOS] = {
    1 ,  1 , 5 , 3 , 1 ,
    1 ,  2 , 5 , 2 , 1 ,
    1 ,  3 , 5 , 1 , 0 ,
    1 ,  4 , 6 , 4 , 0 ,
    1 ,  5 , 6 , 5 , 0 ,
    1 ,  6 , 6 , 7 , 0 ,
    1 ,  7 , 7 , 5 , 0 ,
    1 ,  8 , 7 , 6 , 0 ,
    1 ,  9 , 7 , 7 , 0 ,
    1 , 10 , 8 , 8 , 0
    };
    //Informacoes: VIDA, VIDA MAXIMA, X , Y , EXISTENCIA(se o inimigo existe ou nao)
int ex, ey, inimigos_index; //algumas variaveis de utilizacao livre
double fator_perseguicao = 6; //algumas variaveis de utilizacao livre

void tela_limpar () //Limpa a tela
{
  system("cls");
}
void tela_pausar () //Pausa a tela
{
    system("Pause");
}
void init() //Define alguns valores iniciais para algumas variaveis
{
    condicao = 0;

    //Mapa
    andar = 1;
    mapa_max_coluna = 14, mapa_max_linha = 7;
    sx = (int) (mapa_max_coluna * 0.8);
    sy = (int) (mapa_max_linha * 0.8);

    //Jogador
    px = 2, py = 2;
    p_life[0] = 7;
    p_life[1] = 9;
    p_forc = 1, abates = 0;

    //Inimigo
    fator_perseguicao = 7;
    for(x = 0; x < INIMIGOS_QUANTIDADE; x++)
    {
        inimigos[x][0] = x + 1;
        inimigos[x][1] = x + 1;
        ex = (rand () % 4) + 3;
        inimigos[x][2] = ex;
        ey = (rand () % 4) + 3;
        inimigos[x][3] = ey;
        inimigos[x][4] = 0;
    }
    inimigos[0][4] = 1;
}
void menu_inicial () //Menu
{
    printf ("\nEsta em busca de um artefato, perdido no calabouco...\n");
    sleep(3);
    printf ("\nDesca os andares...\n");
    sleep(2);
    printf ("\nEvite os inimigos...\n");
    sleep(2);
    printf ("\nChegue no fim...\n");
    sleep(1);
    printf ("\nObtenha o que voce deseja.\n");
    sleep(3);
    tela_limpar ();
}

void desenhar_mapa () //Ira desenhar o mapa na tela
{
    printf ("Life: %i/%i | Forca: %i \nAndar: %i \n", p_life[0],
    p_life[1], p_forc, andar);

    for ( x = 0 ; x < INIMIGOS_QUANTIDADE ; x++) //loop nos inimigos e define sua posicao no mapa
    {
        if (inimigos[x][4] == 1 && inimigos[x][0] > 0) //isso se, o inimigo existir e tiver vida
        {
            ex = inimigos[x][2];
            ey = inimigos[x][3];

            if ( ex > 0 || ey > 0 || ex < mapa_max_linha - 1 || ey < mapa_max_coluna - 1)
            {
                MAPA[ex][ey] = INIMIGOS_IMAGEM;
            }
            else {
                MAPA[ex][ey] = MAP_SPACE;
            }
        }
    }

    for (y = 0; y < mapa_max_linha; y++) //loop no mapa, com o tamanho corrente para definir as posicoes
    {
        for (x = 0; x < mapa_max_coluna; x++)
        {
            if (y == 0 || x == 0 || y == mapa_max_linha - 1 || x == mapa_max_coluna - 1)
            {
                MAPA[x][y] = '#';
            }
            else if (x == px && y == py)
            {
                MAPA[x][y] = 'P';
            }
            else if (x == sx && y == sy)
            {
                MAPA[x][y] = '@';
            }
            else if (MAPA[x][y] == INIMIGOS_IMAGEM) //isso para nao ficar invisivel
            {
                MAPA[x][y] = INIMIGOS_IMAGEM;
            }
            else
            {
                MAPA[x][y] = MAP_SPACE;
            }
        }
    }

    for (y = 0; y < mapa_max_linha; y++) //loop que da um print com as informacoes do mapa
    {
        for (x = 0; x < mapa_max_coluna; x++)
        {
            printf("%c", MAPA[x][y]);
        }
        printf("\n");
    }

}

void evento_batalha () //Consiste no sistema de batalha do jogo
{
    tela_limpar ();
    printf("----------------------------\n");
    printf("   Entrou em uma batalha!   \n");
    printf("----------------------------\n");
    tela_pausar ();

    int dano = 0, prob_x, prob_max = 10; //Algumas variaveis

    while ((inimigos[inimigos_index][0] > 0) && (p_life[0] > 0)) //Loop da Batalha
    {
        tela_limpar ();

        printf ("// Vida:     %i/%i  / Inimigo:  %i/%i  //\n",
                p_life[0], p_life[1], inimigos[inimigos_index][0], inimigos[inimigos_index][1]);
        printf ("// Forca:    %i\n", p_forc);
        printf ("// P-                 -I //\n\n"); // Representacao da Batalha

        //Lista de Ataque do JOGADOR
        printf ("\nDigite o Numero da acao desejada.");
        printf ("\n1. Ataque Simples (1 x Forca em Dano | 9/10 de acerto )");
        printf ("\n2. Ataque Carregado (3 x Forca em Dano | 4/10 de acerto )");
        printf ("\n3. Descansar ( +1/8 Vida )");
        printf ("\n9. Fugir ( -1 de Vida Corrente e Maxima | -1 da Forca | Inimigo ira para a saida)");

        prob_x = rand () % prob_max; //Define um valor aleatorio
        fflush(stdin);
        printf ("\nEscolha: ");
        scanf (" %c", &comando);

        switch (comando) //Define e altera valores em funcao da escolha do Jogador
        {
            case '1':
                printf("\nO Ataque simples... ");
                if (prob_x >= (prob_max * 1 / 10))
                {
                    dano = 1 * p_forc;
                    printf("Acertou!!\n Causando %i de dano ao inimigo.\n", dano);
                }
                else { printf("Errou.\n"); }
                break;
            case '2':
                printf("\nO Ataque Carregado... ");
                if (prob_x >= (prob_max * 5 / 10))
                {
                    dano = 3 * p_forc;
                    printf("Acertou!!\nCausando %i de dano ao inimigo.\n", dano);
                }
                else { printf("Errou.\n"); }
                break;
            case '3':
                printf("\nDescansou o suficiente para restaurar suas força");
                if (p_life[0] >= p_life[1])
                {
                    printf("\n\nNao pode exceder o limite de Vitalidade\n");
                }
                else { p_life[0] = p_life[0] + (p_life[1] * 1 / 8); }
                break;
            case '9':
                if (p_life[0] - (p_life[0] * 3 / 10) >= 0 )
                {
                    p_life[0] = p_life[0] - 1;
                    if (p_life[1] - 5 > 0) { p_life[1] = p_life[1] - 1; }
                    if (p_forc - 1 > 0) { p_forc = p_forc - 1; }
                    inimigos[inimigos_index][2] = sx;
                    inimigos[inimigos_index][3] = sy;
                    return;
                }
                else
                {
                    printf("\nEsta fraco demais para Fugir.\n");
                    printf("Em vez disso, voce descansou ( +1 Vida | +1 Estamina )\n");
                }
            default:
                printf("\nComando invalido.\nSem acao qualquer valida.\n");
                break;
        }
        inimigos[inimigos_index][0] = inimigos[inimigos_index][0] - dano;
        dano = 0;

        //Turno do INIMIGO
        prob_x = rand () % prob_max; //Define outro valor aleatorio

        if (prob_x < (prob_max * 4 / 10) ) //O inimigo da dano no Jogador
        {
            if (prob_x <= 0) { dano = 1 + 7 * andar / 6; }
            else { dano = 1 + 5 * andar / 8; }

            printf ("\nO inimigo te atacou!!\nE te causou %i de dano\n", dano);
        }
        p_life[0] = p_life[0] - dano;
        dano = 0;

        tela_pausar ();
    }

    //A BATALHA so acaba quando, ou o inimigo, ou o Jogador ficam com 0 de vida
    if (inimigos[inimigos_index][0] <= 0)
    {
        printf ("Inimigo Derrotado");
        ex = 0; ey = 0;
        abates = abates + 1;
    }
    else if (p_life[0] <= 0) { condicao = 9; return;}

    tela_limpar();
    printf ("A batalha Acabou!\n");
    tela_pausar ();
    tela_limpar();
}

void mover_inimigo () //Fara com que o inimigo se mova MELHORAR
{
    double distancia;
    int deltaX, deltaY; //Algumas variaveis

    for( x = 0; x < INIMIGOS_QUANTIDADE; x++) //Loop nos inimigos
    {
        if (inimigos[x][4] == 1 && inimigos[x][0] > 0) //Se ele existir e tiver vida, o inimigo se move
        {
            ex = inimigos[x][2];
            ey = inimigos[x][3]; //Algumas variaveis
            MAPA[ex][ey] = MAP_SPACE; //Problema no print do mapa, isso aqui corrige

            deltaX = pow((px - ex), 2);
            deltaY = pow((py - ey), 2);
            distancia = deltaX + deltaY;
            distancia = sqrt(distancia); //Calculos para fazer o inimigo perseguir o Jogador

            if (distancia >= fator_perseguicao) //Se a distancia for muito grande, o inimigo ira atras do Jogador
            {
                if (deltaX >= deltaY)
                {
                    if (px - ex > 0){ ex = ex + 1; }
                    else { ex = ex - 1; }
                }
                else if (deltaX < deltaY)
                {
                    if (py - ey > 0){ ey = ey + 1; }
                    else { ey = ey - 1; }
                }
            }
            else //Caso contrario, sera um movimento aleatorio
            {
                aleatorio = rand () % 4;
                if (aleatorio == 0)
                {
                    ex = ex - 1;
                    if (ex <= 0) { ex = 1; }
                }
                else if (aleatorio == 2)
                {
                    ex = ex + 1;
                    if (ex >= mapa_max_coluna - 1) { ex = mapa_max_coluna - 2; }
                }
                else if (aleatorio == 1)
                {
                    ey = ey - 1;
                    if (ey <= 0) { ey = 1; }
                }
                else if (aleatorio == 3)
                {
                    ey = ey + 1;
                    if (ey >= mapa_max_linha - 1) { ey = mapa_max_linha - 2; }
                }
            }

            inimigos[x][2] = ex;
            inimigos[x][3] = ey; //Atualiza a posicao do inimigo nos inimigos, sera utilizado no desenhar_mapa

            if (distancia <= 1 && inimigos[x][0] > 0 ) { inimigos_index = x; evento_batalha(); return; }
        }
    }
    tela_pausar();
}

void acao_executada (char acao) //Recebe um valor de ACAO e faz os lances
{
    acao_realizada = 1;
    switch (acao) //Faz a acao do Jogador ai, e boas
    {
        case 's':
            py = py + 1;
            if (py > mapa_max_linha - 2)
                { py = mapa_max_linha - 2; }
            acao_realizada = 0;
            break;
        case 'w':
            py = py - 1;
            if (py < 1)
                { py = 1; }
            acao_realizada = 0;
            break;
        case 'd':
            px = px + 1;
            if (px > mapa_max_coluna - 2)
                { px = mapa_max_coluna - 2; }
            acao_realizada = 0;
            break;
        case 'a':
            px = px - 1;
            if (px < 1)
                { px = 1; }
            acao_realizada = 0;
            break;
        case 'q':
            if (p_life[0] < p_life[1])
            {
                p_life[0] = p_life[0] + 1;
                printf("\n\nVida Restaurada...\n");
            }
            else
            {
                printf("\n\nSua ganancia por vitalidade fez com que algum inimigo se recupesasse...\n");
                aleatorio = rand () % 10;
                inimigos[aleatorio][1] = inimigos[aleatorio][1] + 1;
            }
            acao_realizada = 0;
            acao_realizada = 0;
            break;
        default:
            printf ("Comando invalido.");
            printf ("\nPressione uma tecla para Continuar.");
            tela_pausar ();
            break;
    }

    if (acao_realizada == 0) { mover_inimigo (); if(condicao == 9){return;} } //Vai mover o inimigo, se o Jogador fizer uma acao

    if (px == sx && py == sy) { condicao = 1; }
    else if (MAPA[px][py] == ' ') { condicao = 0; }
}

void restaurar_elementos () //Reedefine os valores de alguns elementos para o inicio de cada andar
{
    //Mapa
    mapa_max_coluna = mapa_max_coluna + 2;
    mapa_max_linha = mapa_max_linha + 1;
    sx = (int) (mapa_max_coluna * 0.9);
    sy = (int) (mapa_max_linha * 0.8);

    //Jogador
    px = 2; py = 2;
    condicao = 0;
    p_life[1] = p_life[1] + 3;
    p_life[0] = p_life[0] + abates;
    abates = 0;
    p_forc = p_forc + 1;

    //Inimigos
    fator_perseguicao = fator_perseguicao - 0.5;
    if (andar <= 10) {
        inimigos[andar][4] = 1;
    }
    for ( x = 0; x < INIMIGOS_QUANTIDADE; x++)
    {
        if (inimigos[x][4] == 1)
        {
            aleatorio = (rand () % mapa_max_coluna - 4) + 3;
            inimigos[x][2] = (int) (aleatorio);
            aleatorio = (rand () % mapa_max_linha - 4) + 3;
            inimigos[x][3] = (int) (aleatorio);
            if (inimigos[x][0] <= 0){
                inimigos[x][1] = inimigos[x][1] + 5;
                inimigos[x][0] = inimigos[x][1];
            }
            else {
                inimigos[x][1] = inimigos[x][1] + 2;
                inimigos[x][0] = inimigos[x][1];
            }
        }
    }

}

int main (void) //O JOGO
{
    menu_inicial ();
    reininiar:
    init();
    srand (time (NULL));

    for ( ; ; ) {
        desenhar_mapa ();

        printf("Movimento: W (Cima) / A (Esquerda) / S (Baixo) / D (Direita)\n");
        printf("Interacao: Q (Descansar + 1 de Vida)\n");
        printf("Digite um Comando para realizar a Acao:");
        scanf(" %c", &comando);
        fflush(stdin);
        comando = tolower (comando);

        acao_executada (comando);
        tela_limpar ();

        if (condicao == 1) // Proximo Andar
        {
            printf ("Voce saiu do andar %i\n\n", andar); tela_pausar(); tela_limpar();
            andar = andar + 1;
            restaurar_elementos();
        }

        if (condicao == 9) // Derrota
        {
            printf ("                     \n");
            printf ("Sua Jornada Acabou...\n");
            printf ("                     \n");
            tela_pausar();
            tela_limpar();
            for ( ; ; )
            {
                printf(" ... mas voce deseja tentar novamente (s/n)? ");
                scanf(" %c", &comando);
                comando = tolower (comando);

                if (comando == 's')
                {
                    printf("\n\n ... entao, Boa Sorte ... \n");
                    condicao = 0;
                    tela_limpar();
                    goto reininiar;
                    break;
                }
                else if (comando == 'n') {
                    printf("\n entao que seja assim ... \n");
                    break;
                }
                else {
                    printf("\nComando Invalido... Digite novamente...\n");
                }
            }
            break;
        }

        if (andar > 15) // Vitoria
        {
            tela_limpar ();
            printf("\nVoce finalmente encontrou o Santo Graal nas profundezas do calabouco ... \n\n");
            printf("        P         \n   ___________    \n  '._==_==_=_.'   \n  .-\:      /-.   \n");
            printf(" | (|:. 1   |) |  \n  '-|:.     |-'   \n    \::.    /     \n     '::. .'      \n");
            printf("       ) (        \n     _.' '._      \n     -=---=-      \n                  \n");
            break;
        }
    }
}
