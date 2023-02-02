#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *, int);

int main () {
  int *vet;
  int N, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  shell_sort(vet, N);
}

void shell_sort(int *vet, int N) {
  int value, i, j, k, l;
  k = 1;
  while (k < N/2) {
    k = k * 3 + 1;
  }
  while (k != 1) {
    k = k / 3;
    for (l = 0; l < k; l ++) {
      for (i = l + k; i < N; i = i + k) {
        value = vet[i];
        j = i;
        while (j - k >= 0 && vet[j-k] > value) {
          vet[j] = vet[j - k];
          j = j - k;
        }
        vet[j] = value;
      }
    }
  }
}
