//Aniversário
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	FILE *ani = fopen("aniversario.txt", "r");
	int dia, mes, ano,dAni, mAni, aAni, i = 0;
	struct user{
		char nome[90];
		int idade;
	}usuario[4];
	if(ani == NULL){
		printf("\nArquivo não encontrado\n");
	}else{
		printf("\nDigite o dia de hoje\n");
		scanf("%d", &dia);
		printf("\nDigite o mês de hoje\n");
		scanf("%d", &mes);
		printf("\nDigite o ano de hoje\n");
		scanf("%d", &ano);
		do{
			fscanf(ani, " %s %d %d %d", usuario[i].nome, &dAni, &mAni, &aAni);
			usuario[i].idade = ano - aAni;
			if(mes < mAni){
				usuario[i].idade --;
			}
			if(mes == mAni && dia < dAni){
				usuario[i].idade --;
			}
			i++;
		}while(!feof(ani));
		fclose(ani);
		for(i = 0; i < 4; i ++){
			printf("\nNome: %s", usuario[i].nome);
			printf("\tIdade: %d", usuario[i].idade);
		}
		}
return 0;
}
