#include <stdio.h>
#include <locale.h>

int Digitos(int N, int i);

//-----------------------------------------------------

int main(){
	
	setlocale (LC_ALL, "");
	setlocale (LC_CTYPE, "pt_BR.UTF-8");

	int a, b;

	printf("Digite os dois numeros: ");
	scanf("%d %d", &a, &b);
	
	printf("Resultado = %d", a+b);
	
	return 0;
	
}
