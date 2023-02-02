#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, int *, int, int);

int main () {
  int *vet;
  int *aux;
  int N, i;
  scanf("%d", &N);
  vet = malloc(N*sizeof(int));
  aux = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    printf("aaa");
    scanf(" %d", &vet[i]);
  }
  mergesort(vet, aux, 0, N-1);
  return 0;
}


void mergesort(int *vet, int *aux, int i , int j) {
  int k, middle, direita, esquerda;
  if (j <= i) {
    return;
  }
  middle = (i + j)/2;
  mergesort(vet, aux, i, middle);
  mergesort(vet, aux, middle + 1, j);
  esquerda = i;
  direita = middle + 1;
  k = 0;
  while (esquerda <= middle && direita <= j) {
    if(vet[esquerda] < vet[direita]) {
      aux[k] = vet[esquerda];
      esquerda ++;
    } else {
      aux[k] = vet[direita];
      direita ++;
    }
    k ++;
  }
  if (esquerda > middle) {
    while (direita <= j) {
      aux[k] = vet[direita];
      k ++;
      direita ++;
    }
  } else {
    while (esquerda <= middle) {
      aux[k] = vet[esquerda];
      k ++;
      esquerda ++;
    }
  }
  for (k = i; k <= j; k ++) {
    vet[k] =aux[k-i];
  }
}
