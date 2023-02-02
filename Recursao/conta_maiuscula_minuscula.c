#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int maior(char*, int, int);
int menor(char*, int, int);
void conta(char*, int, int);


int main(void) {
  char str[50] = "O gatO dE BOTas", strSEspaco[50];
  int i, j = 0;
  for(i = 0; i < strlen(str); i++){
    if(str[i] == ' '){
      strSEspaco[j] = str[i + 1];
      j++;
      i++;
    }else{
      strSEspaco[j] = str[i];
      j++;
    }
  }
  printf("PINTU: %s\n", strSEspaco);
  printf("\n Maiúsculas: %d \n Minúsculas: %d\n", maior(strSEspaco, 0, strlen(strSEspaco) - 1), menor(strSEspaco, 0, strlen(strSEspaco) - 1));
  conta(str, 0, strlen(str) - 1);
  return 0;
}

int maior(char *str, int inicio, int tam){
  char c = str[inicio];
  if(inicio == tam){
    if(c == toupper(str[tam]))
      return 1;
    else
      return 0;
  }else{
    if(c == toupper(str[inicio])){
      return(1+(maior(str, inicio+1, tam)));
    }else{
      return(maior(str, inicio+1, tam));
    }

  }
}

int menor(char *str, int inicio, int tam){
  char c = str[inicio];
  if(inicio == tam){
    if(c == tolower(str[tam]))
      return 1;
    else
      return 0;
  }else{
      if(c == tolower(str[inicio])){
      return(1+(menor(str, inicio+1, tam)));
    }else{
        return((menor(str, inicio+1, tam)));
    }
  }
}

void conta(char* str, int inicio, int tam){
  char c = str[inicio];
  if(inicio == tam){
    if(c == tolower(str[tam]) && c != ' '){
      printf("%c", toupper(str[tam]));
    }else{
      printf("%c", tolower(str[tam]));
    }
    if(c == ' '){
      printf("%c", c);
    }
  }else{
     
      if(c == tolower(str[inicio]) && c != ' '){
        printf("%c", toupper(str[inicio]));
      }else if(c == toupper(str[inicio]) && c != ' '){
        printf("%c", tolower(str[inicio]));
      }else if(c == ' '){
        printf("%c", c);
      }
     conta(str, inicio + 1, tam);
  }
}
