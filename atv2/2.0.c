#include <stdio.h>


int main(){

	int n, k=1, i;

	printf("Digite a quantidade de numeros: ");
	scanf("%d", &n);

	int vetor[n];

	printf("Digite a sequencia de numeros: ");

	for(i=0;i!=n;i++){

		scanf("%d",&vetor[i]);

	}

	for(i=1;i<=n;i++){

		if(vetor[i] != vetor[i-1]){

			vetor[k] = vetor[i];
			k++;

		}
	}

	printf("\nResultado: existe(m) %d numero(s) na sequencia final", k-1);
        printf("\nSequencia final: ");

	for(i=0;i<k-1;i++){

		printf("%d ", vetor[i]);

	}

	return 0;

}



