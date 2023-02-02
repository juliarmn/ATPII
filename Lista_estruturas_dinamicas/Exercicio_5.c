#include <stdio.h>
#include <stdlib.h>

int main() {
  int vet[10], tam_vet = 10, vet_retirados[10], num, i, j = 0, pos, tras, count;
  for (i = 0; i < 10; i++) {
    vet[i] = i;
  }
  i = 0;
  pos = i;
  do {
    printf("Digite um num\n");
    scanf("%d", &num);
    if (num > 0) {
      for (i = pos; i < (num + pos); i++) {
        count++;
        if (count == 10) {
          count = 0;
        }
        if (vet[count] == -1) {
          do {
            count++;
            if (count == 10) {
              count = 0;
            }
          } while (vet[count] == -1);
        }
        printf("count = %d\n", count);
      }
      vet_retirados[j] = vet[count];
      printf("Foi retirado: %d\n", vet_retirados[j]);
      j++;
      vet[count] = -1;
      tam_vet--;
      pos = i + 1;
    }
    if (num == 0) {
      printf("0 é invalido\n");
      continue;
    }
    if (num < 0) {
      tras = 0;
      printf("aa %d\n", i);
      while (tras < -num) {
        i--;
        if (i < 0) {
          i = 9;
        }
        printf("aa %d\n", i);
        if (!(vet[i] == -1)) {
          tras++;
        }
      }
      vet_retirados[j] = vet[i];
      printf("Foi retirado: %d\n", vet_retirados[j]);
      j++;
      count = i;
      vet[i] = -1;
      tam_vet--;
      pos = i + 1;
    }

  } while (tam_vet > 1);
  for (i = 0; i < 10; i++) {
    if (vet[i] != -1) {
      printf("O último foi: %d\n", vet[i]);
    }
  }
  printf("Ordem de retirada:\n");
  for (i = 0; i < 9; i++) {
    printf(" [%d] ", vet_retirados[i]);
  }
  return 0;
}
