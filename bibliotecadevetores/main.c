#include <stdio.h>
#include "findvetor.h"
int main(){
    int a[2]= {2,4};
    int b[2]= {6,2};
    int res[2];
    findvetor(a,b,res);
    printf("O vetor resultante eh: [%d,%d]\n",res[0],res[1]);
}