#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
//#include <unistd.h>


#define MAP_SPACE ' '

//problema na regeracao das cordenadas da saida

//ideias
/*

- 3 dimensoes: onde aparace no canto um "1/5" para indicar quantas profundidas tem e em qual delas o jogador estC!
    - poderia ser uma torre!! ou calabouC'o!!!
- geraC'C#o e leitura de seeds
    - mapas variaveis e fases
- Mundo aberto (??)
- sistema de inventario e itens para aumentar os status do jogador

-status em um vetor, como vida[2]
    -vida[0] = vida corrente
    -vida[1] = vida maxima



*/

//- MAPA (torre/calabouco)
//-- Fase ou andar
int mapa_max_coluna = 14, mapa_max_linha = 7;
int y, x, andar = 1; // OU FASE
//-- Saida
int sx = 0, sy = 0;
//Outros
int aleatorio, condicao = 0;


//- PLAYER
//-- Position
int px = 2, py = 2;
//-- Status
// Indice 0 e a vida corrente | o indice 1 e a vida maxima
int p_life[2] = { 15 , 19 };
int p_stamina = 5, p_str = 4;
int inventario[3];				//Espacos no inventario, ACHAR UM JEITO DE RETORNAR NOMES E STATUS
//-- Outros
char comando;
int acao_realizada;


//- ENEMY
//-- Position
int ex = 0, ey = 0;
int exx = 0, eyy = 0;
// proximas posicoes para o inimigo, como um indicador de para onde o inimigo ira se mover

//-- Status
int e_life[2] = { 5 , 5 };		// Indice 0 e a vida corrente | o indice 1 e a vida maxima

//GRUPO DE inimigos
//inimigos[QUANTIDADE_INIMIGOS][ATRIBUICOES]
/*
inimigos[2][5] =
[inimigo 1][posicao x][posicao y][vida corrente][vida maxima]
[inimigo 2][posicao x][posicao y][vida corrente][vida maxima]
.
.
.
*/

void tela_limpar () {
  //system ("clear"); // ONLINE GDB
  system("cls"); // CODEBLOCK
  //printf("\e[1;1H\e[2J"); // OUTROS
}
void tela_pausar () {
    // ONLINE GDB
    //int getchar (comando);

    //printf("\nPausa, digite algo e de enter: ");
    //scanf(" %c", &comando); // ONLINE GDB

    //sleep(1);

    // CODEBLOCK
    system("Pause");
}
void init(){
    sx = (int) (mapa_max_coluna * 0.8);
    sy = (int) (mapa_max_linha * 0.8);

    ex = (int) (mapa_max_coluna * 0.7); ey = (int) (mapa_max_linha * 0.7);
    exx = (int) (mapa_max_coluna * 0.7); eyy = (int) (mapa_max_linha * 0.7);

}
void menu_inicial () {
  printf ("--------\n  MENU  \n--------\n");
  tela_pausar ();
  tela_limpar ();
}

void desenhar_mapa ()
{
    printf ("Life: %i/%i | Stamina: %i | Strength: %i \n", p_life[0],
    p_life[1], p_stamina, p_str);

    for (y = 0; y < mapa_max_linha; y++)
    {
        for (x = 0; x < mapa_max_coluna; x++)
        {
            if (y == 0 || x == 0 || y == mapa_max_linha - 1 || x == mapa_max_coluna - 1)
            {
                printf("#");
            }
            else if (x == px && y == py)
            {
                printf("P");
            }
            else if (x == ex && y == ey)
            {
                if (e_life[0] > 0) { printf("E"); } // An enemy
                else { printf("G");} // A Ghost, it may hit the player
            }
            else if (x == exx && y == eyy)
            {
                printf(".");
            }
            else if (x == sx && y == sy)
            {
                printf("@");
            }
            else
            {
                printf("%c", MAP_SPACE);
            }

        }
        printf("\n");
    }
}

void jogador_teleporte ()
{
    // o problema do teleporte, e que ele pode fazer o jogo ficar mais facil
    // pois seria s�
}

