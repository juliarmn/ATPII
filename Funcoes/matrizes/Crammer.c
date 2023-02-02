#include <stdio.h>
#define max 3
//Protótipos:
void pegaMatriz(double* , double*);
double determinante(double [max][max]);
double trocaMatriz(double*, double*, int);

int main(void) {
  int i, j;
  double det, resultadosParte2[max];
  double matriz[max][max], resultado[max] = {0};
  pegaMatriz(&matriz[0][0], &resultado[0]);
  for(i = 0; i < max; i ++){
    for(j = 0; j < max; j ++){
      printf("[ %.2lf ]", matriz[i][j]);
    }
    printf("\n");
  }
  det = determinante(matriz);
  if(det == 0){
    printf("\nNão\n");
  }else{
    for(i = 0; i < 3; i ++){
      resultadosParte2[i] = trocaMatriz(&matriz[0][0], &resultado[0], i);
    }
    printf("\n\nResultados:\n");
    printf("Determinante: %.2lf\n", det);
    printf("X: %.2lf\n", resultadosParte2[0]/det);
    printf("Y: %.2lf\n", resultadosParte2[1]/det);
    printf("Z: %.2lf\n", resultadosParte2[2]/det);
  }
  return 0;
}

void pegaMatriz(double *matrix, double *results){
  int i;
  for(i = 0; i < max*max; i ++){
    scanf("%lf", &(*matrix));
    matrix++;
  }
  for(i = 0; i < max; i ++){
    scanf("%lf", &(*results));
    results++;
  }
}

double determinante(double matriz[3][3]){
  double det;
  det = ((matriz[0][0]*matriz[1][1]*matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0]) +
            (matriz[0][2]*matriz[1][0]*matriz[2][1]) - (matriz[0][0]*matriz[1][2]*matriz[2][1]) -
            (matriz[0][1]*matriz[1][0]*matriz[2][2]) - (matriz[0][2]*matriz[1][1]*matriz[2][0]));
  return det;
}

double trocaMatriz(double *matriz, double *resultado, int coluna){
  double aux[max][max];
  int i, j;
  for(i = 0; i < max; i ++){
    for(j = 0; j < max; j ++){
      aux[i][j] = *matriz;
      matriz ++;
    }
  }
  for(i = 0; i < max; i ++){
    aux[i][coluna] = *resultado;
    resultado ++;
  }
  for(i = 0; i < max; i ++){
    for(j = 0; j < max; j ++){
      printf("[ %.2lf ]", aux[i][j]);
    }
    printf("\n");
  }
  return(determinante(aux));
}
