#include <stdio.h>
#include <stdlib.h>
// N numero de pessoas
// I idade
// T tempo que chega na fila

// cada pessoa atendida em 3 minutos
// linha com a idade, seguida das idades das pessoas na fila

// mais de 59 entra antes da mais nova mais proxima do comeco.

typedef struct fila {
  int idade;
  int tempo;
  struct fila *prox;
} Fila;

void insere_aux(Fila **head, Fila **tail, int idade, int tempo) {
  Fila *novo = malloc(sizeof(Fila)), *aux, *aux_anterior;
  novo->idade = idade;
  novo->tempo = tempo;

  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    (*head)->prox = NULL;
    return;
  }
  if (novo->tempo < (*head)->tempo || (novo->tempo == (*head)->tempo && novo->idade > 59 && novo->idade > (*head)->idade)) {
    novo->prox = *head;
    *head = novo;
    return;
  }

  if (novo->tempo > (*tail)->tempo) {
    novo->prox = NULL;
    (*tail)->prox = novo;
    *tail = novo;
    return;
  }

  aux = (*head)->prox;
  aux_anterior = *head;
  while (aux != NULL) {
    if (novo->tempo < aux->tempo || (novo->tempo == aux->tempo && novo->idade > 59 && novo->idade > aux->idade)) {
      aux_anterior->prox = novo;
      novo->prox = aux;
      return;
    }
    aux_anterior = aux;
    aux = aux->prox;
  }

  if (novo->tempo == (*head)->tempo && ((*head)->prox == NULL || (*head)->prox->tempo != novo->tempo)) {
    novo->prox = (*head)->prox;
    (*head)->prox = novo;
    return;
  }

  aux = (*head)->prox;
  while (aux != NULL) {
    if (novo->tempo == aux->tempo && (aux->prox == NULL || aux->prox->tempo != novo->tempo)) {
      novo->prox = aux->prox;
      aux->prox = novo;
      if (novo->prox == NULL) *tail = novo;
      return;
    }
    aux = aux->prox;
  }
}

void insere_fila(Fila **head, Fila **tail, int idade, int tempo) {
  Fila *novo = malloc(sizeof(Fila));
  novo->idade = idade;
  novo->tempo = tempo;
  Fila *aux, *aux_anterior;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    (novo)->prox = NULL;
    return;
  }
  if ((novo)->idade > 59) {
    if ((novo)->idade > (*head)->idade) {
      (novo)->prox = *head;
      *head = novo;
      return;
    }
    aux = (*head)->prox;
    aux_anterior = (*head);
    while (aux != NULL) {
      if ((novo)->idade > aux->idade) {
        aux_anterior->prox = novo;
        (novo)->prox = aux;
        return;
      }
      aux_anterior = aux;
      aux = aux->prox;
    }
  }
  (*tail)->prox = novo;
  (novo)->prox = NULL;
  *tail = novo;
}

void remover(Fila **head, Fila **tail) {
  if (*head == NULL) return;
  if ((*head)->prox == NULL) {
    free(*head);
    *head = NULL;
    *tail = NULL;
    return;
  }
  if ((*head)->prox == *tail) {
    free(*head);
    *head = *tail;
    return;
  }
  Fila *aux = *head;
  *head = (*head)->prox;
  free(aux);
}

void printa(Fila *head) {
  while (head != NULL) {
    printf("%d ", head->idade);
    head = head->prox;
  }
  printf("\n");
}

int main() {
  int i, n, idade, tempo, tempo_total, tempo_atual = 3, idade_atual;
  Fila *head_aux = NULL, *tail_aux = NULL, *head = NULL, *tail = NULL;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &idade, &tempo);
    insere_aux(&head_aux, &tail_aux, idade, tempo);
  }
  tempo_total = head_aux->tempo;
  idade_atual = head_aux->idade;
  insere_fila(&head, &tail, head_aux->idade, head_aux->tempo);
  remover(&head_aux, &tail_aux);
  int inseriu = 1;
  while (!(head_aux == NULL && head == NULL)) {
    if (tempo_atual >= 3) {
      tempo_atual = 0;
      if (head == NULL) {
        insere_fila(&head, &tail, head_aux->idade, head_aux->tempo);
        tempo_total = head_aux->tempo;
        remover(&head_aux, &tail_aux);
        inseriu = 1;
      }
      idade_atual = head->idade;
      remover(&head, &tail);
    }
    while (head_aux != NULL && tempo_total >= head_aux->tempo) {
      insere_fila(&head, &tail, head_aux->idade, head_aux->tempo);
      remover(&head_aux, &tail_aux);
      inseriu = 1;
    }
    if (inseriu) {
      printf("%d ", idade_atual);
      printa(head);
    }
    tempo_atual++;
    tempo_total++;
    inseriu = 0;
  }

  return 0;
}
