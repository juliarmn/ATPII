#include <stdio.h>
#include <stdlib.h>
// Protótipos:
void PegaMatriz(int *, int);
void apresenta(int *, int);
int verificaLinha(int *, int);
int permuta(int);

int main(void) {
  int **matriz;
  int N, i;
  printf("\nDigite a ordem da matriz quadrada\n");
  scanf("%d", &N);
  matriz = malloc(N * sizeof(int *));
  for (i = 0; i < N; i++) {
    matriz[i] = malloc(N * sizeof(int *));
  }
  PegaMatriz(&matriz[0][0], N);
  apresenta(&matriz[0][0], N);
  if (verificaLinha(&matriz[0][0], N) == 1) {
    printf("Sim\n");
  } else {
    printf("Não\n");
  }
  return 0;
}

void PegaMatriz(int *matriz, int N) {
  int i;
  for (i = 0; i < N * N; i++) {
    printf("\nDigite o elemento na respectiva posição\n");
    scanf("%d", &(*matriz));
    matriz++;
  }
}

void apresenta(int *matriz, int N) {
  printf("\t----> MATRIZ <----\n");
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("[ %d ]", *matriz);
      matriz++;
    }
    printf("\n");
  }
}

int verificaLinha(int *matriz, int N) {
  int aux[N][N], i, j, k, flag = 1, permut[N];
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      aux[i][j] = *matriz;
      matriz++;
    }
  }
  for (i = 0; i < N; i++) {
    permut[i] = 1;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      permut[i] *= aux[i][j];
    }
    j = 0;
    if (permut[i] == permuta(N)) {
      for (k = 0; k < N; k++) {
        if (aux[i][j] == aux[i][k] && j != k) {
          return 0;
        } else {
          return 1;
        }
        j++;
      }
    } else {
      return 0;
    }
  }
  return 0;
}

int permuta(int N) {
  int permutacao;
  if (N == 1) {
    return 1;
  }
  permutacao = N * permuta(N - 1);
  return (permutacao);
}
