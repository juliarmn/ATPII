 #include <stdio.h>
//Protótipos:
int fatorial(int);


int main(void) {
  int num;
  printf("Digite um número\n");
  scanf("%d", &num);
  printf("fatorial: %d\n", fatorial(num));
  return 0;
}

int fatorial(int num){
  int fat = num;
  if(num == 1 || num == 0){
    fat = 1;
  }
  if(num > 1){
      fat = fat * fatorial(num-1);
  }

  return(fat);
}
