#include <stdio.h>
#include <stdlib.h>

int busca_bin(int *, int, int, int);

int main () {
  int *vet;
  int N, num, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  scanf("%d", &num);
  busca_bin(vet, num, 0, N-1);
}

int busca_bin(int *vet, int value, int begin, int end) {
  int mid;
  mid = mid = (begin + end) / 2;
  if (begin >= end ) {
    return -1;
  }
  if (vet[mid] == value) {
    return mid;
  }
  if (vet[mid] < value) {
    busca_bin(vet, value, mid, end);
  } else {
    busca_bin(vet, value, begin, mid);
  }
}
