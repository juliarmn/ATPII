#include <stdio.h>

float harmonico(float);

int main(void) {
  float n;
  printf("Digite o N\n");
  scanf("%f", &n);
  printf("%.2f", harmonico(n));
  return 0;
}

float harmonico(float n){
  if(n == 1){
    return 1;
  }else{
    return((1/n)+(harmonico(n-1)));
  }
}
