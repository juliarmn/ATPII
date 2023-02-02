#include <stdio.h>
#include <stdlib.h>

typedef struct listinha {
  int num;
  struct listinha *prox;
} lista;

lista *head = NULL, *tail = NULL;

void insere_principal(int num) {
  lista *novo = malloc(sizeof(lista));
  novo->num = num;
  if (head == NULL) {
    head = novo;
    tail = novo;
    (head)->prox = NULL;
    return;
  }
  tail->prox = novo;
  tail = novo;
  novo->prox = NULL;
}

void insere_A(lista **head_a, lista **tail_a) {
  lista *novo = malloc(sizeof(lista));
  novo->num = head->prox->num;
  novo->prox = NULL;
  *head_a = novo;
  *tail_a = novo;

  lista *aux = *tail_a, *aux_2 = head->prox->prox;
  while (aux_2 != NULL) {
    novo = malloc(sizeof(lista));
    novo->num = aux_2->num;
    aux->prox = novo;
    novo->prox = NULL;
    aux = aux->prox;
    aux_2 = aux_2->prox;
  }
  aux->prox = malloc(sizeof(lista));
  aux->prox->num = head->num;
  *tail_a = aux->prox;
  (*tail_a)->prox = NULL;
}

void insere_B(lista **head_b, lista **tail_b) {
  lista *novo = malloc(sizeof(lista));
  novo->num = head->num;
  *head_b = novo;
  *tail_b = novo;
  novo->prox = NULL;
  lista *aux = head->prox;
  lista *aux_ant = novo;
  while (aux != NULL) {
    novo = malloc(sizeof(lista));
    novo->num = aux->num;
    novo->prox = aux_ant;
    aux_ant = novo;
    aux = aux->prox;
  }
  *head_b = aux_ant;
}

int get_size(lista *head) {
  int i = 0;
  while (head != NULL) {
    head = head->prox;
    i++;
  }
  return i;
}

void insere_C(lista **head_c, lista **tail_c) {
  lista *novo = malloc(sizeof(lista)), *aux, *aux_2;
  lista *head_aux, *tail_aux;
  insere_B(&head_aux, &tail_aux);
  aux = head;
  aux_2 = head_aux;
  *head_c = novo;
  *tail_c = novo;
  novo->num = (head->num) + (head_aux->num);
  novo->prox = NULL;
  aux = aux->prox;
  aux_2 = aux_2->prox;
  int max_size = get_size(aux), i = 1;
  while (i < max_size) {
    novo = malloc(sizeof(lista));
    novo->num = aux->num + aux_2->num;
    (*tail_c)->prox = novo;
    (*tail_c) = novo;
    novo->prox = NULL;
    aux = aux->prox;
    aux_2 = aux_2->prox;
    i = i + 2;
  }
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
  printf("/.../\n");
}

int main() {
  lista *head_a = NULL, *tail_a = NULL, *head_b = NULL, *tail_b = NULL, *tail_c = NULL, *head_c = NULL;
  int num;
  for (int i = 0; i < 10; i++) {
    scanf("%d ", &num);
    insere_principal(num);
  }
  printa(head);
  // insere_A(&head_a, &tail_a);
  // printa(head_a);
  // insere_B(&head_b, &tail_b);
  // printa(head_b);
  insere_C(&head_c, &tail_c);
  printa(head_c);
  return 0;
}
