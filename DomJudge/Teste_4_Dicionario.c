#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Uso de duas listas
typedef struct dic {
  char string[100];
  struct dic *prox;
} Diderot;

int busca(Diderot *head, Diderot *tail, char *str) {
  Diderot *aux;
  if (head == NULL) {
    return 0;
  }
  if (!strcmp(str, head->string)) {
    return 1;
  }
  if (!strcmp(str, tail->string)) {
    return 1;
  }
  aux = head;
  while (aux != NULL) {
    if (!strcmp(str, aux->string)) {
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}

void insere(Diderot **head, Diderot **tail, char *str) {
  if (busca(*head, *tail, str)) {
    return;
  }
  Diderot *aux, *aux_ant, *novo;
  novo = malloc(sizeof(Diderot));
  strcpy(novo->string, str);
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  if (strcmp(novo->string, (*head)->string) <= 0) {
    novo->prox = *head;
    *head = novo;
    return;
  }
  if (strcmp(novo->string, (*tail)->string) >= 0) {
    (*tail)->prox = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  aux = (*head)->prox;
  aux_ant = *head;
  while (aux != NULL) {
    if (strcmp(novo->string, aux->string) <= 0) {
      novo->prox = aux;
      (aux_ant)->prox = novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
}

void print(Diderot *head) {
  Diderot *aux;
  aux = head;
  while (aux != NULL) {
    printf("%s ", aux->string);
    aux = aux->prox;
  }
  printf("\n");
}

void remover(Diderot **head, Diderot **tail, char *str) {
  Diderot *aux, *aux_ant;
  if (*head == NULL) {
    printf("NULL\n");
    return;
  }
  if (!strcmp(str, (*head)->string)) {
    if ((*head)->prox == NULL) {
      free(*head);
      *head = NULL;
      printf("NULL\n");
      return;
    }
    aux = (*head)->prox;
    free(*head);
    *head = aux;
    print(*head);
    return;
  }
  aux = (*head)->prox;
  aux_ant = *head;
  while (aux != NULL) {
    if (!strcmp(str, aux->string)) {
      aux_ant->prox = aux->prox;
      if (aux == *tail) {
        *tail = aux_ant;
      }
      free(aux);
      break;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
  print(*head);
}

int main() {
  int N;  // Num inicial de palavras
  int M;  // num operacoes
  int i;
  char str[100];
  int op;
  Diderot *head = NULL, *tail = NULL;
  scanf("%d", &N);
  scanf("%d", &M);
  for (i = 0; i < N; i++) {
    scanf("%s", str);
    insere(&head, &tail, str);
  }
  for (i = 0; i < M; i++) {
    scanf("%d", &op);
    switch (op) {
      case 0: {
        scanf("%s", str);
        remover(&head, &tail, str);
        break;
      }
      case 1: {
        scanf("%s", str);
        insere(&head, &tail, str);
        break;
      }
    }
  }
  return 0;
}
