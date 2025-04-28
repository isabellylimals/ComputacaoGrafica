#include "des.h"
void deslocamento(int a[], int v[], int resultado1[], int resultado2[], int a2[], int v2[]){
    resultado1[0]= a[0]+v[0], 
    resultado1[1]= a[1]+v[1];
    resultado2[0]= a2[0]+v2[0];
    resultado2[1]= a2[1]+v2[1];
    resultado2[2]= a2[2]+v2[2];}
// Exercícios: Realize o deslocamento dos pontos usando os vetores.

// 1. a = (2, -5) e v = <2, 4>
// Resultado: (2 + 2, -5 + 4) = (4, -1)

// 2. a = (3, 5, -6) e v = <-3, 2, -3>
// Resultado: (3 + (-3), 5 + 2, -6 + (-3)) = (0, 7, -9)
