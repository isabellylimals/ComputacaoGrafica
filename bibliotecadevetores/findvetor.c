#include "findvetor.h"
#include <math.h>
void findvetor(int a[], int b[], int v[], int a1[], int b1[], int v1[], int a2[], int b2[], int v2[], int a3[], int b3[], int v3[]){
    v[0]= b[0]-a[0];
    v[1]= b[1]-a[1];    
    v[2]= b[2]-a[2];
    v1[0]= b1[0]-a1[0];
    v1[1]= b1[1]-a1[1];    
    v2[0]= b2[0]-a2[0];
    v2[1]= b2[1]-a2[1];    
    v2[2]= b2[2]-a2[2];
    v3[0]= b3[0]-a3[0];
    v3[1]= b3[1]-a3[1];    
    v3[2]= b3[2]-a3[2];
}
