#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct listinha {
  int num;
  struct listinha *prox;
} Tlista;

int menu() {
  setlocale(LC_ALL, "Portuguese");
  int op;
  printf("\n===> OPÇÕES: <===\n");
  printf("1) Insere;\n");
  printf("2) Retira;\n");
  printf("3) Listar;\n");
  printf("4) Busca;\n");
  scanf("%d", &op);
  return (op);
}

Tlista *insere(Tlista **head, Tlista **tail, int num) {
  Tlista *novo = malloc(sizeof(Tlista));
  Tlista *aux, *aux_anterior;
  novo->num = num;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return (novo);
  }
  if (num < (*head)->num) {
    novo->prox = *head;
    *head = novo;
    return (novo);
  }
  if (num > (*tail)->num) {
    (*tail)->prox = novo;
    novo->prox = NULL;
    *tail = novo;
    return novo;
  }
  aux_anterior = *head;
  aux = (*head)->prox;
  while (aux != NULL) {
    if (num < aux->num) {
      novo->prox = aux;
      aux_anterior = novo;
      return (novo);
    }
    aux_anterior = aux;
    aux = aux->prox;
  }
  return (NULL);
}

void lista_a_lista(Tlista **head) {
  Tlista *aux = *head;
  if (*head == NULL) {
    printf("\nNÃO TEM ELEMENTO\n");
    return;
  }
  while (aux != NULL) {
    printf("%d\n", aux->num);
    aux = aux->prox;
  }
}

Tlista *busca(Tlista **head, int num) {
  Tlista *aux = *head;
  while (aux != NULL) {
    if (aux->num == num) {
      return (aux);
    }
    aux = aux->prox;
  }
  return (NULL);
}

Tlista *tira(Tlista **head, Tlista **tail, int num) {
  Tlista *aux, *aux_anterior;
  aux;
  aux_anterior = *head;
  if (*head == NULL) {
    return (NULL);
  }
  if (num == (*head)->num) {
    aux = (*head)->prox;
    free(*head);
    *head = aux;
    return (aux);
  }
  aux = *head;
  while (aux != NULL) {
    if (aux->num == num) {
      aux_anterior->prox = aux->prox;
      if (aux == *tail) {
        *tail = aux_anterior;
      }
      free(aux);
      return (aux_anterior);
    }
    aux = aux->prox;
  }
  return (NULL);
}

int main() {
  Tlista *head = NULL;
  Tlista *tail = NULL;
  int op = -1;
  while (op != 0) {
    op = menu();
    switch (op) {
      case 1: {
        int num;
        printf("\nNúmero a inserir: ");
        scanf("%d", &num);
        insere(&head, &tail, num);
        break;
      }
      case 2: {
        int num;
        printf("\nNúmero a retirar: ");
        scanf("%d", &num);
        if (!tira(&head, &tail, num)) {
          printf("\nSem elementos a retirar\n");
        }
        break;
      }
      case 3: {
        lista_a_lista(&head);
        break;
      }
      case 4: {
        int num;
        printf("\nNúmero a buscar: \n");
        scanf("%d", &num);
        if (busca(&head, num)) {
          printf("\nENCONTRADO!\n");
        } else {
          printf("\nNão existe esse elemento\n");
        }
        break;
      }
    }
  }
  return 0;
}
