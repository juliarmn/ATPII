#include <stdio.h>
#include <stdlib.h>

int busca_bin(int *, int,  int);

int main () {
  int *vet;
  int N, num, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  scanf("%d", &num);
  printf("%d", busca_bin(vet, N, num));
}

int busca_bin(int *vet, int N, int value) {
  int mid, begin = 0, end = N - 1;
  if (vet[begin] == value) {
    return begin;
  }
  if (vet[end] == value) {
    return end;
  }
  mid = (begin + end) / 2;
  while (begin < end && vet[mid] != value) {
    if (value < vet[mid]) {
      begin = mid;
    } else {
      end = mid;
    }
    mid = (begin + end) / 2;
  }
  if (value == vet[mid]) {
    return mid;
  } else {
    return -1;
  }
}
