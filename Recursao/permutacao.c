#include <stdio.h>
unsigned char alfbet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
char aux;

int permutacao(int n){
  if(n == 1){
    return 1;
  }else{
    return(n*permutacao(n-1));
  }
}

void permuta(int num, char*str, int per){
  int i;
    for(i = num - 1; i > 0; i --){
      aux = str[i];
      str[i] = str[i - 1];
      str[i - 1] = aux;
      printf("%s\n", str);
      per --;
    }
    if(per > 1){
          permuta(num, str, per);
    }
}

int main(void) {
  int num, i;
  char str[27];
  printf("\nDigite o num\n");
  scanf("%d", &num);
  for(i = 0; i < num; i ++){
    str[i] = alfbet[i];
  }
  permuta(num, str, permutacao(num));
  return 0;
}
