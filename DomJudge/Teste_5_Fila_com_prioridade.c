#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{ // Fila com prioridade
  int idade;
  int tempo_chegada;
  int prioridade;
  struct fila *prox;
} Fila;

void insere_tempo(Fila **head, int idade, int tempo_chegada)
{ // Nao estava usando o tail, retirei
  // Copiei a insere do caderno, lista simples
  Fila *novo = malloc(sizeof(Fila)), *aux, *aux_ant;
  novo->idade = idade;
  novo->tempo_chegada = tempo_chegada;
  if (idade - 59 <= 0)
  {
    novo->prioridade = 0;
  }
  else
  {
    novo->prioridade = idade - 59;
  }
  if (*head == NULL)
  {
    *head = novo;
    return;
  }
  aux = *head;
  aux_ant = *head;
  while (aux->prox && novo->tempo_chegada >= aux->tempo_chegada)
  {
    aux_ant = aux;
    aux = aux->prox;
  }
  if (aux == *head)
  {
    if (novo->tempo_chegada > aux->tempo_chegada)
    {
      novo->prox = aux->prox;
      (*head)->prox = novo;
      return;
    }
    else if (novo->tempo_chegada < aux->tempo_chegada)
    {
      novo->prox = *head;
      *head = novo;
      return;
    }
    else
    {
      if (novo->prioridade > aux->prioridade)
      {
        novo->prox = *head;
        *head = novo;
        return;
      }
      else
      {
        novo->prox = aux->prox;
        (*head)->prox = novo;
        return;
      }
    }
  }
  if (novo->tempo_chegada > aux->tempo_chegada)
  {
    novo->prox = aux->prox;
    aux->prox = novo;
    return;
  }
  else if (novo->tempo_chegada < aux->tempo_chegada)
  {
    novo->prox = aux;
    aux_ant->prox = novo;
    return;
  }
  else
  {
    if (novo->prioridade > aux->prioridade)
    {
      novo->prox = aux;
      aux_ant->prox = novo;
      return;
    }
    else
    {
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  }
}

void insere_idade(Fila **head, int idade, int tempo_chegada, int prioridade)
{
  Fila *novo = malloc(sizeof(Fila)), *aux;
  novo->idade = idade;
  novo->tempo_chegada = tempo_chegada;
  novo->prioridade = prioridade;

  if (*head == NULL || ((*head)->prioridade <= novo->prioridade && novo->prioridade != 0) )
  {
    novo->prox = *head;
    *head = novo;
  }
  else
  {
    aux = *head;
    while (aux->prox != NULL && (aux->prox)->prioridade >= novo->prioridade)
    {
      aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
  }
}

// Retirar da lista:
void remover(Fila **head)
{
  Fila *aux;
  if (*head == NULL)
  {
    return;
  }
  aux = (*head)->prox;
  free(*head);
  *head = aux;
  return;
}
// printar:
void printa(Fila *head)
{
  while (head != NULL)
  {
    printf("%d ", head->idade);
    head = head->prox;
  }
}

int main()
{
  Fila *head = NULL, *head_fila_principal = NULL;
  int idade, tempo_chegada, num_pessoas, count, removeu = 1;
  int i, tempo_decorrido, tempo_atual;
  scanf("%d", &num_pessoas);
  for (i = 0; i < num_pessoas; i++)
  {
    scanf("%d", &idade);
    scanf("%d", &tempo_chegada);
    insere_tempo(&head, idade, tempo_chegada);
  }
  tempo_decorrido = head->tempo_chegada;
  tempo_atual = head->tempo_chegada;
  while (head != NULL)
  {
    if (tempo_atual >= 3)
    {
      tempo_atual = 0;
      remover(&head_fila_principal);
      if (head_fila_principal != NULL)
      {
        head_fila_principal->prioridade = 999;
      }
    }
    if (tempo_decorrido == head->tempo_chegada)
    {
      while (head != NULL && tempo_decorrido == head->tempo_chegada)
      {
        insere_idade(&head_fila_principal, head->idade, head->tempo_chegada, head->prioridade);
        remover(&head);
      }
      head_fila_principal->prioridade = 999;
      printa(head_fila_principal);
      printf("\n");
    }
    tempo_decorrido++;
    tempo_atual++;
  }
  // Pode sorrir Julia, depois de 2 dias voce conseguiu
  return 0;
}
