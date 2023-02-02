#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 char **palavra;

void ordena (int N) {
 int passos, pot, i, j, l, w;
 char valor[100];
 //Se P está entre N/8 e N/4, pode tirar o log para achar k como potencia de 2
 //tem que corrigir e passar pra int
 pot = (int)log2(N/4);
 passos = (int)pow(2, pot);
 //Achou primeiro passo, implementa shell
 while (passos != 0) {
  for (l = 0; l < passos; l ++) {
    for (i = l + passos; i < N; i = i + passos) {
      strcpy(valor, palavra[i]);
      j = i;
      while (j - passos >= 0 && strcmp(valor, palavra[j-passos]) < 0) {
        strcpy(palavra[j], palavra[j-passos]);
        j = j - passos;
      } 
      strcpy(palavra[j], valor);
    }
  }
  for (w = 0; w < N; w ++) {
    printf("%s ", palavra[w]);
  }
   printf("\n");
  passos = passos / 2;
 }
}

int main () {
  int N, i;
  scanf("%d", &N);
  palavra = malloc(sizeof(char*)*(N+1));
  for (i = 0; i < N; i ++) {
    palavra[i]=malloc(sizeof(char)*100);
  }
  for (i = 0; i < N; i ++) {
    scanf("%s", palavra[i]);
  }
  ordena(N);
  return 0;
}
