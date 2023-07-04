/****

LAED1 - Projeto (Parte II) - Estimativa do formato da pista

Alunos(as): Augusto de Oliveira Soares

Data:

****/

#include <stdlib.h>
#include <stdio.h>

#define LIMIAR_DIREITA 100
#define LIMIAR_ESQUERDA -100

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

/* ========================================================================= DECLARA�AO DE FUNCOES*/

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere(TipoItem x, TipoLista *Lista);
void ImprimeEValida(TipoLista Lista, int L);

/* ========================================================================= VARIAVEIS GLOBAIS*/

int padrao1[3] = {3,2,3};
TipoApontador Aux;
int result = 0;

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

void ImprimeEValida(TipoLista Lista, int L){
	
	int i=0, status = 0, vetorescertos = 0, primeiroValidado = 0, PMupperLine, PMlowerLine, diff;
	float  aux1, aux2, accuracy;
	
	Aux = Lista.Primeiro -> Prox;	
	
	while (Aux != NULL){//percorre todas as celulas
		
		/*printf("\n");
		printf("%d\n", Aux -> Item.Chave);
		printf("%d\n", Aux -> Item.TipoCor);
		printf("%d\n", Aux -> Item.Quant);
		printf("%d\n", Aux -> Item.PontoMedio);
		printf("%d\n", Aux -> Item.UltimoSegmento);
		printf("\n\n");*/
		
		//printf("\n\n\nNOVO SEGMENTO\n");
		//printf("ultimo seg: %d\n\n\n", Aux -> Item.UltimoSegmento);
			
		if(status == 0){
			//------------------caso normal----------------------	
			
			//printf("\n-----CASO NORMAL-----\n");
			//printf("\n-----i: %d-----\n",i);
			
			if(padrao1[i] != Aux -> Item.TipoCor){//padrao 1 � um vetor {3,2,3}
			
				i = 0;//sempre que o tipo da cor quebrar o padrao1.
				//printf("%d \n\n",i);
	
				if(padrao1[i] == Aux -> Item.TipoCor){
					i++;//se esse quebra for com o tipo da cor que come�a o padrao (o tipo 1), ele ja vai contar desde aqui.
					//printf("%d \n\n",i);
				}
		
			}else{
				
				i++;
				//printf("%d \n\n",i);
				
				if(i == 2){
					if(primeiroValidado == 0){
						PMupperLine = Aux -> Item.PontoMedio;//pega o ponto medio segmento de pista vermelho(pista) da linha mais alta
						//printf("upper: %d \n\n",PMupperLine);
				
					}else{
						PMlowerLine = Aux -> Item.PontoMedio;//pega o ponto medio segmento de pista vermelho(pista) da linha mais baixa
						//printf("lower: %d\n",PMlowerLine);
					}
				}
				
				if(i == 3){
					status = 1;
					primeiroValidado = 1;
				}
	
			}//caso i chegue a 5, quer dizer que h� padr�o 1 no vetor.
		
			if(Aux -> Item.UltimoSegmento == 1){
				//printf("\n\nstatus: %d\n\n", status);
				
				if(status == 1){
					vetorescertos++;
					status = 0;
					i=0;
				}
			}
		
		Aux = Aux -> Prox;
		
    	}
	}
    //printf("\n\nvetores corretos: %d", vetorescertos);
    //printf("\n\nlinhas: %d", L);
    
    aux1 = vetorescertos;
    aux2 = L;
    accuracy = aux1/aux2;
    
    //printf("\n\nacc: %f\n\n", accuracy);
    
    if(accuracy>=0.7){
    		
    	diff = PMupperLine-PMlowerLine;//subtracao do ponto medio da pista da linha mais abaixo pela mais de cima
    	
    	if(LIMIAR_ESQUERDA <=  diff && diff <= LIMIAR_DIREITA){
    		
    		result = 1;//RETO
    		
		}else if(diff > LIMIAR_DIREITA){
    		
    		result = 2;//CURVA DIREITA
    		
		}else if(diff < LIMIAR_ESQUERDA){
    		
    		result = 3;//CURVA ESQUERDA
    		
		}
	}
}

/* ========================================================================== */

int main(){

	FILE *arquivoSegmentos;
	char nomeArquivo[50];
	int N,L,i,j,k, sizeSegmento = 1, atual, proximo;
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
		//printf("\%d\n\n",N);
	}//COISAS DA FILE

	
	for(i=0; i < L;i++){
		k=0;
		for (j=0; j < N; j++){
	  		
			atual = elementosVetores[j][i];
			proximo = elementosVetores[j+1][i];
			//printf("atual: %d\n",atual);
			//printf("proximo: %d\n\n",proximo);
			
			if(atual == proximo && (j+1)!=N){
				
	    		sizeSegmento++;
	    		item[k][i].UltimoSegmento = 0;
	    		
	  		}else{//quanto o segmento acaba, registrado os valores no vetor de TipoItem "item".
	
				item[k][i].Chave = k+1;
				item[k][i].Quant = sizeSegmento;
				item[k][i].PontoMedio = ((j-(--sizeSegmento))+j)/2;//conta que representa (p+q)/2.
				item[k][i].UltimoSegmento = 1;
				
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
				sizeSegmento = 1;//"zera" o contador de unidades por segmento.
	  		}
	  	}	
	}
	
	ImprimeEValida(lista, L);
	
	if(result == 1){
		
		printf("Resultado: Pista em linha reta.");
		
	}else	if(result == 2){
		
		printf("Resultado: Curva a direita.");
		
	}else	if(result == 3){
		
		printf("Resultado: Curva a esquerda.");
		
	}else{
		
		printf("Resultado: Formato da pista nao estimado.");
	}

	return 0;
}
