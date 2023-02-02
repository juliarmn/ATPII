#include <stdio.h>
#include <stdlib.h>

int busca_bin_crescente(int *, int, int, int);
int busca_bin_decrescente(int *, int, int, int);

int main() {
  int *vet, *busca;
  int N, M, i, cres, decresc;
  scanf("%d", &N);
  vet = malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    scanf("%d", &vet[i]);
  }
  scanf("%d", &M);
  busca = malloc(M * sizeof(int));

  for (i = 0; i < M; i++) {
    scanf("%d", &busca[i]);
  }
  for (i = 0; i < M; i++) {
    cres = busca_bin_crescente(vet, 0, N/2, busca[i]);
    decresc = busca_bin_decrescente(vet, N/2, N - 1, busca[i]);
    if (cres == -1 && decresc == -1) {
      printf("-1 ");
    } else if (cres != -1 && decresc == -1) {
      printf("%d ", cres);
    } else {
      printf("%d ", decresc);
    }
  }
  return 0;
}

int busca_bin_crescente(int *vector, int begin, int end, int valor){
    int busca = (begin + end) / 2;
    if (begin > end) {
        return -1;
    }
    if (vector[busca] == valor) {
        return busca;
    }
    if (vector[busca] < valor) {
        return busca_bin_crescente(vector, busca + 1, end, valor);
    } else {
        return busca_bin_crescente(vector, begin, busca - 1, valor);
    }
}    

int busca_bin_decrescente(int *vector, int begin, int end, int valor){
    int busca = (begin + end) / 2;
    if (begin > end) {
        return -1;
    }
    if (vector[busca] == valor) {
        return busca;
    }
    if (vector[busca] > valor) {
        return busca_bin_decrescente(vector, busca + 1, end, valor);
    } else {
        return busca_bin_decrescente(vector, begin, busca - 1, valor);
    }
}    
