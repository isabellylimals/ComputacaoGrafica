#include <stdio.h>
#include "findvetor.h"
int main(){
    int a[2]= {2,4};
    int b[2]= {6,2};
    int a1[2]= {6,7};
    int b1[2]={-1,-2};
    int a2[3]={2,2,4};
    int b2[3]={1,1,1};
    int a3[3]={-2,4,-5};
    int b3[3]={5,2,-5};
    int res[2];
    int res1[2];
    int res2[3];
    int res3[3];
    findvetor(a,b,res,a1,b1,res1,a2,b2,res2,a3,b3,res3);
    printf("O vetor resultante eh: [%d,%d]\n",res[0],res[1]);
    printf("O vetor resultante eh: [%d,%d]\n",res1[0],res1[1]);
    printf("O vetor resultante eh: [%d,%d,%d]\n",res2[0],res2[1],res2[2]);
    printf("O vetor resultante eh: [%d,%d,%d]\n",res3[0],res3[1],res3[2]);
    int soma=0;
    int i;
    for(i=0; i<50; i++){
        
        soma= i + soma;
    }
    printf("Resultado da soma: %d\n", soma);
    return 0;

}