#include <stdlib.h>
#include <stdio.h>

int main() {
    
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
        printf("%.2f | ", num[i]);
    };

    //ordenação
    float aux;

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if ((num[i]) > (num[j])) {
            aux = num[i];
            num[i] = num[j];
            num[j] = aux;
        } 
        }
    }

    //vetor ordenado
    printf("\nVetor ordenado -> ");
    for(int i = 0; i < n; i++){
        printf("%.2f | ", num[i]);
    };
    
    free(num); //liberando a memoria

}