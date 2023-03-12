#include <stdio.h>
#include <locale.h>

int Digitos(int N, int i);

//-----------------------------------------------------

int main(){
	
	setlocale (LC_ALL, "");
	setlocale (LC_CTYPE, "pt_BR.UTF-8");
	
	int result, num;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	result = Digitos(num, 1);
	printf("Resultado: %d", result);
	
	return 0;
	
}

int Digitos(int N, int i){
	
	if(N>=10){
		
		N = N/10;
		i++;
		
		return Digitos(N, i);
		
	}else{
		
		return i;
		
	}
	
}
