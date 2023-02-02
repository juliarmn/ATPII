#include <stdio.h>

int main(){
	FILE *fp = fopen("pares.txt", "r");
	FILE *fg = fopen("esquisito.txt", "w");
	char letra = 'A';
	int valor;
	if(fp == NULL){
		printf("\nDigite um nome válido\n");
		return 0;
	}
	do{
		fscanf(fp, "%d", &valor);
		fprintf(fg, "%d%c", valor, letra);
		letra = (letra + 1 - 'A')%26 + 'A';
	}while(!feof(fp));
	fclose(fp);
	fclose(fg);
	return 0;
}
