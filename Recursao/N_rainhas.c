#include <stdio.h>
#include <stdlib.h>
#define size 4
// Protótipo:
int valido(int, int);
int rainha(int);
// Globais:
int tabuleiro[size][size] = {{0}, {0}, {0}, {0}};

int main(void){
  int i, j;
  rainha(0);
  for (i = 0; i < size; i++){
    printf("\n");
    for (j = 0; j < size; j++){
      printf(" [%d] ", tabuleiro[i][j]);
    }
  }
  return 0;
}

int rainha(int n){
  int i;
  for (i = 0; i < size; i++){
    tabuleiro[n][i] = 1;
    if (n == size - 1 && valido(n, i)){
      return 1;
      }else if (n < size - 1 && valido(n, i) && rainha(n + 1)){
      return 1;
    }
    tabuleiro[n][i] = 0;
  }
  return 0;
}

int valido(int n, int j) {
  int auxLinha, auxColuna;
    for (auxLinha = n - 1; auxLinha >= 0; auxLinha--){
      if (tabuleiro[auxLinha][j] == 1){
        return 0;
      }
    }
    auxLinha = n - 1;
    for(auxColuna = j - 1; auxColuna >= 0; auxColuna --){
      if(tabuleiro[auxLinha][auxColuna] == 1){
        return 0;
      }
      auxLinha --;
    }
    auxLinha = n - 1;
    for(auxColuna = j + 1; auxColuna < size; auxColuna ++){
      if(tabuleiro[auxLinha][auxColuna] == 1){
        return 0;
      }
      auxLinha --;
    }
  return 1;
  }
