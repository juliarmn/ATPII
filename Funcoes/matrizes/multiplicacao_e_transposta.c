#include <stdio.h>
#define size 3
#define n 2

void pega_matriz(double *);
void transpoe(double[size][n]);
void multiplica(double [size][size], double [size][size], double [size][size]);

int main(void) {
  double matA[size][size], matB[size][size], matC[size][n], matJ[size][size];
  pega_matriz(&matC[0][0]);
  //pega_matriz(&matA[0][0]);
  //pega_matriz(&matB[0][0]);
  transpoe(matC);
  for(int i =0; i < size; i ++){
    for(int j = 0; j < size; j ++){
      matJ[i][j] = 0;
    }
  }
  //multiplica(matA, matB, matJ);
  //for(int i = 0; i < size; i ++){
    //printf("\n");
    //for(int j = 0; j < size; j ++){
      //printf("%.2lf", matJ[i][j]);
   // }
 // }
  return 0;
}

void pega_matriz(double *mat) {
  int i;
  for (i = 0; i < size * size; i++) {
    scanf("%lf", &(*mat));
    mat++;
  }
}
void transpoe(double mat[size][n]) {
  double nova[n][size];
  for (int i = 0; i < size; i++) {
    printf("\n");
    for (int j = 0; j < n; j++) {
      nova[j][i] = mat[i][j];
      printf(" [ %.2lf ] ", nova[j][i]);
    }
  }
}
void multiplica(double A[size][size], double B[size][size], double M[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) { // menor que coluna A
        M[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
