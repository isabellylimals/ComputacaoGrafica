#include "findvetor.h"
#include <math.h>
void findvetor(int a[], int b[], int v[], int a1[], int b1[], int v1[], int a2[], int b2[], int v2[], int a3[], int b3[], int v3[]){
    v[0]= b[0]-a[0];
    v[1]= b[1]-a[1];    
    v[2]= b[2]-a[2];
    v1[0]= b1[0]-a1[0];
    v1[1]= b1[1]-a1[1];    
    v2[0]= b2[0]-a2[0];
    v2[1]= b2[1]-a2[1];    
    v2[2]= b2[2]-a2[2];
    v3[0]= b3[0]-a3[0];
    v3[1]= b3[1]-a3[1];    
    v3[2]= b3[2]-a3[2];
}
// Exercícios: Encontre o vetor a partir dos pontos abaixo:

// 1. a = (2, 4) e b = (6, 2)
// v = (b1 - a1, b2 - a2)
// v = (6 - 2, 2 - 4)
// v = (4, -2)

// 2. a = (6, 7) e b = (-1, -2)
// v = (b1 - a1, b2 - a2)
// v = (-1 - 6, -2 - 7)
// v = (-7, -9)

// 3. a = (2, 2, 4) e b = (1, 1, 1)
// v = (b1 - a1, b2 - a2, b3 - a3)
// v = (1 - 2, 1 - 2, 1 - 4)
// v = (-1, -1, -3)

// 4. a = (-2, 4, -5) e b = (5, 2, -5)
// v = (b1 - a1, b2 - a2, b3 - a3)
// v = (5 - (-2), 2 - 4, -5 - (-5))
// v = (7, -2, 0)
