#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverte(char *, int, int);

int main(void) {
  char str[50];
  int i, j = 0;
  char pal[50];

  printf("Digite:\n");
  scanf(" %[^\n]s", str);
 for(int i = 0; i < strlen(str); i ++){
    str[i] = tolower(str[i]);
  }
  for (i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      pal[j] = str[i + 1];
      j++;
      i++;
    }else{
      pal[j] = str[i];
    j++;
    }
  printf("%s\n", str);
  if(inverte(pal, strlen(pal)-1, 0) == 0){
    printf("N\n");
  }else{
    printf("S\n");
  }
  return 0;
}
  }

int inverte(char *str, int tam, int aux) {
  if(tam <= aux){
    return 1;
  }else{
    if(str[tam] != str[aux]){
      return 0;
      }
      return(inverte(str, (tam-1), (aux+1)));
  }
}
