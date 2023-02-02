#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Considerando uma lista circular em que as operacoes de insercao sempre
ocorrem na posicao apontada pelo marcador de final, e as de remocao sempre ocorrem
na posicao apontada pelo marcador de inicio, implemente as funcoes para: i) insercao,
ii) remocao, e iii) verificacao de lista vazia. A lista deve ser implementada usando
estruturas dinamicas e cada posicao dela contem apenas um string*/

typedef struct circ {
  char str[90];
  struct circ *prox;
} circular;

int vazia(circular **head, circular **tail) {
  if (*head == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int menu() {
  int op;
  printf("\n===> EXCOLIA: <===\n");
  printf("1) Insere;\n");
  printf("2) Tira;\n");
  printf("3) Lista;\n");
  scanf("%d", &op);
  return (op);
}

void insercao(circular **head, circular **tail, char *str) {
  circular *novo = malloc(sizeof(circular));
  strcpy(novo->str, str);
  if (vazia(head, tail)) {
    *head = *tail = novo;
    (*head)->prox = *head;
    return;
  }
  if (*head == *tail) {
    novo->prox = *head;
    (*head)->prox = novo;
    *tail = novo;
    return;
  }
  novo->prox = (*tail)->prox;
  (*tail)->prox = novo;
  *tail = novo;
}

void remover(circular **head, circular **tail) {
  circular *aux;
  if (vazia(head, tail)) {
    printf("Não tem o que remover\n");
    return;
  }
  if (*head == *tail) {
    free(*head);
    *head = *tail = NULL;
  }
  aux = (*head)->prox;
  (*tail)->prox = aux;
  free(*head);
  *head = aux;
}


void lista_a_lista(circular **head) {
  circular *aux = *head;
  if (*head == NULL) {
    printf("\nNÃO TEM, FDP\n");
    return;
  }
  do {
    printf("%s\n", aux->str);
    aux = aux->prox;
  } while (aux != *head);
}

int main() {
  circular *head = NULL;
  circular *tail = NULL;
  int op = -1;
  char str[100];
  while (op != 0) {
    op = menu();
    switch (op) {
      case 1: {
        
        printf("\nDigite:\n");
        scanf(" %[^\n]s", str);
        insercao(&head, &tail, str);
        break;
      }
      case 2: {
        remover(&head, &tail);
      }
      case 3: {
        lista_a_lista(&head);
        break;
      }
    }
  }
  return 0;
}
