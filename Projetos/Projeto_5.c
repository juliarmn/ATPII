//Código que testa com quicksort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Para fazer contagem de tempo
#define size 200000//Estabelece o tamanho do vetor como indicado

typedef struct biggo {
  int high;
  int low;
} BigInt;

void quicksort(BigInt *, int, int);
void troca(BigInt *, BigInt *);
// int mediana(BigInt *);

int main() {
  clock_t t;//contagem de tempo
  BigInt vet[size];
  FILE *fp, *out;//Arquivos 
  int i = 0;
  fp = fopen("bigint.dat", "r");
  out = fopen("quick.dat", "w");
  if (fp == NULL) {
    // printf("Este arquivo não existe\n");
    return 0;  // Não existe o arquivo
  }
  for (i = 0; i < size; i++) {//Pega os dados do arquivo
    fscanf(fp, "%d %d", &vet[i].high, &vet[i].low);
    if (vet[i].high < 0) { //Caso o high seja negativo, devemos ordenar de outra forma
      vet[i].low = (-1) * vet[i].low;//Multiplica por - 1 para fazer ordenar corretamente
    }
  }
  t = clock(); //Começa a contar o tempo
  quicksort(vet, 0, size - 1);
  t = clock() - t; //Para a contagem de tempo
  double time = ((double)t)/CLOCKS_PER_SEC;//Clock per sec para pegar o tempo por segundos
  printf("%f", time);
  for (i = 0; i < size; i ++) {//Para copiar para o próximo arquivo
    if(vet[i].high < 0) {//Transformar de volta caso o high seja negativo o low no que era anteriormente
      vet[i].low = (-1) * vet[i].low;
    }
    fprintf(out, "%d %d\n", vet[i].high, vet[i].low);
  }
  return 0;
}

void troca(BigInt *valor1, BigInt *valor2) {
  BigInt aux;
  aux = *valor1;
  *valor1 = *valor2;
  *valor2 = aux;
}

//Função que verificaria a mediana de 3 - Não consegui fazer funcionar

// int mediana(BigInt *vet) {
//   int inicio = 0, meio = size / 2, fim = size - 1;
//   if (((vet[inicio].high < vet[meio].high || (vet[inicio].high == vet[meio].high && vet[inicio].low < vet[meio].low)) &&
//        (vet[inicio].high > vet[fim].high || (vet[inicio].high == vet[fim].high && vet[inicio].low > vet[fim].low))) ||
//       ((vet[inicio].high < vet[fim].high || (vet[inicio].high == vet[fim].high && vet[inicio].low < vet[fim].low)) &&
//        (vet[inicio].high > vet[meio].high || (vet[inicio].high == vet[meio].high && vet[inicio].low > vet[meio].low)))) {
//     return inicio;
//   }
//   if (((vet[fim].high < vet[meio].high || (vet[fim].high == vet[meio].high && vet[fim].low < vet[meio].low)) &&
//        (vet[fim].high > vet[inicio].high || (vet[fim].high == vet[inicio].high && vet[fim].low > vet[inicio].low))) ||
//       ((vet[fim].high < vet[inicio].high || (vet[fim].high == vet[inicio].high && vet[fim].low < vet[inicio].low)) &&
//        (vet[fim].high > vet[meio].high || (vet[fim].high == vet[meio].high && vet[fim].low > vet[meio].low)))) {
//     return fim;
//   }
//   return meio;
// }

void quicksort(BigInt *vet, int inicio, int fim) {
  int i, pivo, maior;
  if (inicio < fim) {//Enquanto ainda tiver mais de uma posição no vetor verificado
    pivo = fim;
    troca(&vet[pivo], &vet[fim]);//Coloca o pivo no fim para facilitar as comparações
    maior = inicio;
    for (i = maior; i < fim; i++) {
      if (vet[i].high < vet[fim].high || (vet[i].high == vet[fim].high && vet[i].low < vet[fim].low)) {//Verifica o high e se for igual verifica o low
        troca(&vet[i], &vet[maior]);//Chama a função troca, troca o maior com um elemento que seja menor que o pivo
        maior++;//Agora o meio elemeento para a comparação passa a ser o próximo do vetor
      }
    }
    troca(&vet[maior], &vet[fim]);//Quando sai do laço, coloca o pivo no seu devido lugar
    quicksort(vet, inicio, maior - 1);//Chamada recursiva para a parte de baixo do vetor - ordena ela primeiro
    quicksort(vet, maior + 1, fim);//Chamada recursiva para a parte de cima do vetor
  }
}
