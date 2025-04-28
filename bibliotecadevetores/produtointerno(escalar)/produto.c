
#include "produto.h"

void produtoEscalar(int a[], int b[], int *resultado) {
    *resultado = a[0] * b[0] + a[1] * b[1];
}

void produtoInterno(int a[], int b[], int *resultado) {
    *resultado = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// Exercícios: Realize as operações nos vetores abaixo.

// 1. Calcule o produto escalar entre os vetores a = <2, -4> e b = <5, 3>
// Produto escalar: (2 * 5) + (-4 * 3) = 10 - 12 = -2

// 2. Calcule o produto interno entre os vetores a = <1, 7, 5> e b = <2, 4, 5>
// Produto interno: (1 * 2) + (7 * 4) + (5 * 5) = 2 + 28 + 25 = 55


