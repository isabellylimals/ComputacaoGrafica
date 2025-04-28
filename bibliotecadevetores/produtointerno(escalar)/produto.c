
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

// 3. Transforme o vetor v = <12, 3> em vetor unitário
// Norma = sqrt(12^2 + 3^2) = sqrt(144 + 9) = sqrt(153) ≈ 12.369
// Vetor unitário: (12 / 12.369, 3 / 12.369) ≈ (0.9701, 0.2425)

// 4. Transforme o vetor v = <-3, 4, -5> em vetor unitário
// Norma = sqrt((-3)^2 + 4^2 + (-5)^2) = sqrt(9 + 16 + 25) = sqrt(50) ≈ 7.071
// Vetor unitário: (-3 / 7.071, 4 / 7.071, -5 / 7.071) ≈ (-0.4243, 0.5657, -0.7071)
