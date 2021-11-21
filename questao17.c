#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função soma -> recebe o tamanho dos vetores e os ponteiros para cada vetor
void somadevetores(int n, int *vet1, int *vet2, int *vetsoma){
    for (int i = 0; i < n; i++)
    {
        vetsoma[i] = vet1[i] + vet2[i];
    }
    
}

void main(){

    int n;

    //coletando o tamanho do vetor
    printf("Informe a quantidade de números do vetor: ");
    scanf("%d", &n);
    
    //alocando a memoria dos vetores
    int *vet1 = malloc(n*sizeof(int));
    int *vet2 = malloc(n*sizeof(int));
    int *vetsoma = malloc(n*sizeof(int));

    //preenchendo os vetores com numeros aleatorios
    for (int i = 0; i < n; i++)
    {
        vet1[i] = rand()%100;
    }

    for (int i = 0; i < n; i++)
    {
        vet2[i] = rand()%100;
    }

    //chamando a função soma
    somadevetores(n, vet1, vet2, vetsoma);

    //imprimindo os vetores
    printf("Vetor 1\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d | ", vet1[i]);
    }

    printf("\nVetor 2\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d | ", vet2[i]);
    }

    printf("\nVetor soma\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d | ", vetsoma[i]);
    }
    
    free(vet1);
    free(vet2);
    free(vetsoma);
    }