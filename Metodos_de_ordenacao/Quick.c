#include <stdio.h>
#include <stdlib.h>

void quicksort(int *, int, int, int);

int main () {
  int *vet;
  int N, i;
  scanf(" %d", &N);
  vet = malloc(N*sizeof(int));
  for (i = 0; i < N; i ++) {
    scanf(" %d", &vet[i]);
  }
  quicksort(vet, 0, N-1, N);
  for (i = 0; i < N; i ++) {
    printf(" %d", vet[i]);
  }
  return 0;
}

void insertion_sort(int *vet, int N) {
  int aux, i, j;
  for (i = 1; i < N; i ++) {
    aux = vet[i];
    j = i;
    while (j > 0 && vet[j-1] > aux) {
      vet[j] = vet[j - 1];
      j  --;
    }
    vet[j] = aux;
  }
}


void troca(int *valor1, int *valor2) {
  int aux;
  aux = *valor1;
  *valor1 = *valor2;
  *valor2 = aux;
}

void quicksort(int *vet, int inicio, int fim, int tam) {
  int i, pivo, maior;
  if (tam < 24) {//Enquanto ainda tiver mais de uma posição no vetor verificado
    pivo = fim;
    troca(&vet[pivo], &vet[fim]);//Coloca o pivo no fim para facilitar as comparações
    maior = inicio;
    for (i = maior; i < fim; i++) {
      if (vet[i] < vet[fim]) {//Verifica o high e se for igual verifica o low
        troca(&vet[i], &vet[maior]);//Chama a função troca, troca o maior com um elemento que seja menor que o pivo
        maior++;//Agora o meio elemento para a comparação passa a ser o próximo do vetor
      }
    }
    troca(&vet[maior], &vet[fim]);//Quando sai do laço, coloca o pivo no seu devido lugar
    quicksort(vet, inicio, maior - 1, (maior-1-inicio));//Chamada recursiva para a parte de baixo do vetor - ordena ela primeiro
    quicksort(vet, maior + 1, fim, (fim-maior+1));//Chamada recursiva para a parte de cima do vetor
  } else {
    insertion_sort(vet, tam);
  }
}
