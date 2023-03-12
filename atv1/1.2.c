#include <stdio.h>
#include <locale.h>
#include <string.h>

void dec2bin(int dec);

//-----------------------------------------------------

int main(){
	
	setlocale (LC_ALL, "");
	setlocale (LC_CTYPE, "pt_BR.UTF-8");
	
	int dec;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &dec);
	printf("Resultado: ");
	
	dec2bin(dec);
	
	return 0;
	
}

void dec2bin(int dec){
	
	int digit;
	
	if(dec/2 == 0){
		
		printf("%d", dec%2);
		
	}else{
		
		digit = dec/2;
		dec2bin(digit);
		printf("%d", dec%2);
	}
	
}

