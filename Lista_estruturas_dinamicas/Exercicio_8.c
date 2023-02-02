#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int num;
  int prox;
} Pilha;

Pilha vet[81];

void empilha(int *topo, int num) {
  int i;
  if (*topo == -1) {
    *topo = 0;
  }
  for (i = 1; i < 81; i++) {
    if (vet[i].prox == -1) {
      vet[i].num = num;
      vet[i].prox = *topo;
      *topo = i;
      return;
    }
  }
}

void desempilha(int *topo) {
  int i, aux = *topo;
  if (vet[*topo].prox == 0) {
    *topo = -1;
    vet[aux].prox = -1;
    return;
  }
  *topo = vet[*topo].prox;
  vet[aux].prox = -1;
}

void printa(int topo) {
  if (topo == -1) {
    return;
  }
  printf("/---/\n");
  while (vet[topo].prox != 0) {
    printf("%d\n", vet[topo].num);
    topo = vet[topo].prox;
  }
  printf("%d\n", vet[topo].num);
  printf("/---/\n");
}

int main() {
  int i, num, prim_topo = -1, seg_topo = -1, op_pilha, op_operacao;
  vet[0].prox = 0;
  for (i = 1; i < 81; i++) {
    vet[i].prox = -1;
  }
  do {
    scanf("%d", &op_pilha);
    scanf("%d", &op_operacao);
    switch (op_operacao) {
      case 1: {
        scanf("%d", &num);
        if (!op_pilha) {
          empilha(&prim_topo, num);
          break;
        }
        empilha(&seg_topo, num);
        break;
      }
      case 2: {
        if (!op_pilha) {
          printa(prim_topo);
          break;
        }
        printa(seg_topo);
        break;
      }
      case 3: {
        if (!op_pilha) {
          desempilha(&prim_topo);
          break;
        }
        desempilha(&seg_topo);
        break;
      }
    }
  } while (op_pilha != -1);
}
