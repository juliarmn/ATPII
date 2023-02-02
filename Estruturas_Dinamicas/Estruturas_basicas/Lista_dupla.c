#include <stdio.h>
#include <stdlib.h>

typedef struct listinha {
  int num;
  struct listinha *prox;
  struct listinha *ant;
} Tlista;

int menu() {
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
  Tlista *aux;
  novo->num = num;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    novo->ant = NULL;
    return (novo);
  }
  if (num < (*head)->num) {
    novo->prox = *head;
    novo->ant = NULL;
    (*head)->ant = novo;
    *head = novo;
    return (novo);
  }
  if (num > (*tail)->num) {
    (*tail)->prox = novo;
    novo->ant = *tail;
    novo->prox = NULL;
    *tail = novo;
  }
  aux = *head;
  while (aux != NULL) {
    if (num < aux->num) {
      novo->ant = aux->ant;
      novo->prox = aux;
      aux->ant->prox = novo;
      aux->ant = novo;
      return (novo);
    }
    aux = aux->prox;
  }
  return (NULL);
}

void listar(Tlista **head) {
  Tlista *aux = *head;
  if (*head == NULL) {
    printf("\nNÃO TEM\n");
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
  Tlista *aux = busca(head, num);
  if (aux == NULL) {
    return (NULL);
  }
  if (aux == *head) {
    if((*head)->prox == NULL){
        free(*head);
        *head = NULL;
        return (*head);
    }
    aux->prox->ant = NULL;
    *head = aux->prox;
    free(aux);
    return (*head);
  }
  if (aux ==  *tail) {
    aux->ant->prox = NULL;
    *tail = aux;
    free(aux);
    return (*head);
  }
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  free(aux);
  return (*head);
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
        printf("\nDigite o número a ser inserido: ");
        scanf("%d", &num);
        insere(&head, &tail, num);
        break;
      }
      case 2: {
        int num;
        printf("\nNúmero a retirar: ");
        scanf("%d", &num);
        if (!tira(&head, &tail, num)) {
          printf("\nNão tem elemento a retirar\n");
        }
        break;
      }
      case 3: {
        listar(&head);
        break;
      }
      case 4: {
        int num;
        printf("\nDigite elemento a ser buscado: ");
        scanf("%d", &num);
        if (busca(&head, num)) {
          printf("\nEncontrado\n");
        } else {
          printf("\nNão encontrado\n");
        }
        break;
      }
    }
  }
  return 0;
}
