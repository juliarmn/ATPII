#include <stdio.h>
#include <string.h>
char aux[3][30];

int permutacao(int n){
  if(n == 1){
    return 1;
  }else{
    return(n*permutacao(n-1));
  }
}

void permuta(char mat[3][30], int n, int perm){
  for(int i = n - 1; i > 0; i --){
    strcpy(aux[i], mat[i]);
    strcpy(mat[i], mat[i - 1]);
    strcpy(mat[i-1], aux[i]);
    for(int j = 0; j < 3; j ++){
      printf("%s ", mat[j]);
    }
    printf("\n");
    perm --;
  }
  if(perm > 1){
    permuta(mat, n, perm);
  }
}

int main(void) {
  char  mat[3][30] = {{"Banana"},{"arroz"}, {"oie"}};
  permuta(mat, 3, permutacao(3));
  return 0;
}
