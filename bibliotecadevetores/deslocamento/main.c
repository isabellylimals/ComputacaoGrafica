#include <stdio.h>
#include "des.h"

int main() {
    int a[2] = {2, -5};
    int v[2] = {2, 4};
    int a2[3] = {3, 5, -6};

    int v2[3] = {-3, 2, -3};
    int resultado1[2];
    int resultado2[3];


    deslocamento(a, v, resultado1, resultado2, a2, v2);
    printf("O vetor resultante eh: [%d, %d]\n", resultado1[0], resultado1[1]);      
    printf("O vetor resultante eh: [%d, %d, %d]\n", resultado2[0], resultado2[1], resultado2[2]);


    return 0;
}