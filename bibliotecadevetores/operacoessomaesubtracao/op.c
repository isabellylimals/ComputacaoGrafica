#include "op.h"
void soma(int a[], int v[], int resultado[] ){
    resultado[0]= a[0]+v[0];
    resultado[1]= a[1]+v[1];

}
void subtracao(int a[], int v[], int resultado[]){
    resultado[0]= a[0]-v[0];
    resultado[1]= a[1]-v[1];
}
void soma2(int a[], int v[], int resultado[] ){
    resultado[0]= a[0]+v[0];
    resultado[1]= a[1]+v[1];
    resultado[2]= a[2]+v[2];
   
}
void subtracao2(int a[], int v[], int resultado[] ){
    resultado[0]= a[0]-v[0];
    resultado[1]= a[1]-v[1];
    resultado[2]= a[2]-v[2];

}
// Exercícios: Realize as operações nos vetores abaixo.

// 1. Soma entre a = <2, -5> e v = <2, 4>
// Resultado: (2 + 2, -5 + 4) = (4, -1)

// 2. Subtração entre a = <3, 2> e v = <1, 7>
// Resultado: (3 - 1, 2 - 7) = (2, -5)

// 3. Soma entre a = <3, 5, -6> e v = <-3, 2, -3>
// Resultado: (3 + (-3), 5 + 2, -6 + (-3)) = (0, 7, -9)

// 4. Subtração entre a = <5, 5, 1> e v = <3, 1, 7>
// Resultado: (5 - 3, 5 - 1, 1 - 7) = (2, 4, -6)

