#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NOME 50

typedef struct{ int Bomba; int Aberto; int aoRedor; int Bloqueado; } tpCelula;

typedef struct{ char Nome[MAX_NOME]; int Pontuacao; int JogadasRealizadas; }
tpJogador;


void Limpar_Jogador(tpJogador *j)
{

    for (int i = 0; i < MAX_NOME; i++)
    {
        j->Nome[i] = '\0';
    }
    j->JogadasRealizadas = 0;
    j->Pontuacao = 0;
}

void Gravar_Nome(tpJogador *Jogador)
{
    printf("\nDigite o seu nome: ");
    fflush(stdin);
    fgets(Jogador->Nome, MAX_NOME, stdin);
}

//Pega o Campo e desenha na tela
void Desenhar_Campo(tpCelula *Campo, int tamanho)
{
    //system("cls");
    printf("\n-   ");
    for(int i = 0; i<tamanho;i++)
    {
        if(i >= 10){ printf("%i",i); }
        else{ printf("%i ",i); }
    }
    printf("\n\n");

    for(int linha = 0; linha < tamanho; linha++)
    {
        if(linha>=10){printf("%i| ",linha);}
        else{printf("%i | ",linha);}

        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if ((Campo + coluna + linha * tamanho)->Aberto == 0)
            {
                printf("%c ", 254);
            }
            else
            {
                if ((Campo + coluna + linha * tamanho)->Bomba == 1)
                {
                    printf("* ");
                }
                else
                {
                    if((Campo + coluna + linha * tamanho)->Bloqueado == 1)
                    {
                        printf("& ");
                    }
                    else
                    {
                        printf("%i ", (Campo + coluna + linha * tamanho)->aoRedor);
                    }
                }
            }

        }
        printf("| %i", linha);
        printf("\n");
    }
}

//Quando perder, a posicao das bombas serao revelados
void Revela_Bombas(tpCelula *Campo, int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if( (Campo + coluna + linha * tamanho)->Bomba)
            {
                (Campo + coluna + linha * tamanho)->Aberto = 1;
            }
        }
    }
}

void Fim_Jogo(tpCelula *Campo, int tamanho, int lin, int col)
{
    system("cls");
    Revela_Bombas(Campo, tamanho);
    Desenhar_Campo(Campo, tamanho);
    printf("\nHavia uma bomba na cordenada %ix%i\n", lin, col);
    printf("E voce pisou nela. Fim de Jogo\n");
}

//Gerando o relatorio em aruivo .rlt
void Gerar_Relarotio(tpCelula *Campo, int celulasRestantes, tpJogador *Jogador)
{
    int pontuacao = (200 - celulasRestantes) * Jogador->JogadasRealizadas;

    FILE *relatorio;
    relatorio = fopen("Relatorio.rlt", "wb");

    if(relatorio == NULL)
    {
        printf("\nNao foi possivel Gerar o Relatorio!");
    }
    else
    {
        fprintf(relatorio, "\nJogador: ");
        fwrite(Jogador->Nome, MAX_NOME, 1, relatorio);
        fprintf(relatorio, "\nJogadas Realizadas:  ");
        fprintf(relatorio, "%i \n", Jogador->JogadasRealizadas);
        fprintf(relatorio, "\nPontuacao:  ");
        fprintf(relatorio, "%i \n", pontuacao);
        fprintf(relatorio, "\nCampo: ");
        fwrite(Campo, sizeof(tpCelula), 1, relatorio);

        fclose(relatorio);
    }

}

//Valida as coordenadas em relacao ao tamanho estabelacido
int Validacao_Coordadeda(int linha, int coluna, int tamanho)
{
    return (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho);
}

//Calcula a quantidade de Bombas ao redor da Celula
int Bombas_Proximas(tpCelula *Campo, int linha, int coluna, int tamanho)
{
    int quantidade = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(Validacao_Coordadeda(linha + i, coluna + j, tamanho) && (Campo + (coluna + j) + (linha + i) * tamanho)->Bomba)
            {
                quantidade++;
            }
        }
    }
    return quantidade;
}

//Atribui a quantidade de bombas ao redor de uma determinada celula, de todas as celulas
void Contar_Bombas(tpCelula *Campo, int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            (Campo + coluna + linha * tamanho)->aoRedor = Bombas_Proximas(Campo, linha, coluna, tamanho);
        }
    }
}

//Posiciona as bombas em celulas aleatorias, se repitir uma posicao, ele retorna
void Posicionar_Bombas(tpCelula *Campo, int tamanho, int quantidadeBombas)
{
    srand(time(NULL));
    for(int i = 1; i <= quantidadeBombas; i++)
    {
        int linha = rand() % tamanho;
        int coluna = rand() % tamanho;
        if((Campo + coluna + linha * tamanho)->Bomba == 0)
        {
            (Campo + coluna + linha * tamanho)->Bomba = 1;
        }
        else
            i--;
    }
}

//Inicializa e Limpa cada Celula do Campo
void Inicializar(tpCelula *Campo, int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            (Campo + coluna + linha * tamanho)->Bomba = 0;
            (Campo + coluna + linha * tamanho)->Aberto = 0;
            (Campo + coluna + linha * tamanho)->aoRedor= 0;
        }
    }
}

