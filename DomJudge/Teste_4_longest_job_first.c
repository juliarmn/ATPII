// ordenar inverso com base no tempo
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int tempo_exec, tempo_cheg;
  struct lista *prox;
} Lista;

// insere ordenando crescente na lista principal
void insere_principal(Lista **head, Lista **tail, Lista **novo) {
  Lista *aux, *aux_ant;
  if ((*novo)->tempo_cheg <= (*head)->tempo_cheg) {
    (*novo)->prox = *head;
    *head = *novo;
    return;
  }
  if ((*novo)->tempo_cheg >= (*tail)->tempo_cheg) {
    (*novo)->prox = NULL;
    (*tail)->prox = *novo;
    *tail = *novo;
    return;
  }
  aux_ant = *head;
  aux = (*head)->prox;
  while (aux != NULL) {
    if ((*novo)->tempo_cheg <= aux->tempo_cheg) {
      (*novo)->prox = aux;
      aux_ant->prox = *novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
}

// insere ordenando decrescente na lista de espera
void insere_espera(Lista **head, Lista **tail, Lista **novo) {
  Lista *aux, *aux_ant;
  if ((*novo)->tempo_exec == (*head)->tempo_exec) {  // se for igual ao head, insere após ele
    (*novo)->prox = (*head)->prox;
    (*head)->prox = *novo;
    if ((*novo)->prox == NULL) {
      *tail = *novo;
    }
    return;
  }
  if ((*novo)->tempo_exec >= (*head)->tempo_exec) {  // se for maior que o head, insere antes dele
    (*novo)->prox = *head;
    *head = *novo;
    return;
  }
  if ((*novo)->tempo_exec <= (*tail)->tempo_exec) {  // se for menor que o tail, insere após ele
    (*novo)->prox = NULL;
    (*tail)->prox = *novo;
    *tail = *novo;
    return;
  }
  aux_ant = *head;
  aux = (*head)->prox;
  while (aux != NULL) {
    if ((*novo)->tempo_exec == aux->tempo_exec) {  // se for igual insere após
      (*novo)->prox = aux->prox;
      aux->prox = *novo;
      return;
    }
    if ((*novo)->tempo_exec > aux->tempo_exec) {  // se for maior insere antes
      (*novo)->prox = aux;
      aux_ant->prox = *novo;
      return;
    }
    aux_ant = aux;
    aux = aux->prox;
  }
}

// insere nas listas
void insere(Lista **head, Lista **tail, int tempo_exec, int tempo_cheg, int tipo_ordenacao) {
  Lista *novo, *aux, *aux_ant;
  novo = malloc(sizeof(Lista));
  novo->tempo_cheg = tempo_cheg;
  novo->tempo_exec = tempo_exec;
  if (*head == NULL) {
    *head = novo;
    *tail = novo;
    novo->prox = NULL;
    return;
  }
  if (!tipo_ordenacao)
    insere_principal(head, tail, &novo);
  else
    insere_espera(head, tail, &novo);
}

// remove head da lista
void remover(Lista **head, Lista **tail) {
  if ((*head)->prox == NULL) {
    free(*head);
    *head = NULL;
    *tail = NULL;
    return;
  }
  Lista *aux = (*head)->prox;
  free(*head);
  *head = aux;
}

// printa o programa quando começa a executar, se vier outro enquanto executa taca na lista de espera (que ja ordena de acordo com a prioridade)

int main() {
  Lista *head_principal = NULL, *tail_principal = NULL, *head_espera = NULL, *tail_espera = NULL;
  int N;
  int T, C;
  int i, tempo_processador, tempo_exec_atual = 0, tempo_processamento_atual = 0;
  scanf("%d", &N);
  if(N == 0)
    return 0;
  for (i = 0; i < N; i++) {
    scanf("%d %d", &T, &C);
    insere(&head_principal, &tail_principal, C, T, 0);
  }

  // insere primeiro elemento na lista de espera
  insere(&head_espera, &tail_espera, head_principal->tempo_exec, head_principal->tempo_cheg, 1);
  remover(&head_principal, &tail_principal);
  tempo_processador = head_espera->tempo_cheg;
  while (!(head_principal == NULL && head_espera == NULL)) {
    while (head_principal != NULL && tempo_processador >= head_principal->tempo_cheg) {               // se tempo_processador for igual ou ultrapassar o tempo de chegada de alguma tarefa (se existir tarefa chegando)
      insere(&head_espera, &tail_espera, head_principal->tempo_exec, head_principal->tempo_cheg, 1);  // insere na lista de espera
      remover(&head_principal, &tail_principal);                                                      // remove da lista principal pois já está na lista de espera
    }
    if (head_espera != NULL && tempo_processamento_atual >= tempo_exec_atual) {  // se tempo_processamento_atual for igual ou ultrapassar tempo de execução da tarefa atual e existir tarefa na lista de espera
      tempo_exec_atual = head_espera->tempo_exec;                                // começa a executar a tarefa que estava no topo da lista
      remover(&head_espera, &tail_espera);                                       // remove da lista pois já está executando
      printf("%d ", tempo_exec_atual);                                           // printa
      tempo_processamento_atual = 0;                                             // zera tempo_processamento_atual
    }
    tempo_processador++;
    tempo_processamento_atual++;
  }

  return 0;
}
