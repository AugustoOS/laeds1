/****

LAED1 - Projeto (Parte III) - Estimativa do formato da pista

Alunos(as): Augusto de Oliveira Soares

Data: 25/06/2023

****/

#include <stdlib.h>
#include <stdio.h>

/* ========================================================================= LISTA*/

typedef struct {
	int Chave;
	int TipoCor;
	int Quant;
	int PontoMedio;
	int UltimoSegmento;
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

int padrao1[3] = {1,3,2}, padrao2[3] = {2,3,1};
TipoApontador Aux;
int status = 0;

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
	
	int i=0,j=0, flag = 0;
	Aux = Lista.Primeiro -> Prox;
	
	while (Aux != NULL){
	
		/*printf("\n");
		printf("%d\n", Aux -> Item.Chave);
		printf("%d\n", Aux -> Item.TipoCor);
		printf("%d\n", Aux -> Item.Quant);
		printf("%d\n", Aux -> Item.PontoMedio);
		printf("\n\n");*/
		
		//printf("cor: %d\n\n", Aux -> Item.TipoCor);
		//printf("ultimo?: %d\n\n", Aux -> Item.UltimoSegmento);
		
		if(padrao1[i] == Aux -> Item.TipoCor){
			
			i++;
			//printf("---- 111111i: %d ----\n\n",i);
			
			if(i == 3){

					Aux = Aux -> Prox;
				
				
				while (flag != 1 && Aux != NULL){
					
					if(padrao2[j] == Aux -> Item.TipoCor){
						
						j++;
						//printf("---- 222222j: %d ----\n\n",j);
						
						
						if(j == 3){
							status = 1;
							return;
						}
				
					}else{
						j = 0;
						//printf("---- 222222j: %d ----\n\n",j);
					}
					
					if(Aux != NULL){
						if(Aux -> Item.UltimoSegmento == 1){
						
							flag = 1;
							j=0;
							//printf("\n--- ULTIMO SEGMENTO J---\n\n\n");
						
						}else{
							Aux = Aux -> Prox;
						}
					}
				}
				
				flag = 0;
			}
	
		}else{
			
			i = 0;
			//printf("---- 111111i: %d ----\n\n",i);
			if(padrao1[i] == Aux -> Item.TipoCor){
				i++;
			}
		}
		
		if(Aux -> Item.UltimoSegmento == 1){
			//printf("\n--- ULTIMO SEGMENTO I ---\n\n\n");
			i=0;		
		}
		
		if(Aux != NULL){
			Aux = Aux -> Prox;
		}
    		
	}	
	
}

/* ========================================================================== */

int main(){

	FILE *arquivoSegmentos;
	char nomeArquivo[50];
	int N,L,i,j,k, sizeSegmento = 1, atual, proximo, count = 0, somadorChaves = 0;
	TipoLista lista;
	
	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arquivoSegmentos = fopen(nomeArquivo, "r");
	fscanf(arquivoSegmentos, "%d", &L);
	//printf("%d\n\n",L);
	fscanf(arquivoSegmentos, "%d", &N);
	//printf("%d\n\n",N);
	TipoItem item[N][L];
	int elementosVetores[N][L];
	
	FLVazia(&lista);
	
	for(i=0; i < L; i++){
		for (j = 0; j < N; j++) {
			fscanf(arquivoSegmentos, "%d ", &elementosVetores[j][i]);
			//printf("%d ",elementosVetores[j][i]);
		}
		fscanf(arquivoSegmentos, "%d ", &N);
		//printf("\n\n%d\n\n",N);
	}//COISAS DA FILE

	
	for(i=0; i < L;i++){
		k=0;
		for (j=0; j < N; j++){

			atual = elementosVetores[j][i];
			if(j+1 !=N){
				proximo = elementosVetores[j+1][i];
			}else{
				proximo = 1;	
			}
			
			//printf("atual: %d\n",atual);
			//printf("proximo: %d\n\n",proximo);
			
			if(atual == proximo){
				
	    		sizeSegmento++;
	    		
	  		}else{//quanto o segmento acaba, eh registrado os valores no vetor de TipoItem "item".
				
				item[k][i].Chave = somadorChaves+1;
				item[k][i].Quant = sizeSegmento;
				item[k][i].PontoMedio = ((j-(--sizeSegmento))+j)/2;//conta que representa (p+q)/2.
				
				if((j+1)==N){
					//printf("\n\n----------%d------1111----\n\n",j);
					item[k][i].UltimoSegmento = 1;
					//printf("segmento %d Ultimo segmento: %d\n\n",item[k][i].Chave,item[k][i].UltimoSegmento);
					count++;
		  		}else{
		  			item[k][i].UltimoSegmento = 0;
					//printf("\n\n----------%d-----22222-----\n\n",j);  	
				}
				
				if(elementosVetores[j][i] == 0){
					
					item[k][i].TipoCor = 1;
					//printf("%d ", item[k][i].TipoCor);					
					
				}else if(elementosVetores[j][i] == 128){
					
					item[k][i].TipoCor = 2;
					//printf("%d ", item[k][i].TipoCor);
					
					
				}else if(elementosVetores[j][i] == 255){
					
					item[k][i].TipoCor = 3;
					//printf("%d ", item[k][i].TipoCor);
					
					
				}else{
					
					item[k][i].TipoCor = 0;
					//printf("%d ", item[k][i].TipoCor);
					
				}
				
				Insere(item[k][i], &lista);/*Insere valores nas celulas da lista */
				k++;//k representa a quantidade de celulas utilizaveis na em cada parte da lista.
				somadorChaves++; 
				sizeSegmento = 1;//"zera" o contador de unidades por segmento.
	  		}
	  	}	
	}
	
	//printf("\n\nCONTADOR DE LINHAS: %d\n\n", count);
    
	ImprimeEValida(lista);
	//printf("\n%d\n\n", status);
	
	if(status == 0){
		
		printf("Resultado: Pista sem impedimento.");
		
	}else{
		
		printf("Resultado: Pista com impedimento.");
	}

	return 0;
}
