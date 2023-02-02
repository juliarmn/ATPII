#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *, int);

int main () {
  int *vet;
  int N, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  selection_sort(vet, N);
}

void selection_sort(int *vet, int N) {
  int aux, menor, i, j;
  for (i = 0; i < N - 1; i  ++) {
    menor = i;
    for (j = i + 1; j < N; j ++) {
      if (vet[j] < vet[menor]) {
        menor = j;
      }
    }
    if (menor != i) {
      aux = vet[i];
      vet[i] = vet[menor];
      vet[menor] = aux;
    }
  }
}
