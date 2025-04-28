#include "norma.h"
#include <math.h>
void norma(int a[], int b[], int c[], int d[], float resultado[]){
    resultado[0]= sqrt(a[0]*a[0]+a[1]*a[1]);
    resultado[1]= sqrt(b[0]*b[0]+b[1]*b[1]);
    resultado[2]= sqrt(c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
    resultado[3]= sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);}
    

    // Exercícios: Encontre a norma dos vetores abaixo:

// 1. a = <2, -5>
// ||a|| = sqrt(2^2 + (-5)^2)
// ||a|| = sqrt(4 + 25)
// ||a|| = sqrt(29)
// ||a|| ≈ 5.385

// 2. b = <4, 2>
// ||b|| = sqrt(4^2 + 2^2)
// ||b|| = sqrt(16 + 4)
// ||b|| = sqrt(20)
// ||b|| ≈ 4.472

// 3. c = <3, 5, -6>
// ||c|| = sqrt(3^2 + 5^2 + (-6)^2)
// ||c|| = sqrt(9 + 25 + 36)
// ||c|| = sqrt(70)
// ||c|| ≈ 8.366

// 4. d = <6, -2, 1>
// ||d|| = sqrt(6^2 + (-2)^2 + 1^2)
// ||d|| = sqrt(36 + 4 + 1)
// ||d|| = sqrt(41)
// ||d|| ≈ 6.403
