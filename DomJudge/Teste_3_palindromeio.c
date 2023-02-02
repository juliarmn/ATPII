#include <stdio.h>
#include <string.h>


int verifica (char *str, int tam, int ini) { //Verifica se é palindromo
  if (tam <= ini)
    return 1;
  else {
    if (str[tam] != str[ini])
      return 0;

    return verifica(str, tam - 1, ini + 1);
  }
}

int numPalindromo(char *str) { //Faz a subdivisão 
  int tam, i, j, k, total = 0;
  tam = strlen(str);
  char pal[tam];
  for (i = tam; i > 0; i--) {
    for (j = 0; j < tam - i + 1; j++) {
      total = 0;
      for (k = j; k < j + i; k++) {
        pal[total] = str[k];
        total++;
      }
      pal[total] = '\0';
      if (verifica(pal, total - 1, 0)) {
        return i;
      }
    }
  }
}

int main(void) {
  char k[2001];
  scanf("%s", k);
  printf("%d\n", numPalindromo(k));
  return 0;
}
