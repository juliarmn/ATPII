//Declaracao de bibliotecas
#include <stdio.h>//Biblioteca padrao
#include <string.h>//manipulacao de strings
#include <locale.h>//Acentuacao
#define max 250 //Numero alto para ler a string
//Prototipos das funçoes:
void escrever(int, FILE*, FILE*);
//Variáveis globais:
char str[max], aux[5][max];//matriz de string com 5 posiçoes pois o número maximo e 5
int i, j, count = 0;
int main(){
	setlocale(LC_ALL, "Portuguese");
	//Declaraçao dos arquivos:
	FILE *codigos, *palavras, *linhas; 
	//Variaveis:
	int num, quebraLinha;
	quebraLinha = 0;
	//Abertura dos arquivos:
	codigos = fopen("codigos.dat", "r");
	palavras = fopen("palavras.dat", "r");
	linhas = fopen("linhas.dat", "w");
	//Validar a existencia dos arquivos abertos para leitura:
	if(codigos == NULL || palavras == NULL){
		printf("\nArquivo não encontrado...\n");
		return 0;//Para de rodar o codigo, encerramento
	}
	//Caso exista o arquivo:
	while(!feof(codigos) && !feof(palavras)){//Caso nao tenha chegado ao fim do arquivo, continua rodando
		fscanf(codigos, "%d", &num);//leitura dos números no arquivo de codigos
		escrever(num, palavras, linhas);
	}
	while(!feof(codigos)){
		fscanf(codigos, "%d", &num);
		fprintf(linhas, "%d ", num);
	}
	while(!feof(palavras)){
		fscanf(palavras, "%s ", str);//Espaco importante para nao repetir a ultima palavra
      	quebraLinha++;//Para contar quando quebrar a linha
		fprintf(linhas, "%s ", str);
    	if(quebraLinha%5 == 0){//Em 5 palavras tem que pular a linha
     		fprintf(linhas, "\n");
    	}
	}
	//Fechar os arquivos apos sua manipulacao:
	fclose(codigos);
	fclose(palavras);
	return 0;
}
//Funcao para escrever em "linhas":
void escrever(int num, FILE* palavras, FILE* linhas){
	//Declara os arquivos:
	if(num == 0){//Se for 0, so precisa imprimir e pular a linha
		fprintf(linhas, "0\n");
	}else if(num > 0){//Aqui copia as palavras de acordo com num
		for(i = 0; i < num; i ++){
			fscanf(palavras, "%s", str);
			fprintf(linhas, "%s ", str);
			if(count < 5){//Copia os 5 primeiros
				strcpy(aux[count], str);//Copia em aux, pois quando tivermos que trocar as posicoes, uma matriz auxiliar sera utilizada
			}else{//Quando ja for maior que 5
				for(j = 0; j < 4; j ++){
					/*Para copiar as palavras da proxima posicao na anterior, 
					com a finalidade de colocar a ultima palavra na ultima posicao
					e copiar corretamente quando num < 0*/
					strcpy(aux[j], aux[j+1]);
				}
				strcpy(aux[4], str);//copia a nova palavra, quando count > 5, na ultima posicao
			}
			count ++;//incrementa count
			}
			fprintf(linhas, "\n");//Quebra de linha
	}else{//Se o numero for menor que 0, ele retorna e copia as ultimas palavras n vezes
		for(i = (5 + num); i < 5; i ++){//Como o valor e negativo, tem que somar com 5 para encontrar a posição correta para começar a copiar
				fprintf(linhas, "%s ", aux[i]);//Como aux já foi organizado anteriormente, é só copiar aux normalmente
			}
      fprintf(linhas, "\n");
		}
	}
