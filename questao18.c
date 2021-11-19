#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multmatriz(int **a, int **b, int **c, int lin_A, int col_A, int col_B){
    for (int i = 0; i < lin_A; i++)
    {
        for (int j = 0; j < col_B; j++)
        {
            for (int k = 0; k < col_A; k++)
            {
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        } 
    }
}

void main (){

int **a, **b, **c;
int lin_A, col_A, lin_B, col_B, lin_C, col_C;

//coletando num de linhas e colunas
printf("Linhas de A: ");
scanf("%d", &lin_A);
lin_C = lin_A;

printf("Colunas de A: ");
scanf("%d", &col_A);
lin_B = col_A;

printf("Colunas de B: ");
scanf("%d", &col_B);
col_C = col_B;

//alocando memoria das matrizes
a = malloc(lin_A*sizeof(int*));
a[0] = malloc(lin_A*col_A*sizeof(int));
for (int i = 1; i < lin_A; i++){
    a[i] = a[i-1]+col_A;
}

b = malloc(lin_B*sizeof(int*));
b[0] = malloc(lin_B*col_B*sizeof(int));
for (int i = 1; i < lin_B; i++){
    b[i] = b[i-1]+col_B;
}

c = malloc(lin_C*sizeof(int*));
c[0] = malloc(lin_C*col_C*sizeof(int));
for (int i = 1; i < lin_C; i++){
    c[i] = c[i-1]+col_C;
}

//preenchendo as matrizes com valores aleatorios
for (int i = 0; i < lin_A; i++)
{
    for (int j = 0; j < col_A; j++)
    {
        a[i][j] = rand()%5;
    }
    
}

for (int i = 0; i < lin_B; i++)
{
    for (int j = 0; j < col_B; j++)
    {
        b[i][j] = rand()%5;
    }
    
}

//chamando a função de multiplicacao
multmatriz(a, b, c, lin_A, col_A, col_B);

//imprimindo o conteudo das matrizes
printf("\n\nMatriz A");
for (int i = 0; i < lin_A; i++)
{
    printf("\n");
    for (int j = 0; j < col_A; j++)
    {
        printf("%d | ", a[i][j]);
    }
    
}

printf("\n\nMatriz B");
for (int i = 0; i < lin_B; i++)
{
    printf("\n");
    for (int j = 0; j < col_B; j++)
    {
        printf("%d | ", b[i][j]);
    }
    
}

printf("\n\nMatriz C");
for (int i = 0; i < lin_C; i++)
{
    printf("\n");
    for (int j = 0; j < col_C; j++)
    {
        printf("%d | ", c[i][j]);
    }
    
}

}