#include <stdio.h>
#include <stdlib.h>

void ordena(int N, int k, double *vet) {
  int i, j, maior;
  double  aux;
  for (i = 1; i <= k; i++) {
    aux = vet[i];
    j = i;
    while (j > 0 && vet[j - 1] > aux) {
      vet[j] = vet[j - 1];
      j--;
    }
    vet[j] = aux;
  }
   for (i = k; i < N; i++) {
    aux = vet[i];
    j = i;
    while (j > k && vet[j - 1] < aux) {
      vet[j] = vet[j - 1];
      j--;
    }
    vet[j] = aux;
  }
}

int main() {
  int N, i, k;
  double *vet;
  scanf("%d", &N);
  vet = malloc(N * sizeof(double));
  scanf("%d", &k);
  for (i = 0; i < N; i++) {
    scanf("%lf", &vet[i]);
  }
  ordena(N, k, vet);
  for(i = 0; i < N; i ++) {
    printf("%.3lf ", vet[i]);
  }
  return 0;
}
