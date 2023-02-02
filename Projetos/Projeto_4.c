#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int identificador;
  int tempo_chegada;
  int tempo_atendimento;
  struct fila *prox;
} Fila;

//Protótipos:
void insere_fila(Fila **, int, int, int);
void remove_fila(Fila **);
void atende_fila(Fila *, int [], int );

int main() {
  int N;  // Num de elementos a serem colocados na lista
  int M;  // Num centros de servico
  int I;  // identificador
  int O;  // instante de chegada
  int C;  // tempo de atender
  int i;
  Fila *head = NULL;
  int *centros;
  scanf("%d", &N);
  scanf("%d", &M);
  centros = malloc(M * sizeof(int)); //vetor centros
  for (i = 0; i < M; i++) {
    centros[i] = 0;
  }
  for (i = 0; i < N; i++) {
    scanf("%d", &I);
    scanf("%d", &O);
    scanf("%d", &C);
    insere_fila(&head, O, C, I); //ordenar a fila
  }
  atende_fila(head, centros, M); //fazer atendimento
  return 0;
}

void insere_fila(Fila **head, int O, int C, int I) {  // Insercao de acordo com tempo de chegada - lista ordenada
  Fila *novo = malloc(sizeof(Fila));
  Fila *aux, *aux_ant;
  novo->identificador = I;
  novo->tempo_atendimento = C;
  novo->tempo_chegada = O;
  if (*head == NULL) {  // Se for o primeiro elemento
    *head = novo;
    novo->prox = NULL;
    return;
  }
  if (novo->tempo_chegada < (*head)->tempo_chegada || (novo->tempo_chegada == (*head)->tempo_chegada && novo->identificador < (*head)->identificador)) {  // Chegaram em tempos iguais - primeiro idenfificador
    novo->prox = *head;
    *head = novo;
    return;
  }
  aux_ant = *head;
  aux = (*head)->prox;
  while (aux != NULL) {
    if (novo->tempo_chegada < aux->tempo_chegada || (novo->tempo_chegada == aux->tempo_chegada && novo->identificador < aux->identificador)) { 
      novo->prox = aux;
      aux_ant->prox = novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
  if (novo->tempo_chegada >= aux_ant->tempo_chegada) {
    aux_ant->prox = novo;
    novo->prox = NULL;
  }
}

void remove_fila(Fila **head) { //remove como na fila - apenas a cabeca
  // if (*head == NULL) {
  //   return;
  // }
  Fila *aux = (*head)->prox;
  free(*head);
  *head = aux;
}

void atende_fila(Fila *head, int centros[], int M) { //Atende de acordo com a disponibilidade dos centros e o tempo atingido
  int i, aux_indice, aux_menor;
  while (head != NULL) { 
    aux_indice = 0; //salva o indice
    aux_menor = centros[0]; //acha o menor
    for (i = 1; i < M; i++) {
      if (centros[i] < aux_menor) {
        aux_indice = i;
        aux_menor = centros[i];
      }
    }
    if (centros[aux_indice] < head->tempo_chegada) { //Chegar no tempo de atendimento
      centros[aux_indice] = head->tempo_chegada;
    }
    centros[aux_indice] += head->tempo_atendimento; //soma na posicao do vetor
    remove_fila(&head); //Faz a remocao - atende o elemento
  }

  for (i = 0; i < M; i++) { //printa a resposta
    printf("%d ", centros[i]);
  }
}
