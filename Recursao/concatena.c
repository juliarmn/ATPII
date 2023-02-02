#include <stdio.h>
#include <string.h>

void Troca(char *, char *, char*, int);

int main(void) {
  char A[70], B[80], c[150];
  printf("Dê 1:\n");
  scanf(" %[^\n]s", A);
  printf("Dê 2:\n");
  scanf(" %[^\n]s", B);
  Troca(A, B, c, 0);
  printf("%s", c);
  return 0;
}

void Troca(char *A, char *B, char*c, int in){
  if(*A == '\0'){
      strcat(c, B);
      return;
  }else if(*B == '\0'){
    strcat(c, A);
    return;
  }else{
    c[in] = *A;
    c[in + 1] = *B;
    B++;
    A++;
    Troca(A, B, c, in + 2);
  }
}
