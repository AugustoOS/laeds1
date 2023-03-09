//1.1.c

#include <stdio.h>

int mult (int base, int exp, int stack);

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

    mult(base,exp,stack);

    }else{
    
        return stack;
    
    }
}

int main(){

    int x,n,s = 0, result;

    printf("Digite a base e o expoente: ");
    scanf("%d %d", &x, &n);

    result = mult(x,n,s);

    printf("resultado: %d", result);

    return 0;

}


