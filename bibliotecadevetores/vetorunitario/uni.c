// 3. Transforme o vetor v = <12, 3> em vetor unitário
// Norma = sqrt(12^2 + 3^2) = sqrt(144 + 9) = sqrt(153) ≈ 12.369
// Vetor unitário: (12 / 12.369, 3 / 12.369) ≈ (0.9701, 0.2425)

// 4. Transforme o vetor v = <-3, 4, -5> em vetor unitário
// Norma = sqrt((-3)^2 + 4^2 + (-5)^2) = sqrt(9 + 16 + 25) = sqrt(50) ≈ 7.071
// Vetor unitário: (-3 / 7.071, 4 / 7.071, -5 / 7.071) ≈ (-0.4243, 0.5657, -0.7071)
#include "uni.h"
#include <math.h>
void vetorUnitario(int v[], int v1[], float resultado[], float resultado1[]){
    float norma= sqrt(pow(v[0],2)+pow(v[1],2));
    float norma1= sqrt(pow(v1[0],2)+pow(v1[1],2)+pow(v1[2],2));
    resultado[0]= v[0]/norma;
    resultado[1]= v[1]/norma;
    resultado1[0]= v1[0]/norma1;
    resultado1[1]= v1[1]/norma1;
    resultado1[2]= v1[2]/norma1;
}