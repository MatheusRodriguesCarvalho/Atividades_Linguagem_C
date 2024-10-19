#include <stdio.h>
#include <stdlib.h>


/*
registros ssçao estruturas de dados que conseguem armazenar dados de tipos diferentes
sera utilizado o "struct"


typedef: cria um tipo de variavel, como em um registro


*/

typedef struct{
    char nome[50];
    char estado[20];
    int idade;
    chat sexo;
} tipopessoa;
/*

*/


int main()
{
    tipopessoa pessoa1, pessoa2;

    strcpy(pessoa1.nome, "Nome generico numero 17");
    strcpy(pessoa2.nome, "Bolsolula Messias Inacio");

    tipopessoa pessoa[5];// cria um vetor, onde cada elemento do vetor eh uma variavel do tipo "tipopessoa"
    return 0;
}
