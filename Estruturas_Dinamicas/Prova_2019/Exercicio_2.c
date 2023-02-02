/* Considere que o jogo da Torre de Hanoi foi implementado usando 3
estruturas de pilha representando cada um de seus postes. Escreva a funcao
movimenta (disco, poste_orig, poste_dest), que recebe o numero do disco a ser
movimentado e o transfere do poste de origem para o poste de destino, desempilhando
o disco de uma pilha e o empilhando na outra. USE ESTRUTURAS DINAMICAS ! */
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int disco;
  struct pilha *embaixo;
};

void movimenta(int disco, struct pilha **orig, struct pilha **dest) {
  int d;
  struct pilha *aux;
  d = (*orig)->disco;
    if (d != disco){
      printf("Disco invalido\n");
      return;
    }
  //remover
  aux =  (*orig)->embaixo;
  free(*orig);
  *orig = aux;
  //colocar
  aux = malloc(sizeof(struct pilha));
  aux->disco = d;
  aux->embaixo = *dest;
  *dest = aux;
}
