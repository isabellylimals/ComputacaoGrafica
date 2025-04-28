#include "uni.h"
#include <stdio.h>
int main(){
    int v[2]= {12,3};
    int v1[3]= {-3,4,-5};
    float resultado[2];
    float resultado1[3];
    vetorUnitario(v, v1, resultado, resultado1);
    printf("O vetor unitario eh: [%.2f, %.2f]\n", resultado[0], resultado[1]);
    printf("O vetor unitario eh: [%.2f, %.2f, %.2f]\n", resultado1[0], resultado1[1], resultado1[2]);
    return 0;
}