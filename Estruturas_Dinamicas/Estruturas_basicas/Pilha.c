#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
  int num;
  struct Pilha *embaixo;
} pilha;

void printa(pilha *topo) {
  if(topo == NULL){
    printf("Não tem elemento na pilha\n");
    return;
  }
  printf("/---/\n");
  while(topo != NULL){
    printf("%d\n", topo->num);
    topo = topo->embaixo;
  }
  printf("/---/\n");
}

pilha *empilha(pilha *topo, pilha *elemento) {
  elemento->embaixo = topo;
  return elemento;
}

pilha *tira(pilha **topo) {
  pilha *aux = *topo;
  if (!*topo) {
    printf("\nNão tem o que tirar\n");
    return(NULL);
  }
  *topo = aux->embaixo;
  return(aux);
}

int main () {
  pilha  *topo = NULL;
  int op;
  do {
    printf("1)Empilhar\n2)Tirar\n3)Mostrar\n");
    scanf("%d", &op);
    switch(op) {
      case 1: {
        pilha *elemento = malloc(sizeof(pilha));
        printf("Digite o num:\n");
        scanf("%d", &elemento->num);
        topo = empilha(topo, elemento);
        break;
      }
      case 2: {
        free(tira(&topo));
        break;
      }
      case 3: {
        printa(topo);
        break;
      }
    }
  } while (op != 0);
  return 0;
}
