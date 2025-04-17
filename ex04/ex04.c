#include <stdio.h>

int main() {
    FILE *fp = fopen("imagem.ppm", "w");
    int largura = 100, altura = 100;


    fprintf(fp, "P3\n%d %d\n255\n", largura, altura);
    int y, x;

    
    int centroX = largura / 2;
    int centroY = altura / 2;

    for (y = 0; y < altura; y++) {
        for (x = 0; x < largura; x++) {
            if (y == centroY - 10 && x >= centroX - 10 && x <= centroX + 10) {
                fprintf(fp, "128 0 200 ");  //pinta  a linha
            }

            
            else if (x == centroX && y >= centroY - 10 && y <= centroY + 15) {
                fprintf(fp, "128 0 200 ");  
            }

           
            else {
                fprintf(fp, "0 0 0 ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}
