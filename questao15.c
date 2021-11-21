#include <stdio.h>
#include <stdlib.h>

//funcao de comparacao
//essa função ordena valores do tipo float em ordem crescente
void comparador(float *vet, int n){
    float aux;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if ((vet[i]) > (vet[j])) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        } 
        }
    }
}

//funcao de ordenacao -> recebe a quantidade de elementos, o vetor a ser ordenado e a funcao de comparacao

void ordenador(int n, float *vet, void (*comparador)()){
    comparador(vet, n);
}

void main(){

    //coletando n
    printf("Informe a quantidade de números: ");
    int n;
    scanf("%i", &n);

    //alocando a memoria
    float *vet = malloc(n*sizeof(float));

    //preenchendo o vetor
    for(int i = 0; i < n; i++){
        printf("\nInforme o valor do %dº número: ", i+1);
        scanf("%f", &vet[i]);
    };

    //vetor desordenado
    printf("\nVetor desordenado -> ");
    for(int i = 0; i < n; i++){
        printf("%.2f | ", vet[i]);
    };

    //ordenação
    ordenador(n, vet, comparador);

    //vetor ordenado
    printf("\nVetor ordenado -> ");
    for(int i = 0; i < n; i++){
        printf("%.2f | ", vet[i]);
    };

    free(vet); //liberando a memoria
}
