#include <stdio.h>
#include <stdlib.h>
#define size 10001

//Main:
int main(){
	char *sinal, pegaStr[size];
	int i, j = 1, k, flag = 1;
	int ultimo;
	char aberto;
	scanf("%s", pegaStr);
	for(i = 0; i < size; i ++){
		if((pegaStr[i] == '{') || (pegaStr[i] == '}') || (pegaStr[i] == '[') || (pegaStr[i] == ']') || (pegaStr[i] == '(') || (pegaStr[i] == ')')){
			j ++;
		} 
	}
	sinal = (char*)malloc(j*sizeof(char));
	j = 0;
		for(i = 0; i < size; i ++){
		if((pegaStr[i] == '{') || (pegaStr[i] == '}') || (pegaStr[i] == '[') || (pegaStr[i] == ']') || (pegaStr[i] == '(') || (pegaStr[i] == ')')){
			sinal[j] = pegaStr[i];
			j ++;
		} 
	}
	while(flag == 1 && j != 0){
	
	for(i = 0; i < j; i ++){
		if(sinal[i] == '[' || sinal[i] == '{' || sinal[i] == '('){
			ultimo = i;
			aberto = sinal[i];
		}
		if(aberto == '[' && sinal[ultimo + 1] == ']'){
			for(k = ultimo; k < j; k ++){
				sinal[k] = sinal[k + 1];
			}
			j --;
			sinal = (char*)realloc (sinal , j*sizeof(char));
		}else if(aberto == '{' && sinal[ultimo + 1] == '}'){
			for(k = ultimo; k < j; k ++){
				sinal[k] = sinal[k + 1];
			}
			j --;
			sinal = realloc (sinal , j*sizeof(char));
		}else if(aberto == '(' && sinal[ultimo + 1] == ')'){
			for(k = ultimo; k < j; k ++){
				sinal[k] = sinal[k + 1];
			}
			j --;
			 sinal = realloc (sinal , j*sizeof(char));
		}else{
			flag = 0;
		}
	}
	}
	if(flag == 1){
		printf("S\n");
	}else{
		printf("N\n");
	}
	return 0;
}
