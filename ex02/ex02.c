//OBS: APROVEITEI COLOQUEI DOIS EXERCICIOS
//Implemente uma função que altera o valor de um pixel da imagem.

//Codifique uma função que salva a imagem no formato PPM
#include <stdio.h>  
#include <stdlib.h>  
#define LARGURA 100
#define ALTURA 100   

typedef struct {
    int red, green, blue;
} Pixel;


Pixel imagem[ALTURA][LARGURA];  

void alterar_pixel(int x, int y, int r, int g, int b) {
    if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA) {
        imagem[y][x].red = r;
        imagem[y][x].green = g;
        imagem[y][x].blue = b;
    }
}

void salvar_imagem(const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        perror("Erro");
        return;
    }

    fprintf(fp, "P3\n%d %d\n255\n", LARGURA, ALTURA);
  int y,x;
    for (y = 0; y < ALTURA; y++) {
        for (x = 0; x < LARGURA; x++) {
            fprintf(fp, "%d %d %d ", imagem[y][x].red, imagem[y][x].green, imagem[y][x].blue);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
   
}
int main() {
    int y,x;
    for ( y = 0; y < ALTURA; y++) {
        for ( x = 0; x < LARGURA; x++) {
            imagem[y][x].red = 0;
            imagem[y][x].green = 0;
            imagem[y][x].blue = 0;
        }
    }

    alterar_pixel(LARGURA / 2, ALTURA / 2, 128, 0, 128); 
 salvar_imagem("imagem.ppm");
    return 0;
}
