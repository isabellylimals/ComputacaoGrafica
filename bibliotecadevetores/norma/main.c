#include <stdio.h>
#include "norma.h"
int main(){

    int a[2]= {2,-5};
    int b[2]= { 4,2};
    int c[3]= {3,5,-6};
    int d[3]={6,-2,1};
    float resultado[4];
    norma(a,b,c,d,resultado);
    printf("Norma do vetor a: %2f\n", resultado[0]);
    printf("Norma do vetor b: %.2f\n", resultado[1]);     
    printf("Norma do vetor c: %.2f\n", resultado[2]);
    printf("Norma do vetor d: %.2f\n", resultado[3]);
    return 0;
}
