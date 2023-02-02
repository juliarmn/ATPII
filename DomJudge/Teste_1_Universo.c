
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	typedef struct planetas{
		char nome[21];
		double peso;
		double x;//Declara como double por causa da função sqrt
		double y;
		double z;
	} Planeta;
  
	int i, j;
	int N;//Número de planetas
	int M;//número de informações a serem produzidas
	int op;
	double x1, x2, y1, y2, z1, z2;
	double distancia;
	scanf("%d", &N);
	scanf("%d", &M);
	Planeta planeta[N];
	char primeiroPlaneta[21], segundoPlaneta[21];
  
	for(i = 0; i < N; i ++){
		scanf(" %s", planeta[i].nome);
		scanf("%lf", &planeta[i].peso);
		scanf("%lf", &planeta[i].x);
		scanf("%lf", &planeta[i].y);
		scanf("%lf", &planeta[i].z);
	}
	
	for(i = 0; i < M; i ++){
		scanf("%d", &op);
		if(op == 1){//Calcular a distância entre dois planetas
			scanf(" %s", primeiroPlaneta);
			scanf(" %s", segundoPlaneta);
			for(j = 0; j < N; j ++){
				if(strcmp(primeiroPlaneta, planeta[j].nome) == 0){
				 	x1 = planeta[j].x;
				 	y1 = planeta[j].y;
				 	z1 = planeta[j].z;
				}
				if(strcmp(segundoPlaneta, planeta[j].nome) == 0){
					x2 = planeta[j].x;
				 	y2 = planeta[j].y;
				 	z2 = planeta[j].z;
				}
			}
			distancia = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2) + pow((z2 - z1),2));
			printf("%.2lf\n", distancia);
		}
		if(op == 2){
			scanf(" %s", primeiroPlaneta);
			for(j = 0; j < N; j ++){
				if(strcmp(primeiroPlaneta, planeta[j].nome) == 0){
					printf("%.lf ", planeta[j].x);
					printf("%.lf ", planeta[j].y);
					printf("%.lf\n", planeta[j].z);
				}
			}
		}
		if(op == 3){
			scanf(" %s", primeiroPlaneta);
			for(j = 0; j < N; j ++){
				if(strcmp(primeiroPlaneta, planeta[j].nome) == 0){
					printf("%.2lf\n", planeta[j].peso);
				}
			}
		}	
	}
return 0;
}
