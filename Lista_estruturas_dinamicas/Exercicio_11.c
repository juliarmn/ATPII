#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int num;
  struct lista *prox;
} Lista;

void insere_normal(Lista **head, Lista **tail, int num) {
  Lista *novo = malloc(sizeof(Lista));
  novo->num = num;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  (*tail)->prox = novo;
  novo->prox = NULL;
  *tail = novo;
}

int busca(Lista *head, int num) {
  if (head == NULL) {
    printf("Lista vazia\n");
    return 0;
  }
  if (head->prox == NULL) {
    if(head->num == num) {
      return 1;
    }
    return 0;
  }
  Lista *aux = head;
  while (aux != NULL) {
    if (aux->num == num) {
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}


Lista *sem_repeticao(Lista *head, Lista *tail, int num) {
  if (head == NULL) {
    printf("Vazia\n");
    return NULL;
  }
  Lista *head_aux = NULL;
  Lista *aux;
  Lista *novo = malloc(sizeof(Lista));
  novo->num = head->num;
  novo->prox = NULL;
  head_aux = novo;
  head = head->prox;
  aux = head_aux;
  while (head != NULL) {
    if (busca(head_aux, head->num)) {
      head = head->prox;
      continue;
    }
    novo = malloc(sizeof(Lista));
    novo->num = head->num;
    novo->prox = NULL;
    aux->prox = novo;
    aux = novo;
    head = head->prox;
  }
  return(head_aux);
}

void printa(Lista *head) {
  if (head == NULL) {
    printf("Lista vazia\n");
    return;
  }
  while (head != NULL) {
    printf("[%d] -> ", head->num);
    head = head->prox;
  }
  printf("\n");
}

int main() {
  int op, num;
  Lista *head = NULL, *tail = NULL, *aux;
  do {
    printf("1)Insere lista\n2)Lista sem repeticoes \n3)Mostra listas\n0)Sai\n");
    scanf("%d", &op);
    switch (op) {
      case 1: {
        printf("Digite o num\n");
        scanf("%d", &num);
        insere_normal(&head, &tail, num);
        break;
      }
      case 2: {
        aux = sem_repeticao(head, tail, head->num);
        break;
      }
      case 3: {
        printa(head);
        printa(aux);
      }
    }
  } while (op != 0);
  return 0;
}
