#include <stdio.h>
#include <stdlib.h>
#define size 10000
typedef struct lista {
  int num;
  int prox;
} Lista;

Lista lista[size];

void insere(int *head, int *tail, int num) {
  if (*head == -1) {
    *head = *tail = 1;
    lista[*head].num = num;
    lista[*head].prox = 0;
    return;
  }
  int i = 1, aux_ant = *head, aux = lista[*head].prox;
  while (lista[i].prox != -1) {
    i++;
  }
  lista[i].num = num;
  if (num <= lista[*head].num) {
    lista[i].prox = *head;
    *head = i;
    return;
  }
  if (num >= lista[*tail].num) {
    lista[i].prox = 0;
    lista[*tail].prox = i;
    *tail = i;
    return;
  }
  while (aux != 0) {
    if (num < lista[aux].num) {
      lista[aux_ant].prox = i;
      lista[i].prox = aux;
    }
    aux_ant = aux;
    aux = lista[aux].prox;
  }
}

void tira(int *head, int *tail, int num) {
  int aux = *head, aux_ant;
  if (*head == -1) {
    printf("Nao ha elementos\n");
    return;
  }
  if (lista[*head].num == num) {
    if (lista[*head].prox == 0) {
      lista[*head].prox = -1;
      *head = -1;
      return;
    }
    *head = lista[*head].prox;
    lista[aux].prox = -1;
    return;
  }
  aux = lista[*head].prox;
  aux_ant = *head;
  while (aux != 0) {
    if (lista[aux].num == num) {
      lista[aux_ant].prox = lista[aux].prox;
      lista[aux].prox = -1;
      if (aux == *tail) {
        *tail = aux_ant;
      }
      return;
    }
    aux_ant = aux;
    aux = lista[aux].prox;
  }
  printf("Não tem \n");
}

void printa(int head) {
  int aux = head;
  if (lista[head].prox == -1) {
    printf("Lista vazia\n");
    return;
  }
  while (aux != 0) {
    printf("%d ", lista[aux].num);
    aux = lista[aux].prox;
  }
  printf("\n");
}

int main() {
  int op, num, head = -1, tail = -1;
  for (int i = 1; i < size; i++) {
    lista[i].prox = -1;
  }
  do {
    printf("1 inserir\n2 printar\n3 Tira");
    scanf("%d", &op);
    switch (op) {
      case 1: {
        printf("Numero a ser inserido: ");
        scanf("%d", &num);
        insere(&head, &tail, num);
        break;
      }
      case 2: {
        printa(head);
        break;
      }
      case 3: {
        printf("Numero a ser retirado: ");
        scanf("%d", &num);
        tira(&head, &tail, num);
        break;
      }
    }
  } while (op != 0);
  return 0;
}
