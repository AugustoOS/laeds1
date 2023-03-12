
#include <stdio.h>
#include <locale.h>

int mult (int base, int exp, int stack);

//-----------------------------------------------------

int main(){

	setlocale (LC_ALL, "");
	setlocale (LC_CTYPE, "pt_BR.UTF-8");

    int x,n,s = 0, result;

    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &x, &n);

    result = mult(x,n,s);

    printf("Resultado: %d", result);

    return 0;

}


int mult(int base, int exp, int stack){

    if(exp == 0 && stack == 0){

        stack = 1;

        return stack;

    }else if(exp != 1){
        
        if(stack == 0){

            stack = base*base;
            exp--;

         }else{

            stack= stack*base;
            exp--;

        }

    return mult(base,exp,stack);

    }else{
    
        return stack;
    
    }
}
