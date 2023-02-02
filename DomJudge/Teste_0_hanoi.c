#include <stdio.h>
#include <stdlib.h>
int K; // K representa os movimentos
int pinoA[20] = {0}, pinoB[20] = {0}, pinoC[20] = {0};
int auxiliar;
int count = 0;

void arruma(int origem, int dest, int N) {
  int flag = 0;
  int i;
  if (origem == 1 && dest == 2) {
    pinoB[N - 1] = N;
    pinoA[N - 1] = 0;
  } else if (origem == 1 && dest == 3) {
    pinoC[N - 1] = N;
    pinoA[N - 1] = 0;
  } else if (origem == 2 && dest == 1) {
    pinoA[N - 1] = N;
    pinoB[N - 1] = 0;
  } else if (origem == 2 && dest == 3) {
    pinoC[N - 1] = N;
    pinoB[N - 1] = 0;
  } else if (origem == 3 && dest == 1) {
    pinoA[N - 1] = N;
    pinoC[N - 1] = 0;
  } else {
    pinoB[N - 1] = N;
    pinoC[N - 1] = 0;
  }
  count ++;
  if (count == K) {
    for (i = 0; i < auxiliar; i++) {
      if(pinoA[i] != 0){
         printf("%d ", pinoA[i]);
        flag = 1;
      } 
    }
    if(flag == 0){
      printf("0");
    }
    printf("\n");
    flag  = 0;
    for (i = 0; i < auxiliar; i++) {
     if(pinoB[i] != 0){
         printf("%d ", pinoB[i]);
       flag = 1;
       } 
    }
    if(flag == 0){
      printf("0");
    }
    printf("\n");
    flag = 0;
    for (i = 0; i < auxiliar; i++) {
     if(pinoC[i] != 0){
         printf("%d ", pinoC[i]);
       flag = 1;
      } 
    }
    if(flag == 0){
      printf("0");
    }
    printf("\n");
  }
}

void hanoiRecursiva(int n, int inicio, int dest, int aux) {
  int i;
  if (n == 1) {
    arruma(inicio, dest, n);
  } else {
    hanoiRecursiva(n - 1, inicio, aux, dest);
    arruma(inicio, dest, n);
    hanoiRecursiva(n - 1, aux, dest, inicio);
  }
}

int main(void) {
  int N, i, j = 0; // N sÃ£o os discos
  scanf("%d", &N);
  scanf("%d", &K);
  auxiliar = N;
  if (N != 0 && K != 0) {
    for(i = 0; i < N; i ++){
      pinoA[i] = i + 1;
    }
    hanoiRecursiva(N, 1, 3, 2);
  } else if(K == 0) {
    for(i = 1; i <= N; i ++){
      printf("%d ", i);
    }
    printf("\n0\n0\n");
  } else if (N == 0) {
    printf("0\n0\n0\n");
  }

  return 0;
}
