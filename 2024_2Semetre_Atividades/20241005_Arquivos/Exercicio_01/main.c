#include <stdio.h>
#include <stdlib.h>

#define Tamanho 50

void CodificarDecodificar(int *caractere, int modo)
{
    if (modo == 0) // codificar
    {
        if (*caractere == 'a'){*caractere = 'z';}
        else if (*caractere == 'A') {*caractere = 'Z';}
        else if (*caractere == 'e') {*caractere = 'y';}
        else if (*caractere == 'E') {*caractere = 'Y';}
        else if (*caractere == 'i') {*caractere = 'x';}
        else if (*caractere == 'I') {*caractere = 'X';}
        else if (*caractere == 'o') {*caractere = 'w';}
        else if (*caractere == 'O') {*caractere = 'W';}
        else if (*caractere == 'u') {*caractere = '*';}
        else if (*caractere == 'U') {*caractere = '*';}
    }
    else if (modo == 1) // decodificar
    {
        switch (*caractere)
        {
        case 'z':
            *caractere = 'a';
            break;
        case 'y':
            *caractere = 'e';
            break;
        case 'x':
            *caractere = 'i';
            break;
        case 'w':
            *caractere = 'o';
            break;
        case '*':
            *caractere = 'u';
            break;
        case 'Z':
            *caractere = 'A';
            break;
        case 'Y':
            *caractere = 'E';
            break;
        case 'X':
            *caractere = 'I';
            break;
        case 'W':
            *caractere = 'O';
            break;
        }
    }
}

void codificarArquivo()
{
    FILE *textobase, *textocodif;
    int carac;

    textobase = fopen("Texto_Base.txt", "r");
    if (textobase)
    {
        textocodif = fopen("Texto_Codificado.txt", "w");

        if (textocodif)
        {
            carac = fgetc(textobase);
            while( carac != EOF)
            {
                CodificarDecodificar(&carac, 0);
                fputc(carac, textocodif);
                carac = fgetc(textobase);
            }
            fclose(textocodif);
        }
        else
        {
            printf("Ocorreu um erro na criacao do arquivo.");
        }
        fclose(textobase);
    }
    else
    {
        printf("Ocorreu um erro na abertura do arquivo.");
    }

}

void decodificarArquivo()
{
    FILE *texto_codif, *texto_descodif;
    int carac;

    texto_codif = fopen("Texto_Codificado.txt", "r");
    if (texto_codif)
    {

        texto_descodif = fopen("Texto_Descodificado.txt", "w");
        if(texto_descodif)
        {
            carac = fgetc(texto_codif);

            while( carac != EOF)
            {
                CodificarDecodificar(&carac, 1);
                fputc(carac, texto_descodif);
                carac = fgetc(texto_codif);
            }
            //fputc(carac, texto_descodif);

            fclose(texto_descodif);
        }
        else
        {
            printf("Ocorreu um Error ao criar o arquivo.");
        }
        fclose(texto_codif);
    }
    else
    {
        printf("Ocorreu um Error ao abrir o arquivo.");
    }

}

int main()
{
    codificarArquivo();
    decodificarArquivo();
    //escreverArquivo();
    return 0;
}
