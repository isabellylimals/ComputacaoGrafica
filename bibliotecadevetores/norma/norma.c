#include "norma.h"
#include <math.h>
void norma(int a[], int b[], int c[], int d[], float resultado[]){
    resultado[0]= sqrt(a[0]*a[0]+a[1]*a[1]);
    resultado[1]= sqrt(b[0]*b[0]+b[1]*b[1]);
    resultado[2]= sqrt(c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
    resultado[3]= sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);}