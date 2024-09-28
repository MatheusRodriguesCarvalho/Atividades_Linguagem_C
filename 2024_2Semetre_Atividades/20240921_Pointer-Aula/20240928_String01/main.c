#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
A4_01) Escreva um programa em C que leia uma string (no máximo 50 caracteres) via teclado e informe a
quantidade de letras “a” presentes na string (podendo ser maiúscula ou minúscula)
*/

int main()
{
  char nome[50] = "Fatec Americana Jogos Digitais";
  int contagem = 0;
  strlwr(nome);

  for (int i = 0; i< strlen(nome); i++)
  {
      if (nome[i] == 'i')
      {
          contagem++;
      }
  }

  printf("ha %d 'a's na string", contagem);
}
