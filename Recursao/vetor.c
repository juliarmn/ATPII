#include <stdio.h>
#define size 5
int primeiro = 0;
//Protótipos:
int verificaVetor(int, int[], int);

int main(void) {
  int vetor[size], eleMermo;
  for(int i = 0; i < size; i ++){
    scanf("%d", &vetor[i]);
  }
  printf("\nDigite o elemento que deseja encontrar\n");
  scanf("%d", &eleMermo);
  printf("%d", verificaVetor(eleMermo, vetor, size));
  return 0;
}

int verificaVetor(int eleMermo, int vetor[], int n){
  if(n == 0){
    if(eleMermo == vetor[n]){
      return 1;
    }else{
      return -1;
    }
  }else{
    if(eleMermo == vetor[n]){
      return 1;
    }else{
      return verificaVetor(eleMermo, vetor, n-1);
    }
  }
}
