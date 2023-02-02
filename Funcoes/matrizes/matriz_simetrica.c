#include <stdio.h>
#include <stdlib.h>
//Protótipos:
void pega(float *, int);
void mostra(float *, int);
int sim(float *, int);

int main(void) {
  float **matrix;
  int N, i;
  printf("Digite a ordem da matriz quadrada\n");
  scanf("%d", &N);
  matrix = malloc(N * sizeof(int *));
  for(i = 0; i < N; i ++){
    matrix[i] = malloc(N * sizeof(int *));
  }
  pega(&matrix[0][0], N);
  mostra(&matrix[0][0], N);
  if(sim(&matrix[0][0], N) == 1){
    printf("\nÉ simétrica\n");
  }else{
    printf("\nNão é simétrica\n");
  }
  return 0;
}

void pega(float *matriz, int N){
  int i;
  for (i = 0; i < N * N; i++) {
    printf("\nDigite o elemento na respectiva posição\n");
    scanf("%f", &(*matriz));
    matriz++;
  }
}

void mostra(float *matriz, int N){
  printf("\t----> MATRIZ <----\n");
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("[ %.2f ]", *matriz);
      matriz++;
    }
    printf("\n");
  }
}

int sim(float* matrix, int N){
  int i, j;
  float aux[N][N];
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      aux[i][j] = *matrix;
      matrix ++;
    }
  }
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      
        if(j < i){
          if(aux[i][j] != aux[j][i]){
            return 0;
          }else{
            return 1;
          }
      }
    }
  }
  return 0;
 }
