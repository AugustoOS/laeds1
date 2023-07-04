#include <stdio.h>
#include <stdlib.h>

void ordenar(int *vetor, int tamanho);
int deletarElementosDuplicados(int *vetor, int size);

/* ========================================================================= */

int main()
{
	
	struct Elementos{
    int numElementos; 
    int tipoSegmento;
    int valor;
  };	
	
	struct Elementos elemento[500];	
  	FILE *arquivoSegmentos;
  	char nomeArquivo[49];
  	int i,j,N,linha,coluna;

  	printf("Digite o nome do arquivo: ");
  	scanf("%s", nomeArquivo);
  	arquivoSegmentos = fopen(nomeArquivo, "r");
  	fscanf(arquivoSegmentos, "%d", &N);
 	int elementosVetor[N];
  
  	for (i = 0; i < N; i++){
    	fscanf(arquivoSegmentos, "%d ", &elementosVetor[i]);
  	}

/* ========================================================================= */

	int K = 0, count = 1, last;
	int **segmento;
	segmento = (int **)malloc(2 * sizeof(int *));
	
	for (i = 0; i < 2; i++) segmento[i] = (int *)malloc(N * sizeof(int));
  
	// ver quantos segmentos tem no arquivo
	for (i = 0; i < N; i++){
		last = elementosVetor[i];
		if ((elementosVetor[i + 1]) == last && (i+1)!=N){
    	++count; // conta a quantidade de elementos repetidos sequencialmente
    	}
    	else{
    		elemento[K].valor = elementosVetor[i]; // contar a sequencia de elementos, se salvo
    		elemento[K].numElementos = count;      // o valor do elemento e quantas vezes se repete
    		count = 1;  // reseta a quantidade de elementos contadas
    		K++; // contabiliza a quantidade de segmentos
    	}
  	}

	int totalSegmentos = K;
	// aloca dinamicamente um vetor para salvar os valores obtidos no arquivo
	int *crescenteValor;
	crescenteValor = (int *)malloc(K*sizeof(int));
  
	for(i=0;i<K;i++){
		crescenteValor[i]=elemento[i].valor;
	}
  
	ordenar(crescenteValor, K); // pega os valores obtidos e os ordena de forma crescente deleta elementos repetidos.
	K = deletarElementosDuplicados(crescenteValor, K);  

    for(i=0; i<totalSegmentos;i++){ // percorre todos os segmentos.
    
        for(j=1; j<=K;j++){ // a cada vez percorrida do segmento, verifica em qual tipo de segmento, o elemento se atribui.
                               
            if(elemento[i].valor==crescenteValor[j-1]){
                elemento[i].tipoSegmento = j;
            }
        }
    }

  	for(linha=0; linha<2;linha++){ // preenche a matriz alocada dinamicamente na linha 75 e 76.
        for(coluna=0; coluna<totalSegmentos; coluna++){
            if(linha==0){
            	segmento[linha][coluna]= elemento[coluna].tipoSegmento; // preenche a 1* linha com o tipo de segmento.
            }                                                        
            else{
            	segmento[linha][coluna]= elemento[coluna].numElementos; // preenche a 2* linha com a quantidade de elementos de mesmo segmento registrados sequencialmente.
            }                                                   
        }                                                      
    } 

    printf("Matriz:\n");
    
    for(linha=0; linha<2;linha++){ // imprime a matriz
    	for(coluna=0; coluna<totalSegmentos; coluna++){
        	printf("%d ", segmento[linha][coluna]);
        }
		printf("\n");
	}

  fclose(arquivoSegmentos);
  
  return 0;
  
}   


int  deletarElementosDuplicados(int* vetor,int size){
    int i,j;
    for(i=1;i<size;i++){	
        if(vetor[i]==vetor[i-1]){
            for (j=i;j<size;j++){
            	
                vetor[j-1]=vetor[j];
                
            }
            
            i--;
            size--;
            
        }
    }
            
    return size;
          
}

void ordenar(int *vetor, int tamanho){ // void ordenacao retirado do SO.
    int i,j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
            	
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                
            }
        }
    }
}