void mover_inimigo ()
{

    /*
    fazer alguma coisa para que o inimigo persegua o jogador dado uma certa distancia
        vai seguir o jogador ate um raio 4 e quando chegar nesse raio ter� um movimento aleatorio
    */

    double distancia;
    float fator_perseguicao;
    int deltaX, deltaY;

    //puxar pelo logaritimo para reduzir o numero


    ex = exx;
    ey = eyy;

    deltaX = pow((px - ex), 2);
    deltaY = pow((py - ey), 2);
    distancia = deltaX + deltaY;
    distancia = sqrt(distancia);

    fator_perseguicao = (andar * 4) / e_life[1];

    //printf("\n\npx eh: %i | py eh: %i", px, py);
    //printf("\nex eh: %i | ey eh: %i", ex, ey);
    printf("\nDeltaY eh: %i | Delta Y eh: %i", deltaX, deltaY);
    printf("\nA distancia eh: %0.2f| Fator: %0.2f\n", distancia, fator_perseguicao);
    tela_pausar();


    if (distancia >= fator_perseguicao && e_life[0] > 0){
        //a
        if (deltaX >= deltaY)
        {
            if (px - ex > 0){ exx = exx + 1; }
            else { exx = exx - 1; }
        }
        else if (deltaX < deltaY)
        {
            if (py - ey > 0){ eyy = eyy + 1; }
            else { eyy = eyy - 1; }
        }
    }

    else
    {
        aleatorio = rand () % 4;
        if (aleatorio == 0)
        {
            exx = exx - 1;
            if (exx <= 0) { exx = 1; }
        }
        else if (aleatorio == 2)
        {
            exx = exx + 1;
            if (exx >= mapa_max_coluna - 1) { exx = mapa_max_coluna - 2; }
        }
        else if (aleatorio == 1)
        {
            eyy = eyy - 1;
            if (eyy <= 0) { eyy = 1; }
        }
        else if (aleatorio == 3)
        {
            eyy = eyy + 1;
            if (eyy >= mapa_max_linha - 1) { eyy = mapa_max_linha - 2; }
        }
    }

}

void evento_batalha ()
{

    tela_limpar ();
    printf("----------------------------\n");
    printf("   Entrou em uma batalha!   \n");
    printf("----------------------------\n");
    tela_pausar ();

    int dano, prob_x, prob_max = 10;
    // BATALHA
    while ((e_life[0] > 0) && (p_life[0] > 0)) {

        tela_limpar ();

        printf ("// Vida:     %i/%i  / Inimigo:  %i/%i  //\n", p_life[0], p_life[1], e_life[0], e_life[1]);
        printf ("// Estamina: %i\n", p_stamina);
        printf ("// Forca:    %i\n", p_str);
        printf ("// P-                 -E //\n\n");


        //PLAYER atack

        printf ("\nDigite o Numero da acao desejada.");
        printf ("\n1. Ataque Simples (1 de Dano | 9/10 de acerto )");
        printf ("\n2. Ataque Carregado (3 de Dano | 5/10 de acerto )");
        printf ("\n3. acao x ()"); //utiliza metade da estamina para dar em dano
        printf ("\n4. Descansar ( +1 Vida | +1 Estamina )");
        printf ("\n5. acao y ()"); //se protege, reflete o dano do inimigo para ele proprio

        prob_x = rand () % prob_max;
        //printf ("\nPlayer Probability: %i", prob_x);

        printf ("\nEscolha: ");
        scanf (" %c", &comando);

        switch (comando) {
            case '1':
                printf("\nO Ataque simples... ");
                if (prob_x >= (prob_max * 1 / 10))
                {
                    dano = 1;
                    printf("Acertou!!\n Causando %i de dano ao inimigo.\n", dano);
                }
                else { printf("Errou.\n"); }
                break;
            case '2':
                printf("\nO Ataque Carregado... ");
                if (prob_x >= (prob_max * 5 / 10))
                {
                    dano = 3;
                    printf("Acertou!!\nCausando %i de dano ao inimigo.\n", dano);
                }
                else { printf("Errou.\n"); }
                break;
            case '3':
                printf("\nAcao x");
                p_life[1] = p_life[1] + 1;
                break;
            case '4':
                printf("\nDescansou o suficiente para restaurar suas for�a");
                p_stamina = p_stamina + 1;
                if (p_life[0] >= p_life[1])
                {
                    printf("\n\nNao podera exceder o limite de Vitalidade\n");
                }
                else { p_life[0] = p_life[0] + 1; }
                break;
            case '5':
                printf("\nAcao y");
                p_life[1] = p_life[1] + 2;
                break;
            default:
                printf("\nComando invalido.\nSem acao qualquer valida.\n");
                break;
        }

        e_life[0] = e_life[0] - dano;
        dano = 0;


        //ENEMY's Turn
        prob_x = rand () % prob_max;
        //printf ("\n\n--Enemy Probability: %i--\n", prob_x);

        if (prob_x < (prob_max * 3 / 10) )
        {
            if (prob_x == 0) { dano = 2; }
            else { dano = 1; }

            printf ("\nO inimigo te atacou!!\nEle te causou %i de dano\n", dano);
        }
        p_life[0] = p_life[0] - dano;
        dano = 0;

        tela_pausar ();
    }

    // AFTERMATH
    if (e_life[0] <= 0)
    {
        printf ("Inimigo Derrotado");
        ex = sx; ey = sy; exx = sx;  eyy = sy;
    }
    else if (p_life[0] <= 0) { condicao = 9; printf ("Voce foi derrotado"); }

    tela_limpar();
    printf ("A batalha Acabou!\n");
    tela_pausar ();

    tela_limpar();

}

