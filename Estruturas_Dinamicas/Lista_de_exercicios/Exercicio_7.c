#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  char c;
  struct lista *prox;
} pilha;

void empilha(pilha **topo, char carac) {
  pilha *elemento = malloc(sizeof(pilha));
  elemento->c = carac;
  elemento->prox = *topo;
  *topo = elemento;
}

void printa(pilha *topo) {
  if (topo == NULL) {
    printf("Vazio");
    return;
  }
  while (topo != NULL) {
    printf("%c", topo->c);
    topo = topo->prox;
  }
  printf("\n");
}

int get_tam(pilha *topo) {
  int tam = 0;
  if (topo == NULL) {
    return 0;
  }
  while (topo != NULL) {
    tam++;
    topo = topo->prox;
  }
  return tam;
}

void desempilha(pilha **topo) {
  pilha *aux = *topo;
  if (*topo == NULL) {
    printf("Vazia\n");
    return;
  }
  *topo = (*topo)->prox;
  free(aux);
}

void verifica_pal(pilha *topo) {
  pilha *topo_verifica = NULL, *aux = topo;
  int i, tam;
  tam = get_tam(topo);

  for (i = 0; i < tam / 2; i++) {
    empilha(&topo_verifica, aux->c);
    aux = aux->prox;
    desempilha(&topo);
  }
  printa(topo);
  printa(topo_verifica);

  aux = topo;
  if (tam % 2) {
    desempilha(&topo);
  }
  for (i = 0; i < tam / 2; i++) {
    if (topo->c == topo_verifica->c) {
      desempilha(&topo_verifica);
      desempilha(&topo);
    }
  }
  printf("%d", get_tam(topo_verifica));
}

int main() {
  char letra;
  pilha *topo = NULL;
  do {
    scanf("%c", &letra);
    if (letra != '\n')
      empilha(&topo, letra);
  } while (letra != '\n');
  // printa(topo);
  verifica_pal(topo);
  return 0;
}
