#include "stdio.h"
#include "vetorial.h"
int main(){
    int a[2]={2,-4};
    int b[2]={5,3};
    int resultado;
    vetorial2d(a,b,&resultado);
    printf("O produto vetorial eh: %d\n", resultado);
    int a1[3]={1,7,5};
    int b1[3]={2,4,5};
    int resultado1[3];
    vetorial3d(a1,b1,resultado1);
    printf("O produto vetorial eh: [%d, %d, %d]\n", resultado1[0], resultado1[1], resultado1[2]);
    return 0;
}