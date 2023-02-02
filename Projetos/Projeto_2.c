#include <stdio.h>
#include <stdlib.h>  //Para alocar dinamicamente

int *resultado;   // Salva a maior possibilidade ou a que tem o maior numero (resposta final)
int *candidatos;  // Candidatos para montar as possibilidades
int NumCombinacoes, tamMaiorVet, maiorNum;

void selectionSort(int *candidatos, int tam) {  // Ordena o vetor para facilitar a eliminacao de elementos duplicados nas possibilidades
  // Metodo selection sort:
  int i, j, menor, aux;
  for (i = 0; i < (tam - 1); i++) {
    menor = i;                       // Menor indica o indice, por isso vai até um antes de tamanho -1
    for (j = i + 1; j < tam; j++) {  // j indica os proximos indices em candidatos para fazer a comparação
      if (candidatos[j] < candidatos[menor]) {
        menor = j;  // Muda o indice que guarda o menor
      }
    }
    if (menor != i) {  // Se mudou a posição da original, troca os valores
      aux = candidatos[i];
      candidatos[i] = candidatos[menor];
      candidatos[menor] = aux;
    }
  }
}

void copiaVet(int *combina) {  // Copia os valores do candidato no combina(possibilidades)
  int i = 0;
  while (combina[i] != -1) {
    resultado[i] = combina[i];
    i++;
  }
  resultado[i] = -1;
}

void appendVetor(int num, int *combina) {  // Salva um valor de candidato no  vetor que mostra as possibilidades de soma
  int i = 0;
  while (combina[i] != -1) {
    i++;
  }
  combina[i] = num;
  combina[i + 1] = -1;
}

void pop(int *combina) {  // Retirar o valor para nao repetir
  int i = 0;
  while (combina[i] != -1) {
    i++;
  }
  combina[i - 1] = -1;
}

void printaVetor(int *vet) {
  int i = 0;
  while (vet[i] != -1) {
    printf("%d ", vet[i]);
    i++;
  }
  printf("\n");
}

int checaMaior(int *combina, int tamVetAtual) {
  if (combina[tamVetAtual] > resultado[tamVetAtual]) {
    return 1;
  }
  if (combina[tamVetAtual] < resultado[tamVetAtual]) {
    return 0;
  }
  return (checaMaior(combina, tamVetAtual - 1));
}

void backtrack(int alvo, int index, int *combina, int tamVetAtual, int maiorNumAtual) {  // Recebe o numero que quer decompor, o indice e o vetor de combinacao
  int i = index, prev;                                                                   // i salva o indice, prev e o elemento anterior para eliminar os duplicados
  if (alvo == 0) {                                                                       // Encontramos um conjunto cuja soma gera o alvo
    NumCombinacoes++;                                                                    // Conta quantas combinações foram feitas
    if (tamVetAtual > tamMaiorVet || (tamMaiorVet == tamVetAtual && maiorNumAtual > maiorNum) || (tamMaiorVet == tamVetAtual && maiorNumAtual == maiorNum && checaMaior(combina, tamVetAtual - 1))) {
      copiaVet(combina);  // Salva esse conjunto no resultado
      tamMaiorVet = tamVetAtual;
      maiorNum = maiorNumAtual;
    }
    maiorNumAtual = 0;
    tamVetAtual = 0;
  }
  if (alvo <= 0) {  // O conjunto numerico nao deu o alvo, ou seja, diminuiu mais do que devia
    return;         // Sai da funcao - quebra a recursao
  }
  prev = -2;                      // Valor inicial diferente de -1(que indica final do vetor) apenas para a primeira comparacao
  while (candidatos[i] != -1) {   // Ou seja, sao os valores indicados para combinacoes (M valores)
    if (candidatos[i] == prev) {  // Quando for = prev, ele nao pega esse valor, evita repeticoes
      continue;                   // Pula para o proximo loop sem executar o que esta embaixo
    }
    if (candidatos[i] > maiorNumAtual) {  // Salva o maior numero do conjunto
      maiorNumAtual = candidatos[i];
    }
    appendVetor(candidatos[i], combina);                                              // Salva os candidatos no vetor combinacao
    backtrack(alvo - candidatos[i], i + 1, combina, tamVetAtual + 1, maiorNumAtual);  // Subtrai esse valor de alvo, soma um indice para verificar o proximo
    pop(combina);                                                                     // retira o ultimo para proximas combinacoes
    prev = candidatos[i];                                                             // Agora esse passa a ser o elemento anterior
    i++;                                                                              // Incrementa o indice para comparacao
  }
}

int main(void) {
  int N;         // Quantidade de numeros a serem decompostos
  int M;         // Quantidade de numeros usados na decomposicao
  int i;         // Contador para o laco for
  int *alvo;     // Guarda os N numeros
  int *combina;  // Guarda as possibilidades de combinacao
  scanf("%d %d", &N, &M);
  // Aloca dinamicamente:
  alvo = malloc(N * sizeof(int));
  resultado = malloc((M + 1) * sizeof(int));
  candidatos = malloc((M + 1) * sizeof(int));
  combina = malloc((M + 1) * sizeof(int));
  for (i = 0; i < M; i++) {
    scanf("%d", &candidatos[i]);
  }
  selectionSort(candidatos, M);  // Ordena o vetor candidatos
  candidatos[i] = -1;            // Salva como -1 para poder usar isso posteriormente como forma de frear a checagem
  for (i = 0; i < N; i++) {
    scanf("%d", &alvo[i]);
  }
  if (N == 0) {
    printf("0\n");
    return 0;
  }
  for (i = 0; i < N; i++) {
    combina[0] = -1;
    resultado[0] = -1;
    NumCombinacoes = 0;
    tamMaiorVet = 0;
    maiorNum = 0;
    backtrack(alvo[i], 0, combina, 0, 0);  // Chama a função que monta as possibilidades
    printf("%d ", NumCombinacoes);
    printaVetor(resultado);
  }
  return 0;
}
