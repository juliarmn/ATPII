#include <stdio.h>
#include <locale.h>
 int main(){
 	setlocale(LC_ALL, "Portuguese");
 	FILE *fp = fopen("numerosELetras.txt", "r+");
 	int fim;
 	int count = 0, i;
 	int letra[16];
 	if(fp == NULL){
 		return 0;
	 }
	 fim = fseek(fp, 0, SEEK_END);
	 printf("%d", fim);
	fprintf(fp, "\n");
	for(i = 0; i < count; i ++){
		fprintf(fp, "%c", letra[i]);
	}
	fclose(fp);
	return 0;
 }
