#include <stdio.h>
#include <string.h>

void inverte(char*, int);

int main(void) {
  char str[60];
  printf("Digite\n");
  scanf("%s", str);
  inverte(str,strlen(str) - 1);
  return 0;
}

void inverte(char *str, int tam){
  if(tam == 0){
    printf("%c", str[tam]);
  }else{
    printf("%c", str[tam]);
    inverte(str, tam - 1);
  }
}
