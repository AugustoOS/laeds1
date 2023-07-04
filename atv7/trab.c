
/****

LAED1 - Projeto (Parte I) - Busca por padrão em sequência

Alunos(as): Augusto de Oliveira Soares

Data: 30/05/2023

****/



#include <stdlib.h>
#include <stdio.h>

/* ========================================================================= LISTA*/

typedef struct {
	int Chave;
	int TipoCor;
	int Quant;
	int PontoMedio;
} TipoItem;

typedef struct TipoCelula* TipoApontador;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula;

typedef struct {
	TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= DECLARAÇAO DE FUNCOES*/

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere(TipoItem x, TipoLista *Lista);
void ImprimeEValida(TipoLista Lista);

/* ========================================================================= VARIAVEIS GLOBAIS*/

int padrao[5] = {1,3,2,3,1};
TipoApontador Aux;
int status;

/* ========================================================================= FUNCOES*/

void FLVazia(TipoLista* Lista){ 
	Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
	Lista -> Ultimo = Lista -> Primeiro;
	Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista){ 
	return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
	Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
	Lista -> Ultimo = Lista -> Ultimo -> Prox;
	Lista -> Ultimo -> Item = x;
	Lista -> Ultimo -> Prox = NULL;
}

void ImprimeEValida(TipoLista Lista){
	
	int i=0;
	Aux = Lista.Primeiro -> Prox;
	
	while (Aux != NULL){ 
/*		printf("\n");
		printf("%d\n", Aux -> Item.Chave);
		printf("%d\n", Aux -> Item.TipoCor);
		printf("%d\n", Aux -> Item.Quant);
		printf("%d\n", Aux -> Item.PontoMedio);
		printf("\n\n");*/
		
		if(padrao[i] == Aux -> Item.TipoCor){
		
			i++;
//			printf("%d \n\n",i);
			if(i == 5){
				status = 1;
				return;	
			}
	
		}else{
			
			i = 0;
//			printf("%d \n\n",i);
			if(padrao[i] == Aux -> Item.TipoCor){

				i++;
//				printf("%d \n\n",i);
		
			}
		}
		
		status = 0;
    	Aux = Aux -> Prox;
    	
    }
}



/* ========================================================================== */

int main(){

	FILE *arquivoSegmentos;
	char nomeArquivo[50];
	int N,i,j=0;

	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arquivoSegmentos = fopen(nomeArquivo, "r");
	fscanf(arquivoSegmentos, "%d", &N);

	
	TipoLista lista;
	TipoItem item[N];
	int elementosVetor[N];
	int sizeSegmento = 1, atual, proximo;
	
	FLVazia(&lista);
	
	for (i = 0; i < N; i++) {
		fscanf(arquivoSegmentos, "%d ", &elementosVetor[i]);
	}//COISAS DA FILE
	
	for (i = 0; i < N; i++){
  		
		atual = elementosVetor[i];
		proximo = elementosVetor[i+1];
		
		if (atual == proximo && (i+1)!=N){
    		sizeSegmento++;
  		}else{//quanto o segmento acaba, é registrado os valores no vetor de TipoItem "item".

			item[j].Chave = j+1;
			item[j].Quant = sizeSegmento;
			item[j].PontoMedio = ((i-(--sizeSegmento))+i)/2;//conta que representa (p+q)/2.
			
			if(elementosVetor[i] == 0){
				
				item[j].TipoCor = 1;
//				printf("%d ", item[j].TipoCor);
				
				
			}else if(elementosVetor[i] == 128){
				
				item[j].TipoCor = 2;
//				printf("%d ", item[j].TipoCor);	
				
				
			}else if(elementosVetor[i] == 255){
				
				item[j].TipoCor = 3;
//				printf("%d ", item[j].TipoCor);	
				
				
			}else{
				
				item[j].TipoCor = 0;
//				printf("%d ", item[j].TipoCor);
				
			}
			
			Insere(item[j], &lista);/*Insere valores nas celulas da lista */
			j++;//j representa a quantidade de celulas utilizaveis na lista.
			sizeSegmento = 1;//"zera" o contador de unidades por segmento.
			
  		}
  	}
    
	ImprimeEValida(lista);
	
	if(status == 1){
		
		printf("Resultado: Padrao encontrado.");
		
	}else{
		
		printf("Resultado: Padrao nao encontrado.");
	}

	return 0;
}
