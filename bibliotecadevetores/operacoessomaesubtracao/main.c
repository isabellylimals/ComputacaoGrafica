#include "op.h"
#include <stdio.h>
int main(){

    int a[2]= {2,-5};
    int b[2]= {2,4};
    int a1[2]= {3,2};
    int b1[2]= {1,7};
    int a2[3]= {3,5,-6};
    int b2[3]= {-3,2,-3};
    int a3[3]= {5,5,1};
    int b3[3]= {3,1,7};
    int res[2];
    int res1[2];
    int res2[3];
    int res3[3];

soma(a,b,res);
subtracao(a1,b1,res1);
soma2(a2,b2,res2);
subtracao2(a3,b3,res3);

    printf("O vetor resultante eh: [%d,%d]\n",res[0],res[1]);
    printf("O vetor resultante eh: [%d,%d]\n",res1[0],res1[1]);
    printf("O vetor resultante eh: [%d,%d,%d]\n",res2[0],res2[1],res2[2]);
    printf("O vetor resultante eh: [%d,%d,%d]\n",res3[0],res3[1],res3[2]);

    return 0;
}