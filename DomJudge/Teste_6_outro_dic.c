#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dic {
  char palavra[100];
  struct dic *prox;
} dicionario;

int busca(dicionario *head, char *str) {
  if (head == NULL) {
    return 0;
  }
  while (head != NULL) {
    if (!(strcmp(str, head->palavra))) {
      return 1;
    }
    head = head->prox;
  }
  return 0;
}

void insere(dicionario **head, dicionario **tail, char *str) {
  if (busca(*head, str)) {
    return;
  }
  dicionario *aux, *aux_ant, *novo;
  novo = malloc(sizeof(dicionario));
  strcpy(novo->palavra, str);
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  if (strcmp(novo->palavra, (*head)->palavra) <= 0) {
    novo->prox = *head;
    *head = novo;
    return;
  }
  if (strcmp(novo->palavra, (*tail)->palavra) >= 0) {
    (*tail)->prox = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  aux = (*head)->prox;
  aux_ant = *head;
  while (aux != NULL) {
    if (strcmp(novo->palavra, aux->palavra) <= 0) {
      novo->prox = aux;
      (aux_ant)->prox = novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
}

void remover(dicionario **head, dicionario **tail, char *str) {
  dicionario *aux, *aux_ant;
  if (*head == NULL) {
    return;
  }
  if (!strcmp(str, (*head)->palavra)) {
    if ((*head)->prox == NULL) {
      free(*head);
      *head = NULL;
      return;
    }
    aux = (*head)->prox;
    free(*head);
    *head = aux;
    return;
  }
  aux = (*head)->prox;
  aux_ant = *head;
  while (aux != NULL) {
    if (!strcmp(str, aux->palavra)) {
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
}

dicionario *acha_posicao(dicionario *head, char *str) {
  if(head == NULL) {
    return NULL;
  }
  while (head != NULL && strcmp(head->palavra, str) < 0) {
    head = head->prox;
  }
  return head;
}

void printa(dicionario *elem, char *str) {
  if (elem == NULL) {
    printf("NULL\n");
    return;
  }
  while (elem != NULL) {
    printf("%s ", elem->palavra);
    elem = elem->prox;
  }
  printf("\n");
}

int main() {
  int N, M, i, op;
  char str[100];
  dicionario *head = NULL, *tail = NULL, *elem = NULL;
  scanf("%d", &N);
  scanf("%d", &M);
  for (i = 0; i < N; i++) {
    scanf(" %s", str);
    insere(&head, &tail, str);
  }
  for (i = 0; i < M; i++) {
    scanf("%d", &op);
    scanf(" %s", str);
    switch (op) {
      case 1: {
        insere(&head, &tail, str);
        break;
      }
      case 0: {
        remover(&head, &tail, str);
        break;
      }
      case 2: {
        elem = acha_posicao(head, str);
        printa(elem, str);
        break;
      }
    }
  }
  return 0;
}