//Define a Dificuldade do Jogo
void Configurar_Campo(int * tamanho, int * quantidadeBombas)
{
    char dificuldade;

    printf("\nSelecionar a Dificuldade...");
    do
    {
        printf("\nA - Facil (10x10, 20 Bombas)");
        printf("\nB - Medio (12x12, 30 Bombas)");
        printf("\nC - Dificil (15x15, 40 Bombas)");
        printf("\nDigite sua Escolha:");
        fflush(stdin);
        scanf("%c", &dificuldade);
        dificuldade = toupper(dificuldade);
        system("cls");
        //condicional
    }
    while (dificuldade != 'A' && dificuldade != 'B' && dificuldade != 'C');

    switch (dificuldade)
    {
    case 'A':
        *tamanho = 10;
        *quantidadeBombas = 20;
        break;
    case 'B':
        *tamanho  = 12;
        *quantidadeBombas = 30;
        break;
    case 'C':
        *tamanho  = 15;
        *quantidadeBombas = 40;
        break;
    }
}

//Loop nas celulas ao redor da coordenada( lin x col )
//abrindo a celula caso seja Zero ou esteja ao redor de um Zero
//passivel de Recursividade, por motivos de porque sim
void Abrir_Zeros(tpCelula *Campo, int lin, int col, int tamanho)
{
    int vizinho = 1;
    int aberto = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int nova_linha = (lin + i);
            int nova_coluna = (col + j);

            vizinho = (Campo + col + lin * tamanho)->aoRedor;
            aberto = (Campo + nova_coluna + nova_linha * tamanho)->Aberto;
            if( (Validacao_Coordadeda(nova_linha, nova_coluna, tamanho)) && vizinho == 0 && aberto == 0)
            {
                (Campo + nova_coluna + (nova_linha * tamanho) )->Aberto = 1;
                Abrir_Zeros(Campo, nova_linha, nova_coluna, tamanho);
                //printf("ok1");
            }
            //printf("\n fim j (%i x %i), r = %i\n", i, j, vizinho);
        }
        //printf("\nPAUSA VERIFICADORA\n");
        //getchar();
    }
}

void Bloquear_Celula(tpCelula *Campo, int lin, int col)
{

}

//Repeticao do loop para jogar
void Game_Loop(tpCelula *Campo, int tamanho, int quantidadeBombas)
{
    int lin, col;
    int continuar = 1;
    //algumas estatisticas
    int celulasRestantes = tamanho * tamanho - quantidadeBombas;
    tpJogador Jogador;
    Limpar_Jogador(&Jogador);

    while(continuar)
    {
        system("cls");
        Desenhar_Campo(Campo, tamanho);
        printf("\nHa %i espacos sem Bombas.", celulasRestantes);
        printf("Digite um valor negativo para poder bloquear uma Celula.");
        printf("\nDigite a linha:");
        fflush(stdin);
        scanf("%i", &lin);
        printf("Digite a Coluna:");
        fflush(stdin);
        scanf("%i", &col);
        fflush(stdin);

        //Verificar
        if (celulasRestantes <= 1)
        {
            printf("\nVoce finalizou o Jogo.\n");
            printf("\nO Campo foi limpo sem nenhuma bomba ter sido acertada.");
            Gravar_Nome(&Jogador);
            Gerar_Relarotio(Campo, celulasRestantes, &Jogador);
            continuar = 0;
            system("cls");
        }
        else if( Validacao_Coordadeda(lin, col, tamanho) )
        {
            Jogador.JogadasRealizadas++;
            if( (Campo + col + lin * tamanho)->Bomba)
            {
                Fim_Jogo(Campo, tamanho, lin, col);
                Gravar_Nome(&Jogador);
                Gerar_Relarotio(Campo, celulasRestantes, &Jogador);

                continuar = 0;
                system("cls");
            }
            else
            {
                if( (Campo + col + lin * tamanho)->Aberto)
                {
                    printf("\nCoordenada ja foi escolhida!");
                    printf("\nInforme outra coordenada.\n");
                    getchar();
                }
                else
                {
                    celulasRestantes--;
                    (Campo + col + lin * tamanho)->Aberto = 1;
                    Abrir_Zeros(Campo, lin, col, tamanho);
                }
            }
        }
        else
        {
            if(col < -1 || lin < -1)
            {
                Bloquear_Celula(Campo, lin, col);
            }
            else
            {
                printf("Coordenada informada eh invalida!");
                getchar();
            }
        }
    }
}

//Inicializacao de algumas variaveis
void Jogar()
{

    int tamanho = 10;
    int quantidadeBombas = 0;
    Configurar_Campo(&tamanho, &quantidadeBombas);

    tpCelula Campo[tamanho][tamanho];

    Inicializar(Campo, tamanho);
    Posicionar_Bombas(Campo, tamanho, quantidadeBombas);
    Contar_Bombas(Campo, tamanho);

    Game_Loop(&Campo, tamanho, quantidadeBombas);

}

//Exibe o tutorial do jogo
void Tutorial()
{
    system("cls");
    printf("\nInstruções do Jogo:\n");
    printf("Haverá um determinado Numero de Bombas espalhadas pelo Campo.\n");
    printf("Seu objetivo eh Selecionar todas as calulas que nao possuirem bomba.\n");
    printf("Voce precisara escolher uma coordenada de linha e coluna para abrir a celula.\n");
    printf("Os numeros nas celulas abertas indicaram a quantidade de bombas nas celulas ao redor.\n\n");
    getchar();
}

//Menu
void Menu()
{
    int opcao = 0;

    while (opcao != 3)
    {
        system("cls");
        printf("\n---------------------------\n");
        printf("\n BEM VINDO AO CAMPO MINADO \n");
        printf("\n---------------------------\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Instrucoes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            Jogar();
            break;
        case 2:
            Tutorial();
            break;
        case 3:
            printf("\nSaindo do jogo. Ate logo!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

int main()
{
    Menu();
    return 0;
}
