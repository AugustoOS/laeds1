#include <stdio.h>

int main(){

	FILE *fp;
	char nome[100];
	int quant_mochilas, quant_objetos,i;
	
	typedef struct{
		int peso;
		int preco;
	}Objeto;

	typedef struct{
		int capacidade;
		int peso_atual;
		int valor_montante;
	}Mochila;

	Objeto *objetos;
	Mochila *mochilas;
	
	printf("Digite o nome do arquivo: ");

	scanf("%s", nome);
	fp = fopen(nome,"r");
	
	fscanf(fp, "%d", &quant_mochilas);
	

	for(i=0;i<quant_mochilas;i++){
		fscanf(fp, "%d", &mochilas[i].capacidade);
	}
	
	fscanf(fp, "%d", &quant_objetos);
	objetos = (Objeto *)malloc(quant_objetos*sizeof(Objeto));
	
	for(i=0;i<quant_objetos;i++){
		fscanf(fp,"%d", &objetos[i].peso);
		fscanf(fp,"%d", &objetos[i].preco);
	}
	

	for(;;){

	}
	return 0;
}
