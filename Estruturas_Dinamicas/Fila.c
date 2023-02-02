#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct listinha {
  int num;
  struct listinha *prox;
} Fila;

int menu() {
  setlocale(LC_ALL, "Portuguese");
  int op;
  printf("\n===> Opções: <===\n");
  printf("1) Push;\n");
  printf("2) Pop;\n");
  printf("3) Mostrar;\n");
  printf("4) Buscar;\n");
  printf("0) sair\n");
  scanf("%d", &op);
  return (op);
}

Fila *Push(Fila **head, Fila **tail, int num) {
  Fila *novo = malloc(sizeof(Fila));
  novo->num = num;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return (novo);
  }
  novo->prox = NULL;
  (*tail)->prox = novo;
  *tail = novo;
  return (novo);
}

void listar(Fila **head) {
  Fila *aux = *head;
  if (*head == NULL) {
    printf("\nNão existe\n");
  }
  while (aux != NULL) {
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}

Fila *busca(Fila **head, int num) {
  Fila *aux = *head;
  while (aux != NULL) {
    if (aux->num == num) {
      return (aux);
    }
    aux = aux->prox;
  }
  return (NULL);
}

Fila *pop(Fila **head, Fila **tail) {
  Fila *aux;
  if (*head == NULL) {
    return (NULL);
  }
  if ((*head)->prox == NULL) {
    free(*head);
    *head = NULL;
    return NULL;
  }
  aux = (*head)->prox;
  free(*head);
  *head = aux;
  return(*head);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  Fila *head = NULL;
  Fila *tail = NULL;
  int op = -1;
  while (op != 0) {
    op = menu();
    switch (op) {
      case 1: {
        int num;
        printf("\nDigite o número que desejas inserir\n");
        scanf("%d", &num);
        Push(&head, &tail, num);
        break;
      }
      case 2: {
        if (!pop(&head, &tail)) {
          printf("\nNão tem o que retirar\n");
        }
        break;
      }
      case 3: {
        listar(&head);
        break;
      }
      case 4: {
        int num;
        printf("\nDigite o que queres encontrar\n");
        scanf("%d", &num);
        if (busca(&head, num)) {
          printf("\nEncontrou!\n");
        } else {
          printf("\nNão existe\n");
        }
        break;
      }
    }
  }
}
