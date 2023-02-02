#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
  int num;
  char nome[199];
  struct lista *prox;
  struct lista *ant;
} circ_dupla;

void insere_ordenado(circ_dupla **head, circ_dupla **tail, int num, char *nome) {
  circ_dupla *novo = malloc(sizeof(circ_dupla)), *aux;
  novo->num = num;
  strcpy(novo->nome, nome);
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = novo;
    novo->ant = novo;
    return;
  }
  if ((*head)->prox = *head) {
    (*head)->prox = novo;
    (*head)->ant = novo;
    novo->prox = novo->ant = *head;
    *tail = novo;
    return;
  }
  if (novo->num <= (*head)->num) {
    novo->prox = *head;
    novo->ant = *tail;
    (*head)->ant = novo;
    (*tail)->prox = novo;
    *head = novo;
    return;
  }
  if (novo->num >= (*tail)->num) {
    novo->prox = *head;
    novo->ant = *tail;
    (*head)->ant = novo;
    (*tail)->prox = novo;
    *tail = novo;
    return;
  }
  aux = *head;
  do {
    if (num <= aux->num) {
      novo->prox = aux;
      novo->ant = aux->ant;
      aux->ant->prox = novo;
      aux->ant = novo;
      return;
    }
    aux = aux->prox;
  } while (aux != *head);
}

void retira(circ_dupla **head, circ_dupla **tail, int num) {
  circ_dupla *aux;
  if (*head == NULL) {
    printf("Vazia\n");
    return;
  }
  if (((*head)->prox == NULL) && ((*head)->num = num)) {
    free(*head);
    free(*tail);
    *tail = NULL;
    *head = NULL;
    return;
  }
  if ((*tail)->num == num) {
    aux = *tail;
    aux->ant->prox = (*tail)->prox;
    aux->prox->ant = (*tail)->ant;
    *tail = aux->ant;
    free(aux);
    return;
  }
  aux = *head;
  do {
    if (num == aux->num) {
      aux->ant->prox = aux->prox;
      aux->prox->ant = aux->ant;
      free(aux);
      return;
    }
    aux = aux->prox;
  } while (aux != *head);
}

void printa(circ_dupla *h) {
  if (h == NULL) {
    printf("Lista vazia\n");
    return;
  }
  while (h != NULL) {
    printf("---------------\n");
    printf("Num: %d\n", h->num);
    printf("Nome: %s\n", h->nome);
    printf("---------------\n");
    h = h->prox;
  }
}

int busca(circ_dupla *head, int num) {
  if (head == NULL) {
    printf("Vazia\n");
    return 0;
  }
  do {
    if (head->num == num) {
      return 1;
    }
    head = head->prox;
  } while (head != head);
  return 0;
}

void copia(circ_dupla *head, circ_dupla *tail, circ_dupla **head_1, circ_dupla **tail_1) {
  circ_dupla *novo = malloc(sizeof(circ_dupla));
  novo->num = head->num;
   strcpy(novo->nome, head->nome);
  novo->prox = novo;
  novo->ant = novo;
  *head_1 = novo;
  *tail_1 = novo;
  head = head->prox;
  while (head != tail->prox) {
    novo = malloc(sizeof(circ_dupla));
    novo->num = head->num;
    strcpy(novo->nome, head->nome);
    novo->prox = head->prox;
    novo->ant = head->ant;
    head = head->prox;
    (*tail_1)->prox = novo;
    novo->prox = tail->prox;
    *tail_1 = novo;
  }
}

void concatena(circ_dupla *head, circ_dupla *tail, circ_dupla *head_1, circ_dupla *tail_1, circ_dupla **head_2, circ_dupla **tail_2) {
  circ_dupla *head_aux = NULL, *tail_aux = NULL;
  copia(head, tail, head_2, tail_2);
  copia(head_1, tail_1, &head_aux, &tail_aux);
  (*tail_2)->prox = head_aux;
  tail->prox = head;
  head->ant = tail;
}

void intercala(circ_dupla *head, circ_dupla *tail, circ_dupla *head_1, circ_dupla **head_int, circ_dupla **tail_int) {
  int i = 0;
  circ_dupla *novo = malloc(sizeof(circ_dupla));
  novo->prox = novo;
  novo->ant = novo;
  novo->num = head->num;
  strcpy(novo->nome, head->nome);
  *head_int = novo;
  *tail_int = novo;
  head = head->prox;
  while (!(head == tail->prox && head_1 == tail->prox)) {
    novo = malloc(sizeof(circ_dupla));
    novo->prox = NULL;
    if (!(i % 2) && head_1 != NULL) {
      novo->num = head_1->num;
      strcpy(novo->nome, head_1->nome);
      (*tail_int)->prox = novo;
      *tail_int = novo;
      head_1 = head_1->prox;
    } else if (head != NULL) {
      novo->num = head->num;
      strcpy(novo->nome, head->nome);
      (*tail_int)->prox = novo;
      *tail_int = novo;
      head = head->prox;
    }
    i++;
  }
}

int main () {
  circ_dupla *head = NULL, *tail = NULL, *head_1 = NULL, *tail_1 = NULL, *head_conc = NULL, *tail_conc = NULL, *head_int = NULL, *tail_int = NULL;
  int num;
  circ_dupla *head_2 = NULL, *tail_2 = NULL;
  char nome[100];
  for (int i = 0; i < 10; i++) {
    scanf("%d ", &num);
    scanf(" %[^\n]s", nome);
    insere_ordenado(&head, &tail, num, nome);
  }
  printa(head);
  copia(head, tail, &head_1, &tail_1);
  printa(head_1);
  concatena(head, tail, head_1, tail_1, &head_2, &tail_2);
  printa(head_conc);
  for (int i = 0; i < 10; i++) {
    scanf("%d ", &num);
    insere_ordenado(&head, &tail, num, nome);
  }
  for (int i = 0; i < 15; i++) {
    scanf("%d ", &num);
    insere_ordenado(&head_1, &tail_1, num, nome);
  }
  printa(head);
  printa(head_1);
  intercala(head, tail, head_1, &head_int, &tail_int);
  printa(head_conc);
  return 0;
}
