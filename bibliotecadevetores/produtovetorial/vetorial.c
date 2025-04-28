#include "vetorial.h"
void vetorial2d(int a[], int b[], int *resultado) {
    *resultado = a[1] * 0 + 0 *b[0] +a[0]* b[1]- a[1]*b[0] + 0 *a[0]+ 0* b[1] ;
}
void vetorial3d(int a[], int b[], int *resultado) {
    resultado[0] = a[1] * b[2] - a[2] * b[1];
    resultado[1] = -(a[0] * b[2] - a[2] * b[0]);
    resultado[2] = a[0] * b[1] - a[1] * b[0];
}

// Exercício 1: Produto vetorial no plano 2D
// Vetores: a = <2, -4> e b = <5, 3>
// Fórmula para o produto vetorial em 2D: a1*b2 - a2*b1
// Resultado: 2 * 3 - (-4) * 5 = 6 + 20 = 26

// Exercício 2: Produto vetorial no espaço 3D
// Vetores: a = <1, 7, 5> e b = <2, 4, 5>
// Fórmula para o produto vetorial em 3D:
// a × b = (a2*b3 - a3*b2) * i - (a1*b3 - a3*b1) * j + (a1*b2 - a2*b1) * k
// Componente i: 7 * 5 - 5 * 4 = 35 - 20 = 15
// Componente j: -(1 * 5 - 5 * 2) = -(5 - 10) = 5
// Componente k: 1 * 4 - 7 * 2 = 4 - 14 = -10
// Resultado: <15, 5, -10>
