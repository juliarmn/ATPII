#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);

int main () {
  int *vet;
  int N, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  insertion_sort(vet, N);
}

void insertion_sort(int *vet, int N) {
  int aux, i, j;
  for (i = 1; i < N; i ++) {
    aux = vet[i];
    j = i;
    while (j > 0 && vet[j-1] > aux) {
      vet[j] = vet[j - 1];
      j  --;
    }
    vet[j] = aux;
  }
}
