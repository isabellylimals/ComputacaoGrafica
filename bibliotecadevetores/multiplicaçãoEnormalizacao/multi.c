#include "multi.h"
#include<math.h>
void multiPorEscalar(int v[], int v1[], int escalar1, int escalar2, int resultado[], int resultado1[]){
    resultado[0]= v[0]*escalar1;
    resultado[1]= v[1]*escalar1;
    resultado1[0]= v1[0]*escalar2;
    resultado1[1]= v1[1]*escalar2;
    resultado1[2]= v1[2]*escalar2;
    }
    void normalizacao(int v[], int v1[], float resultado[], float resultado1[]){
        float norma= sqrt(pow(v[0],2)+pow(v[1],2));
        float norma1= sqrt(pow(v1[0],2)+pow(v1[1],2)+pow(v1[2],2));
        resultado[0]= v[0]/norma;
        resultado[1]= v[1]/norma;
        resultado1[0]= v1[0]/norma1;
        resultado1[1]= v1[1]/norma1;
        resultado1[2]= v1[2]/norma1;
    }
// Exercícios: Realize as operações nos vetores abaixo.

// 1. Multiplique o vetor v = <2, 4> pelo escalar 3
// Resultado: (2 * 3, 4 * 3) = (6, 12)

// 2. Multiplique o vetor v = <1, 7, 5> pelo escalar -5
// Resultado: (1 * -5, 7 * -5, 5 * -5) = (-5, -35, -25)

// 3. Normalize o vetor v = <12, 3>
// Norma = sqrt(12^2 + 3^2) = sqrt(144 + 9) = sqrt(153) ≈ 12.369
// Vetor normalizado: (12 / 12.369, 3 / 12.369) ≈ (0.9701, 0.2425)

// 4. Normalize o vetor v = <-3, 4, -5>
// Norma = sqrt((-3)^2 + 4^2 + (-5)^2) = sqrt(9 + 16 + 25) = sqrt(50) ≈ 7.071
// Vetor normalizado: (-3 / 7.071, 4 / 7.071, -5 / 7.071) ≈ (-0.4243, 0.5657, -0.7071)
