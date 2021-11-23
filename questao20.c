#include <gc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Para efeito de comparação entre a alocação tradicional e utilizando a biblioteca libgc,
foram criadas duas funções que rodam a mesma coisa: a alocação de um vetor de float's com tamanho 50.
No método principal, utilizando a função clock() da biblioteca time.h, será medido o tempo de execucação
de cada função */

//essa função utiliza a alocação tradicional
void alocacaopadrao(){
    float *vet = malloc(50*sizeof(float));

    for (int i = 0; i < 50; i++)
    {
        vet[i] = rand()%10;
    }

    free(vet);
}

//essa função utiliza o libgc
void alocacaogc(){
    
    int *vet = GC_MALLOC(50*sizeof(float));

    for (int i = 0; i < 50; i++)
    {
        vet[i] = rand()%10;
    }
    
}

void main(){

    //aqui é medido o tempo de execução utilizando a libgc
    clock_t t = clock();
    alocacaogc();
    t = clock() - t;

    printf("libgc --> %f segundos", ((float) t)/CLOCKS_PER_SEC);

    //aqui é medido o tempo de execução utilizando a alocação tradicional
    clock_t t2 = clock();
    alocacaopadrao();
    t2 = clock() - t2;

    printf("\nAlocação tradicional --> %f segundos", ((float) t2)/CLOCKS_PER_SEC);

    //Como já era esperado, a função que utilizou a libgc levou mais tempo para ser processada
}