#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Considere uma coleção de nomes de sites da web e seus respectivos links na Internet armazenados através
de uma lista simplesmente encadeada. Escreva a respectiva estrutura e uma função que, dado o nome
de um site, busque o seu link correspondente na lista e ao mesmo tempo mova o nó que contém o nome
buscado para o início da lista, de forma que ele possa ser encontrado mais rapidamente na próxima vez
que for buscado.
*/

typedef struct lista {
  char nome[100];
  char link[100];
  struct lista *prox;
}lista;

void insere(lista **h, lista **t, char *nome, char *link) {
  lista *novo = malloc(sizeof(lista));
  strcpy(novo->nome, nome);
  strcpy(novo->link, link);

 if(*h == NULL) {
   *h = novo;
   *t = novo;
   novo->prox = NULL;
   return;
 }

 (*t)->prox = novo;
 novo->prox = NULL;
 *t = novo;

}

void busca(lista **h, lista **t, char *nome) {
  if(*h == NULL) {
    printf("Vazia\n");
    return;
  }
  lista *aux = (*h)->prox, *aux_ant = *h;
  if (!(strcmp((*h)->nome, nome))) {
    printf("Link: %s \n", (*h)->link);
    return;
  }
  while(aux != NULL) {
    if (!(strcmp(aux->nome, nome)) && aux != *t) {
      printf("Link: %s \n", aux->link);
      aux_ant->prox = aux->prox;
      aux->prox = *h;
      *h = aux;
      return;
    }
    if(!(strcmp(aux->nome, nome)) && aux == *t) {
      printf("Link: %s \n", aux->link);
      aux->prox = *h;
      *t = aux_ant;
      aux_ant->prox = NULL;
      *h = aux;
      return;
    }
    aux_ant = aux_ant->prox;
    aux = aux->prox;
  }
  printf("Esse nome é inválido\n");
}

void printa(lista *h) {
  if(h == NULL) {
    printf("Lista vazia\n");
    return;
  }
  while (h != NULL) {
    printf("---------------\n");
    printf("Nome: %s\n", h->nome);
    printf("link: %s\n", h->link);
    printf("---------------\n");
    h = h->prox;
  }
}

int main () {
  int op;
  char nome[100], link[100];
  lista *h = NULL, *t = NULL;
  do {
    printf("MENU:\n1)insere\n2)busca\n3)printa\n0)Sair\n");
    scanf("%d", &op);
    switch(op) {
      case 1: {
        printf("Digite o nome:\n");
        scanf(" %[^\n]s", nome);
        printf("Digite o link:\n");
        scanf(" %[^\n]s", link);
        insere(&h, &t, nome, link);
        break;
      }
      case 2: {
        printf("Digite o que quer buscar:\n");
        scanf(" %[^\n]s", nome);
        busca(&h, &t, nome);
        break;
      }
      case 3: {
        printa(h);
        break;
      }
    }
  } while (op != 0);
  return 0;
}
