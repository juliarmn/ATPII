#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int num;
  struct list *prox;
} lista;

lista *busca(lista *head, lista *tail, int num) {
  lista *aux;
  aux = head;
  while (aux != NULL) {
    if (aux->num == num) {
      return (aux);
    }
    aux = aux->prox;
  }
  return (NULL);
}

void insere_lista_ordenado(lista **head, lista **tail, int num) {
  lista *aux, *aux_ant, *novo = malloc(sizeof(lista));
  novo->num = num;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    (*head)->prox = NULL;
    return;
  }
  if (num < (*head)->num) {
    novo->prox = *head;
    *head = novo;
    return;
  }
  if (num > (*tail)->num) {
    (*tail)->prox = novo;
    novo->prox = NULL;
    *tail = novo;
  }
  aux_ant = *head;
  aux = (*head)->prox;
  while (aux != NULL) {
    if (num < aux->num) {
      novo->prox = aux;
      aux_ant = novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
}

void remover(lista **head, lista **tail, int num) {
  lista *aux, *aux_anterior;
  aux;
  aux_anterior = *head;
  if (*head == NULL) {
    printf("Lista vazia\n");
    return;
  }
  aux = busca(*head, *tail, num);
  if (aux) {
    if (num == (*head)->num) {
      aux = (*head)->prox;
      free(*head);
      *head = aux;
      return;
    }
    if (aux == *tail) {
      *tail = aux_anterior;
    }
    free(aux);
  }
  return;
}

void copia(lista *head, lista **head_1, lista **tail_1) {
  lista *novo = malloc(sizeof(lista));
  novo->num = head->num;
  novo->prox = NULL;
  *head_1 = novo;
  *tail_1 = novo;
  head = head->prox;
  while (head != NULL) {
    novo = malloc(sizeof(lista));
    novo->num = head->num;
    head = head->prox;
    (*tail_1)->prox = novo;
    novo->prox = NULL;
    *tail_1 = novo;
  }
}

void concatena(lista *head, lista *head_1, lista **head_2, lista **tail_2) {
  lista *head_aux = NULL, *tail_aux = NULL;
  copia(head, head_2, tail_2);
  copia(head_1, &head_aux, &tail_aux);
  (*tail_2)->prox = head_aux;
}

void printa(lista *aux) {
  if (aux == NULL) {
    printf("Vazia\n");
  }
  printf("/.../\n");
  while (aux != NULL) {
    printf(" %d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
  printf("/.../\n");
}

void intercala(lista *head, lista *head_1, lista **head_int, lista **tail_int) {
  int i = 0;
  lista *novo = malloc(sizeof(lista));
  novo->prox = NULL;
  novo->num = head->num;
  *head_int = novo;
  *tail_int = novo;
  head = head->prox;
  while (!(head == NULL && head_1 == NULL)) {
    novo = malloc(sizeof(lista));
    novo->prox = NULL;
    if (!(i % 2) && head_1 != NULL) {
      novo->num = head_1->num;
      (*tail_int)->prox = novo;
      *tail_int = novo;
      head_1 = head_1->prox;
    } else if (head != NULL) {
      novo->num = head->num;
      (*tail_int)->prox = novo;
      *tail_int = novo;
      head = head->prox;
    }
    i++;
  }
}

void insere_normal(lista **head, lista **tail, int num) {
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

int main() {
  lista *head = NULL, *tail = NULL, *head_1 = NULL, *tail_1 = NULL, *head_conc = NULL, *tail_conc = NULL;
  int num;
  // for (int i = 0; i < 10; i++) {
  //   scanf("%d ", &num);
  //   insere_lista_ordenado(&head, &tail, num);
  // }
  // printa(head);
  // copia(head, &head_1, &tail_1);
  // printa(head_1);
  // concatena(head, head_1, &head_conc, &tail_conc);
  // printa(head_conc);
  for (int i = 0; i < 10; i++) {
    scanf("%d ", &num);
    insere_normal(&head, &tail, num);
  }
  for (int i = 0; i < 15; i++) {
    scanf("%d ", &num);
    insere_normal(&head_1, &tail_1, num);
  }
  printa(head);
  printa(head_1);
  intercala(head, head_1, &head_conc, &tail_conc);
  printa(head_conc);
  return 0;
}
