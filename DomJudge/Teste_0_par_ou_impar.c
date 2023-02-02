#include <stdio.h>

int main(){
	int numJog;
	int A, B, i, soma;
	scanf("%d", &numJog);
	for(i = 0; i < numJog; i ++){
		scanf("%d", &A);
        scanf("%d", &B);
        soma = A + B;
        if(soma % 2 == 0){
        	printf("A\n");
		}else{
			printf("B\n");
		}
	}
	return 0;
}
