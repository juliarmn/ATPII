#include <stdio.h>
#include <string.h>

int quantos(char senha[10][11], int N) {
  int i, j, soma = 0;
  char *pointer;
  for (j = 0; j < N; j++) {
    for (i = 0; i < N; i++) {
      if(j != i){
        if (strstr(senha[j], senha[i])) {
            soma++;
          }
      }
     
    }
  }

  return soma;
}

int main(void) {
  int N, i;
  char senha[10][11];
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", senha[i]);
  }
  printf("%d", quantos(senha, N));
  return 0;
}