void acao_executada (char acao)
{
    acao_realizada = 1;
    switch (acao) {
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
            //chama_inventario();
            acao_realizada = 0;
            break;
        default:
            //acao_realizada = 0;
            printf ("Comando invalido.");
            printf ("\nPressione uma tecla para Continuar.");
            tela_pausar ();
            break;
    }

    if (acao_realizada == 0) { mover_inimigo (); }

    if (px == sx && py == sy) { condicao = 1; }
    else if (px == ex && py == ey) { evento_batalha (); }
    else { condicao = 0; }

}

void restaurar_elementos ()
{
    px = 2; py = 2;
    condicao = 0;

    mapa_max_coluna = mapa_max_coluna + 4;
    mapa_max_linha = mapa_max_linha + 2;

    sx = (int) (mapa_max_coluna * 0.95);
    sy = (int) (mapa_max_linha * 0.9);

    ex = (int) (mapa_max_coluna * 0.7); ey = (int) (mapa_max_linha * 0.7);
    exx = ex; eyy = eyy;
    e_life[1] = e_life[1] + 10;
    e_life[0] = e_life[1];

}

void var_validadores()
{
    printf ("\nponto: Posicao x = %i // Posicao y = %i \n", exx, eyy);
    printf ("enemy: Posicao x = %i // Posicao y = %i \n\n", ex, ey);
    printf("O numero aleatorioa foi: %i\n", aleatorio);
}

int main (void)
{
    init();
    menu_inicial ();
    srand (time (NULL));

    for ( ; ; ) {

        desenhar_mapa (); //colocar antes ou depois da acao_executada?

        printf("Mover: W (Cima) / A (Esquerda) / S (Baixo) / D (Direita)\n");
        printf("Interagir: Q  (Inventario) / E (Objetos) / R (Inimigos)\n");

        printf("Digite um Comando para realizar a Acao (lin: %i):", mapa_max_linha);
        scanf(" %c", &comando);
        //fflush(stdin); // CODEBLOCK
        comando = tolower (comando);

        acao_executada (comando);

        tela_limpar ();

        if (condicao == 1) {
            printf ("Voce saiu do andar %i\n\n", andar);
            tela_pausar();
            tela_limpar();

            andar = andar + 1;
            restaurar_elementos();

        }
        if (condicao == 9)
        { printf ("Sua Jornada Acabou..."); break; }

    }

}
