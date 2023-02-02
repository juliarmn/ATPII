#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int num_posicoes;//Salva o num de posicoes que ira andar
  int op;//0 retira e 1 recoloca
  int identificador;//Num da posicao
  struct lista *prox, *antes;//Ponteiros - lista duplamente encadeada e circular
} Lista;

void monta_josephius(Lista **, Lista **, int, int, int);
void realiza_operacao(Lista **, Lista **, int, int, int);

int main() {
  int num_posicoes, total_pessoas, op;
  int i;
  Lista *head = NULL, *tail = NULL;//Inicializar os ponteiros
  scanf("%d", &total_pessoas);
  for (i = 1; i <= total_pessoas; i++) {//Salva os dados na lista
    scanf("%d", &num_posicoes);
    scanf("%d", &op);
    monta_josephius(&head, &tail, i, op, num_posicoes);
  }
  realiza_operacao(&head, &tail, total_pessoas, head->op, head->num_posicoes);//Realiza as remocoes ou reeinsercoes ate ultimo elemento
  return 0;
}

void monta_josephius(Lista **head, Lista **tail, int num, int op, int num_posicoes) {//ordena antes de realizar as operacoes
  Lista *novo;
  novo = malloc(sizeof(Lista));//Aloca novo espaco na lista
  //Salva em novo suas caracteristicas
  novo->op = op;
  novo->identificador = num;
  novo->num_posicoes = num_posicoes;
  if (*head == NULL) {//Caso seja o primeiro elemento, ou seja, a lista estava vazia
    *head = novo;
    *tail = novo;
    novo->antes = novo;
    novo->prox = novo;
    return;
  }
  //Caso contrario coloca normalmente, sempre atras do tail, pois o i ja chega em ordem
  novo->antes = *tail;
  novo->prox = (*tail)->prox;
  (*tail)->prox = novo;
  (*head)->antes = novo;
  *tail = novo;
}

void realiza_operacao(Lista **head, Lista **tail, int num, int op, int num_posicoes) {//Realiza as op de acordo com os valores na lista
  Lista *aux, *guarda_ultimo;//guarda_ultimo e para reviver o elemento
  int i;
  int op_novo, num_posicoes_novo = num_posicoes;//num_posicoes que vai andar
  guarda_ultimo = NULL;//inicializa como NULL para primeira vez
  while (num != 1) {
    aux = *head;//percorrer a lista
    for (i = 1; i < num_posicoes_novo; i++) {
      aux = aux->prox;//andar e achar aonde retirar o elemento
    }
    num_posicoes_novo = aux->num_posicoes;//Agora vai andar o que esta na lista
    if (aux->op == 1) {//Para reviver
      guarda_ultimo->prox = guarda_ultimo->antes->prox;//Coloca o elemento de volta na lista
      guarda_ultimo->antes->prox = guarda_ultimo;
      guarda_ultimo->antes = guarda_ultimo->prox->antes;
      guarda_ultimo->prox->antes = guarda_ultimo;
      //muda a op para que nao reviva sempre que caia nele
      guarda_ultimo->op = 0;
      num++;//reinsere na lista
      guarda_ultimo = NULL;//libera o guarda_ultimo, para salvar a proxima vez
    }
    //retira o ultimo elemento, pois o ultimo agora é outro, caso precise reviver
    free(guarda_ultimo);
    //retirar o elemento da lista
    aux->antes->prox = aux->prox;
    aux->prox->antes = aux->antes;
    //Muda o head e tail para iniciar a contagem da posicao correta
    *head = aux->prox;
    *tail = aux->antes;
    //Guarda o ultimo elemento
    guarda_ultimo = aux;
    num--;//Decrementa, ate ter so 1 na lista
  }
  printf("%d\n", aux->prox->identificador);
}
