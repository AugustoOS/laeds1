#include <stdio.h>

int num, i=0,fim=0,k=0,gap, auxk, soma=0;

int main(){



	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	int vetor[num];

	while(i<num){

		vetor[i] = 0;
		i++;

	}

	vetor[0] = num;

	printf("Decomposicao:\n");
	
	
	while(fim==0){
		
		soma = num;
		
		for(auxk = 0;auxk<=k;auxk++){
			
			if(auxk == k){
				printf("%d",vetor[auxk]);
				printf("\n");
				
			}else{
				printf("%d + ",vetor[auxk]);	
				
			}
			
			soma += vetor[auxk];
		}
		
		for(auxk = k;auxk>=0;auxk--){
			
			soma -= vetor[auxk];
			
			if(vetor[auxk]>1){
				gap = num - soma;
				vetor[auxk]--;
				vetor[auxk+1] = gap+1;
				k = auxk+1;
				
				while(vetor[auxk+1] > vetor[auxk]){
					auxk++;
					vetor[auxk]--;
					vetor[auxk+1]++;
					k = auxk+1;
				}
				
				auxk = -2;//faz parar o for sem cair no if final
	
			}
			
			
			
		}
	
		if(auxk == -1){//caso quando todos os valores sejam 1
			fim = 1;
			
		}	
	}

	
	return 0;
	
}
