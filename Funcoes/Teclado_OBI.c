#include <stdio.h>
#include <string.h>

int saida(char*N, char*c){
  if(strlen(N) != strlen(c)){
    return 0;
  }else{
     for (int i = 0; i < strlen(N); i++) {
        if (N[i] == '1' && c[i] != ' ') {
          return 0;
        }
        if (N[i] == '2' && c[i] != 'a' && c[i] != 'b' && c[i] != 'c') {
          return 0;
        }
        if (N[i] == '3' && c[i] != 'd' && c[i] != 'e' && c[i] != 'f') {
          return 0;
        }
        if (N[i] == '4' && c[i] != 'g' && c[i] != 'h' && c[i] != 'i') {
          return 0;
        }
        if (N[i] == '5' && c[i] != 'k' && c[i] != 'l' && c[i] != 'j') {
          return 0;
        }
        if (N[i] == '6' && c[i] != 'n' && c[i] != 'o' && c[i] != 'm') {
          return 0;
        }
        if (N[i] == '7' &&  c[i] != 'p' && c[i] != 'q' && c[i] != 'r' && c[i] != 's') {
          return 0;
        }
        if (N[i] == '8' && c[i] != 't' && c[i] != 'u' && c[i] != 'v') {
          return 0;
        }
        if (N[i] == '9' && c[i] != 'w' && c[i] != 'x' && c[i] != 'y'&& c[i] != 'z') {
          return 0;
        }
      }
    }
  return 1;
}

int main(void) {
  char N[1000], C[1000], c;
  int M, sai = 0, flag;
  scanf("%s", N);
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%s", C);
    if(saida(N, C)==1){
      sai++;
    }
  }
  
  printf("%d\n", sai);
  return 0;
}
