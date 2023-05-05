#include <stdio.h>

int main(){

	FILE *fp;
	char nome[100];
	int n, i, j, k=0, aux, vetor_caixas[400], possibilidades, fileira_resposta, caixa_resposta, max = 0, soma, iref, jref, count = 0;

	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome);
	
	fp = fopen(nome,"r");
	
	fscanf(fp, "%d", &n);

	int matriz[20][n];

	for(i=0; i < n; i++){
		for(j=0; j<=i;j++){

			fscanf(fp, "%d", &matriz[j][i]);
			vetor_caixas[k] = matriz[j][i];
			
			k++;
				
		}		
	}
		
	possibilidades = (n*(n+1))/2;
	aux = n-2;
	iref = n;
	jref = n;
	
	for(k = possibilidades-1; k >= 0; k--){
		
		if(count == aux+2){
			
			iref = aux+1;
			jref = aux+1;
			aux--;
			count = 0;
			
		}
		
		soma = vetor_caixas[k];
		
    	for(i=aux; i >= 0; i--){
			
            for(j=i; j >= 0;j--){
				   	
				soma = soma + matriz[j][i];
				
			}
		}

		if(soma > max){
			max = soma;
			fileira_resposta = iref;
			caixa_resposta = jref;
		
		}
		
		count++;
		jref--;
		
	}
	
	printf("Resposta: fileira %d, caixa %d.", fileira_resposta, caixa_resposta);
	
	fclose(fp);
	
	return 0;

}

