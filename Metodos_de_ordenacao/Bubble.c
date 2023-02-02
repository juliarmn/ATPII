#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *, int);

int main () {
  int *vet;
  int N, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  bubble_sort(vet, N);
  for (i = 0; i < N; i ++) {
    printf(" [%d] ", vet[i]);
  }
}

void bubble_sort(int *vet, int N) {
  int aux, i, j, trocou = 1;
  j = N;
  while (trocou) {
    aux = vet[0];
    trocou = 0;
    for (i = 1; i < j; i ++) {
      if (vet[i] < aux) {
        vet[i-1] = vet[i];
        trocou = 1;
      } else {
        vet[i-1] = aux;
        aux = vet[i];
      }
    }
    vet[i-1] = aux;
    j--;
  }
}
