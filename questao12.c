#include <stdio.h>

int soma(int a, int b){
    int soma = a+b;
    return soma;
}

int subtracao(int a, int b){
    int sub = a-b;
    return sub;
}

int operacao(int a, int b, int (*op)(int,int)){
    int x = op(a,b);
    return x;
}

int main (){

    int a = operacao(7, 5, soma);
    int b = operacao(7, 5, subtracao);

    printf("Soma = %d\n", a);
    printf("Diferença = %d\n", b);    
}