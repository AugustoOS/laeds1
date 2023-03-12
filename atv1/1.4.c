#include <stdio.h>
#include <locale.h>

//------------------------------------

int mdc(int a, int b);


int main(){
	
	setlocale (LC_ALL, "");
	setlocale (LC_CTYPE, "pt_BR.UTF-8");
	
	int value1, value2, lower, higher, result;
	
	
	printf("Digite dois numeros inteiros: ");
	scanf("%d %d", &value1, &value2);
	
	if(value1 <= value2){
			
		lower = value1;
		higher = value2;	
			
	}else{
			
		lower = value2;
		higher = value1;
			
	}
	
	result = mdc(higher,lower);
	
	printf("Resultado: %d", result);

	return 0;
	
}

int mdc(int a, int b){

	if(b==0){
		
		return a;
		
	}else{
		
		return mdc(b, a%b);
		
	}

	
}

