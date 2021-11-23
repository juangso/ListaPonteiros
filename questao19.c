#include <gc.h> //inclusão da biblioteca
#include <stdio.h>
#include <stdlib.h>

int main(){


/*Se chama a função "GC_MALLOC()" ao invés do "malloc()"
Ela possui a mesma sintaxe, recebendo como parâmetro o tamanho do bloco de memória*/

int *vet = (int*) GC_MALLOC(10*sizeof(int));

for (int i = 0; i < 10; i++)
{
    vet[i] = rand()%10;
}

for (int i = 0; i < 10; i++)
{
    printf("%d | ", vet[i]);
}

GC_FREE(vet); //liberando a memória -> a função "free()" é substituida por "GC_FREE()";
return 0;
}