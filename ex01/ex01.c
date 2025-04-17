#include <stdio.h>

int main() {
    FILE *fp = fopen("imagem.ppm", "w");
    

    int largura = 100;
    int altura = 100;
    int centro_x = largura / 2;
    int centro_y = altura / 2;

    
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", largura, altura);
    fprintf(fp, "255\n");
    int y,x;
    for ( y = 0; y < altura; y++) {
        for (x = 0; x < largura; x++) {
            if (x == centro_x && y == centro_y) {
               
                fprintf(fp, "255 0 0 ");
            } else {
                
                fprintf(fp, "0 0 0 ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}
