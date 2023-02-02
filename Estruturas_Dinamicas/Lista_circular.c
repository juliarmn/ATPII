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
  printf("2) Tira;\n");
  printf("3) Lista;\n");
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
    novo->prox = *tail;
    return (novo);
  }
  if (num < (*head)->num) {
    novo->prox = *head;
    *head = novo;
    (*tail)->prox = *head;
    return (novo);
  }
  if (num > (*tail)->num) {
    (*tail)->prox = novo;
    novo->prox = *head;
    *tail = novo;
  }
  aux_anterior = *head;
  aux = (*head)->prox;
  do {
    if (num < aux->num) {
      aux_anterior->prox = novo;
      novo->prox = aux;
      return (novo);
    }
    aux_anterior = aux;
    aux = aux->prox;
  } while (aux != *head);
  return (NULL);
}

void lista_a_lista(Tlista **head) {
  Tlista *aux = *head;
  if (*head == NULL) {
    printf("\nNÃO TEM\n");
    return;
  }
  do {
    printf("%d\n", aux->num);
    aux = aux->prox;
  } while (aux != *head);
}

Tlista *busca(Tlista **head, int num) {
  Tlista *aux = *head;
  do {
    if (aux->num == num) {
      return (aux);
    }
    aux = aux->prox;
  } while (aux != *head);
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
    if ((*head)->prox == *head) {
      free(*head);
      *head = NULL;
      return NULL;
    }
    aux = (*head)->prox;
    free(*head);
    *head = aux;
    (*tail)->prox = *head;
    return (aux);
  }
  aux = *head;
  do {
    if (aux->num == num) {
      aux_anterior->prox = aux->prox;
      if (aux == *tail) {
        *tail = aux_anterior;
        (*tail)->prox = *head;
      }
      free(aux);
      return (aux_anterior);
    }
    aux = aux->prox;
  } while (aux != *head);
  return (NULL);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
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
          printf("\nNão tem\n");
        }
        break;
      }
      case 3: {
        lista_a_lista(&head);
        break;
      }
      case 4: {
        int num;
        printf("\nQual quer buscar? ");
        scanf("%d", &num);
        if (busca(&head, num)) {
          printf("\nElemento encontrado.\n");
        } else {
          printf("\nNão existe\n");
        }
        break;
      }
    }
  }
  return 0;
}
