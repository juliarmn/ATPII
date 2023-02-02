#include <stdio.h>
#include <stdlib.h>
/*Considerando que as funcoes pop(a) e push(a) respectivamente retiram o
elemento a do topo de uma pilha e colocam o elemento a no topo dela, escreva um
programa que leia um inteiro positivo e imprima seu valor em binario usando esta pilha.
Declare a estrutura da pilha e como ela sera implementada, incluindo os prototipos
das funcoes pop e push.*/

typedef struct pilha {
  int bit;
  struct pilha *embaixo;
} Pilha;

Pilha *pop(Pilha **);
void push(int, Pilha **);
void printa(Pilha *);
void bin(int, Pilha *);

int main() {
  int num;
  Pilha *topo = NULL;
  printf("Digite um num decimal:\n");
  scanf("%d", &num);
  printf("Num decimal: %d\n", num);
 bin(num, topo);
  return 0;
}

void bin(int num, Pilha *topo) {
  int quociente = num, resto;
  if (quociente == 0) {
    push(0, &topo);
  } else {
    while (quociente != 0) {
      resto = quociente % 2;  // Vai empilhando
      quociente = quociente / 2;
      push(resto, &topo);
    }
  }
  printf("Binario:\n");
  printa(topo);
}

void push(int num, Pilha **topo) {
  Pilha *novo = malloc(sizeof(Pilha));
  novo->bit = num;
  if ((*topo) == NULL) {
    *topo = novo;
    (*topo)->embaixo = NULL;
    return;
  }
  novo->embaixo = *topo;
  *topo = novo;
  return;
}

Pilha *pop(Pilha **topo) {
  Pilha *aux = *topo;
  if (!*topo) {
    printf("\nNão tem o que tirar\n");
    return (NULL);
  }
  *topo = aux->embaixo;
  return (aux);
}

void printa(Pilha *topo) {
  Pilha *aux; 
  do {
    aux = pop(&topo);
    printf("%d", aux->bit);
  } while (topo != NULL);
}
