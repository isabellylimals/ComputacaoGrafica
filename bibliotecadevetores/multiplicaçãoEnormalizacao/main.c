#include "multi.h"
#include <stdio.h>
int main(){
    int v1[2]= {2,4};
    int v2[3]={1,7,5};
    int escalar1= 3;
    int escalar2= -5;
    int resultado[2];
    int resultado1[3];
    multiPorEscalar(v1, v2, escalar1, escalar2, resultado, resultado1);
    printf("O vetor resultante eh: [%d, %d]\n", resultado[0], resultado[1]);
    printf("O vetor resultante eh: [%d, %d, %d]\n", resultado1[0], resultado1[1], resultado1[2]);
    int n[2]= {12,3};
    int n1[3]= {-3,4,-5};
    float resultado2[2];
    float resultado3[3];
    normalizacao(n, n1, resultado2, resultado3);
    printf("O vetor normalizado eh: [%.2f, %.2f]\n", resultado2[0], resultado2[1]);
    printf("O vetor normalizado eh: [%.2f, %.2f, %.2f]\n", resultado3[0], resultado3[1], resultado3[2]);
    return 0;

}