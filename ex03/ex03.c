//Deixar o fundo branco
#include <stdio.h>
#include <stdlib.h>

int main(){
FILE *fp = fopen("imagem.ppm", "w");


int i, j;
int linha = 100;
int coluna = 100;
fprintf(fp, "P3\n%d %d\n255\n", coluna, linha);
for(i = 0; i < linha; i++){
    for(j = 0; j < coluna; j++){
        fprintf(fp, "%d %d %d ", 255, 255, 255);
    }
    fprintf(fp, "\n");
}
for(i = 0; i < linha; i++){
    for(j = 0; j < coluna; j++){
        
        fprintf(fp, "%d %d %d ", 255, 255, 255);
    }
    fprintf(fp, "\n");
}
fclose(fp);
return 0;}