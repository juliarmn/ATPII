#include <stdio.h>
#include <string.h>

int main(void) {
  char nom[40] = {'a', 'a', 'b',  'c', 'a', 'b', 'c', 'a', 'a', 'a', 'b', 'c', '\0'}, num[40]={'a', 'b', 'c', '\0'};
  int tam1, soma = 0;
  char *ponta;
  ponta = nom;
  
  while(*ponta != '\0'){
    ponta = strstr(ponta, num);
    if (ponta != NULL){
      ponta ++;
      soma ++;
    }else{
      break;
    }
  }
  printf("%d", soma);
  return 0;
}
