#include <stdio.h>
#include <stdlib.h>
//Protótipos:
void pegaMatriz(int *, int);
void apresenta(int *, int);
int magico(int *, int);

int main(void) {
  int N, **matriz, i;
  printf("Digite a ordem da matriz\n");
  scanf("%d", &N);
  matriz = malloc(N * sizeof(int *));
  for(i = 0; i < N; i ++){
    matriz[i] = malloc(N * sizeof(int *));
  }
  pegaMatriz(&matriz[0][0], N);
  apresenta(&matriz[0][0], N);
  if(magico(&matriz[0][0], N) == 1){
    printf("\nS");
  }else{
    printf("\nN");
  }
  return 0;
}

void pegaMatriz(int *matriz, int N){
  int i, j;
  for(i = 0; i < N * N; i ++){
    scanf("%d", &(*matriz));
    matriz ++;
  }
}

void apresenta(int *matriz, int N){
  int i;
  for(i = 0; i < N * N; i ++){
    printf(" [ %d ] ", *matriz);
    matriz ++;
  }
}

int magico(int *matriz, int N){
  int aux[N][N], i, j, linha[N], coluna[N], diagonal1 = 0, diagonal2 = 0, flag = 1;
  for(i = 0; i < N; i ++){
    linha[i] = 0;
    coluna[i] = 0;
  }
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      aux[i][j] = *matriz;
      matriz++;
    }
  }
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      linha[i] += aux[i][j];
      coluna[i] += aux[j][i];
      if(i == j){
        diagonal1 += aux[i][j];
      }
      if(i + j == N -1){
        diagonal2 += aux[i][j];
      }
    }
  }
  for(i = 0; i < N - 1; i ++){
    if(linha[i] == linha[i + 1]){
      if(coluna[i] == coluna[i + 1]){
        flag = 1;
      }
    }else{
      flag = 0;
      
    }
  }
  if(flag == 1){
    if(coluna[0] == linha[0] && diagonal1 == coluna[0] && diagonal2 == coluna[0]){
      return 1;
    }
  }else{
    return 0;
  }
  return 0;
 }
