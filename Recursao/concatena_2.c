#include <stdio.h>
#include <string.h>

void Troca(char*, char*, char*, int);

int main(void) {
  char A[50], B[50], C[100];
  printf("Dê C:\n");
  scanf(" %[^\n]s", C);
  Troca(A, B, C, 0);
  printf("%s\n%s", A, B);
  return 0;
}

void Troca(char *A, char*B, char*C, int in){
  if(C[in] == '\0'){
    return;
  }else{
    A[in] = *C;
    C++;
    B[in] = *C;
    C++;
    Troca(A, B, C, in+1);
  }
}
