#include <stdio.h>
#include <stdlib.h>

  int matriz[10000][10000];

int verifica_menor( int N, int a, int b) {
  int i, j, menor = 2*N*N;
  for (i = a; i <= b; i++) {
    for (j = a; j <= b; j++) {
      if (matriz[i][j] < menor) {
        menor = matriz[i][j];
      }
    }
  }
  return menor;
}

int main() {
  int N, M, a, b;
  int i, j;
  scanf("%d", &N);
  scanf("%d", &M);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  for (i = 0; i < M; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", verifica_menor(N, a - 1, b - 1));
  }
  return 0;
}
