#include <stdio.h>
#include <stdlib.h>

int comparacao(const void *a, const void *b){
    if (*(int*)a == *(int*)b){
        return 0;
    }

    else {
        if (*(int*)a > *(int*)b){
            return 1;
        }
        else {
            return -1;
        }
    }
}

void main(){

     //coletando n
    printf("Informe a quantidade de números: ");
    int n;
    scanf("%i", &n);

    //alocando a memoria
    float *num = malloc(n*sizeof(float));

    //preenchendo o vetor
    for(int i = 0; i < n; i++){
        printf("\nInforme o valor do %dº número: ", i+1);
        scanf("%f", &num[i]);
    };

    //vetor desordenado
    printf("\nVetor desordenado -> ");
    for(int i = 0; i < n; i++){
        printf("%.1f | ", num[i]);
    };

    //chamando a função de ordenacao
    qsort(num, n, sizeof(float), comparacao);

    //imprimindo vetor ordenado
    printf("\nVetor ordenado -> ");
    for(int i = 0; i < n; i++){
        printf("%.1f | ", num[i]);
    };

    free(num); //liberando a memoria

}