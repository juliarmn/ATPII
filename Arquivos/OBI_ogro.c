#include <stdio.h>

int main(void) {
  FILE *fp = fopen("saida.dat", "w");
  int num;
  printf("Digite o número\n");
  scanf("%d", &num);
  for(int i = 0; i < num; i ++){
    if(num <= 5 && i <= 5){
          fprintf(fp," I ");
    }else{
      if(i == 5){
        fprintf(fp, "\n");
        fprintf(fp," I ");
      }else{
        fprintf(fp," I ");
      }
    }
  }
  if(num <= 5){
    fprintf(fp, "\n");
    fprintf(fp," * ");
  }
  fclose(fp);
  return 0;
}
