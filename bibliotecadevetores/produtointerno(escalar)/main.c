#include "produto.h"
#include <stdio.h>
int main(){
    int a[2]= {2,-4};
    int b[2]= {5,3};
    int resultado;
    produtoEscalar(a,b,&resultado);
    printf("O produto escalar eh: %d\n", resultado);
    int a1[3]= {1,7,5};
    int b1[3]= {2,4,5};
    int resultado1;;
    produtoInterno(a1,b1,&resultado1);
    printf("O produto interno eh: %d\n", resultado1);
    return 0;
}