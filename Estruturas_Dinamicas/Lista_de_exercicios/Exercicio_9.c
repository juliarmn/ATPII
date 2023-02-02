#include <stdio.h>
#include <stdlib.h>

void empilha(int *topo, int num, int pilha[], int tam) {
  if (*topo == tam) {
    printf("Pilha cheia\n");
    return;
  }
  pilha[*topo] = num;
  *topo = *topo + 1;
}

void desempilha(int *topo, int pilha[]) {
  *topo = *topo - 1;
}

void busca_num(int *topo, int num, int pilha[], int tam) {
  int topo_aux = 0;
  int aux = *topo - 1;
  int *pilha_aux = malloc(tam * sizeof(int));
  if (*topo == 0) {
    printf("Pilha vazia\n");
    return;
  }
  while (pilha[aux] != num) {
    empilha(&topo_aux, pilha[aux], pilha_aux, tam);
    *topo = *topo - 1;
    aux = aux - 1;
  }
  if (aux < 0) {
    printf("Elemento não encontrado\n");
    return;
  }
  printf("Elemento a  ser retirado: %d\n", pilha[aux]);
  *topo = *topo - 1;
  while (topo_aux > 0) {
    empilha(topo, pilha_aux[topo_aux - 1], pilha, tam);
    desempilha(&topo_aux, pilha_aux);
  }
}

void printa(int topo, int pilha[]) {
  if (topo == 0) {
    printf("Pilha vazia\n");
    return;
  }
  topo = topo - 1;
  printf("/---/\n");
  while (topo >= 0) {
    printf("%d\n", pilha[topo]);
    topo = topo - 1;
  }
  printf("/---/\n");
}

int main() {
  int tam, num, topo = 0, op;
  int *pilha;
  printf("Digite a quatidade de num na pilha\n");
  scanf("%d", &tam);
  pilha = malloc(tam * sizeof(int));
  do {
    printf("1)Insere\n2)Acha num\n3)Printa\n0)sai\n");
    scanf("%d", &op);
    switch (op) {
      case 1: {
        printf("Digite o num que queres inserir\n");
        scanf("%d", &num);
        empilha(&topo, num, pilha, tam);
        break;
      }
      case 2: {
        printf("Digite o num\n");
        scanf("%d", &num);
        busca_num(&topo, num, pilha, tam);
        break;
      }
      case 3: {
        printa(topo, pilha);
      }
    }
  } while (op != 0);
}
