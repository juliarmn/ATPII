#include <stdio.h>

float pot(int x, int exp);

int main(void) {
  float x;
  int exp;
  printf("Digite a base\n");
  scanf("%f", &x);
  printf("Digite o expoente\n");
  scanf("%d", &exp);
  printf("\n%.3f", pot(x,exp));
  return 0;
}

float pot(int x, int exp){
  if(exp == 1){
    return x;
  }
  if(exp == 0){
    return 1;
  }
  if(exp > 1){
    return(x*(pot(x,exp-1)));
  }else
  if(exp < 0 && exp != -1){
    return((1/(x*(pot(x, -exp-1)))));
  }else 
    if(exp == -1){
    return x;
  }
}
