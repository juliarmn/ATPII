#include <stdio.h>

void bin(int);

int main(void) {
  int n;
  printf("Digite\n");
  scanf("%d", &n);
  printf("pintu: %d\n", n);

  bin(n);
  return 0;
}

void bin(int num){
  if(num%2==num){
    printf("%d", num);
  }else{
    bin(num/2);
    printf("%d", num%2);
  }
}
