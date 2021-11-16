#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparador(const void *a, const void *b){
    return *(int*)a-*(int*)b;
};

void main(){
int n;

//coletando n
printf("Informe a quantidade de números: ");
scanf("%d", &n);

//alocando a memoria do vetor
float *num = malloc(n*sizeof(float));

//preenchendo o vetor com numeros aleatorios
for (int i = 0; i < n; i++)
{
    num[i] = rand();
}

// coletando o tempo inicial
clock_t t = clock();

//ordenando com qsort
qsort(num, n, sizeof(float), comparador);

//coletando o tempo de execução (subtraindo o tempo final pelo tempo inicial)
t = clock() - t;

//mostrando o tempo de execução do qsort
printf("\n O qsort levou %f segundos para ordenar\n", ((float) t)/CLOCKS_PER_SEC);

//preenchendo novamente o vetor com numeros aleatorios
for (int i = 0; i < n; i++)
{
    num[i] = rand();
}

int aux;

//coletando o tempo inicial
clock_t t2 = clock();

//ordenando com o método próprio
for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if ((num[i]) > (num[j])) {
            aux = num[i];
            num[i] = num[j];
            num[j] = aux;
        } 
        }
    }

//coletando o tempo de execução (subtraindo o tempo final pelo tempo inicial)
t2 = clock() - t2;

//mostrando o tempo de execução do método próprio
printf("\n O outro método levou %f segundos para ordenar\n", ((float) t2)/CLOCKS_PER_SEC);
}

/*com um vetor pequeno, por vezes, o método próprio até foi mais rápido que o qsort.
porém, com vetores extremamente grandes, a diferença de tempo de execucao é muito considerável.
com um vetor de 100 mil números, o método próprio levou mais de 1 minuto; o qsort precisou de
apenas 3 CENTÉSIMOS!!!!*/