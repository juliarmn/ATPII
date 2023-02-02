#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Protótipo:
int TransformaDec(char*, int);
void TransformaRom(int, char*);

int main(void) {
  int N, i, C, num, soma = 0, dec;
  char romano[100], str[100];
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &C);
    if(C == 1){
      scanf("%s", romano);
      dec = TransformaDec(romano, strlen(romano));
      printf("%d\n", dec);
      soma += dec;
    }else{
      scanf("%d", &num);
      TransformaRom(num, str);
      printf("%s\n", str);
    }
  }
  printf("%d\n", soma);
  return 0;
}

int TransformaDec(char *romano, int tamanho){
  int resultado = 0, i, num[200] = {0}; 
  char c;
  for(i = 0; i < tamanho; i ++){
    c = romano[i];
      switch(c){
        case 'I': num[i] = 1;break;
        case 'V': num[i] = 5;break;
        case 'X': num[i] = 10;break;
        case 'L': num[i] = 50;break;
        case 'C': num[i] = 100;break;
        case 'D': num[i] = 500;break;
        case 'M': num[i] = 1000;break; 
    }
  }
  for(i = 0; i < tamanho; i++){
    if(num[i] < num[i + 1]){
      resultado += num[i + 1] - num[i];
      i++;
    }else{
      resultado += num[i];
    }
  }
  return(resultado);
}

void TransformaRom(int numero, char*romano){
  int i = 0;
  while(numero != 0){
    if(numero >= 1000){
      romano[i] = 'M';
      i++;
      numero -= 1000;
    }else if(numero >= 900){
      romano[i] = 'C';
      i++;
      romano[i] = 'M';
      i++;
      numero -= 900;
    }else if(numero >= 500){
      romano[i] = 'D';
      i++;
      numero -= 500;
    }else if(numero >= 400){
      romano[i] = 'C';
      i++;
      romano[i] = 'D';
      i++;
      numero -= 400;
    }else if(numero >= 100){
      romano[i] = 'C';
      i++;
      numero -= 100;
    }else if(numero >= 90){
      romano[i] = 'X';
      i++;
      romano[i] = 'C';
      i++;
      numero -= 90;
    }else if(numero >= 50){
      romano[i] = 'L';
      i++;
      numero -= 50;
    }else if(numero >= 40){
      romano[i] = 'X';
      i++;
      romano[i] = 'L';
      i++;
      numero -= 40;
    }else if(numero >= 10){
      romano[i] = 'X';
      i++;
      numero -= 10;
    }else if(numero >= 9){
      romano[i] = 'I';
      i++;
      romano[i] = 'X';
      i++;
      numero -= 9;
    }else if(numero >= 5){
      romano[i] = 'V';
      i++;
      numero -= 5;
    }else if(numero >= 4){
      romano[i] = 'I';
      i++;
      romano[i] = 'V';
      i++;
      numero -= 4;
    }else{
      romano[i] = 'I';
      i++;
      numero -= 1;
    }
  }
  romano[i] = '\0';
}
