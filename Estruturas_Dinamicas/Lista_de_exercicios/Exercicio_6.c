#include <stdio.h>
#include <stdlib.h>

typedef struct listinha {
  int num;
  struct listinha *prox;
  struct listinha *ant;
} lista;

void insere(lista **head, lista **tail, int num) {
  lista *novo = malloc(sizeof(lista));
  novo->num = num;
  novo->prox = NULL;
  if (*head == NULL) {
    *head = *tail = novo;
    return;
  }
  (*tail)->prox = novo;
  *tail = novo;
}

void retira_par(lista **head, lista **tail) {
  lista *aux = *head, *aux2;
  if (*head == NULL) {
    printf("Vazia\n");
    return;
  }
  while (aux != NULL) {
    if (!(aux->num % 2)) {
      if (aux == *head) {
        if ((*head)->prox == NULL) {
          free(*head);
          *head = NULL;
          *tail = NULL;
          return;
        }
        aux->prox->ant = NULL;
        *head = aux->prox;
      } else if (aux == *tail) {
        aux->ant->prox = NULL;
        *tail = aux->ant;
      } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
      }
      aux2 = aux;
      aux = aux->prox;
      free(aux2);
    } else {
      aux = aux->prox;
    }
  }
}

void printa(lista *head) {
  lista *aux = head;
  if (head == NULL) {
    printf("\nvazia\n");
  }
  while (aux != NULL) {
    printf("[%d] ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}

int main() {
  lista *head = NULL, *tail = NULL;
  int num;
  for (int i = 0; i < 10; i++) {
    scanf("%d ", &num);
    insere(&head, &tail, num);
  }
  printa(head);
  retira_par(&head, &tail);
  printa(head);
  return 0;
}
