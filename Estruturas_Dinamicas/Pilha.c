#include <stdio.h>
#include <stdlib.h>

int empilha(int topo, int vet[], int elem) {
  vet[topo] = elem;
  return (topo + 1);
}

int desempilha(int *topo, int vet[]) {
  int aux;
  aux = (*topo) - 1;
  return aux;
}

int main() {
  int topo = 0;
  int vet[10000], elem;
  int op, i;
  do {
    printf("1)Empilhar\n2)Tirar\n3)Mostrar\n");
    scanf("%d", &op);
    switch (op) {
      case 1: {
        printf("Digite o num:\n");
        scanf("%d", &elem);
        topo = empilha(topo, vet, elem);
        break;
      }
      case 2: {
        if (topo == 0) {
          break;
        }
        topo =  desempilha(&topo, vet);
        break;
      }
      case 3: {
        i = 0;
        printf("/---/\n");
        for (i = topo -1; i >= 0; i --) {
            printf("%d\n", vet[i]);
        }
        printf("/---/\n");
        break;
      }
    }
  } while (op != 0);
}
