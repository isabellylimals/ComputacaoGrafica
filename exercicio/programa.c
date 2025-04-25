#include<stdio.h>
#include<stdlib.h>

#define i 256
#define j 256

unsigned char img[i][j][3];

// Define a cor de um pixel específico
void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < j && y >= 0 && y < i) {
        img[y][x][0] = r;
        img[y][x][1] = g;
        img[y][x][2] = b;
    }
}

void draw_line(FILE *fp, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        setPixel(x1, y1, r, g, b);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    FILE *fp = fopen("imagem.ppm", "w");
    if (!fp) return 1;

    int linha = 256, coluna = 256;
    fprintf(fp, "P3\n%d %d\n255\n", coluna, linha);

    // Fundo branco
    int y, x;
    for (y = 0; y < i; y++) {
        for (x = 0; x < j; x++) {
            img[y][x][0] = 255;
            img[y][x][1] = 255;
            img[y][x][2] = 255;
        }
    }
// Linha horizontal x1 y1 x2 y2
draw_line(fp, 0, 128, 255, 128, 200, 0, 200);// lembrar que aqui ta pintando os pixels pelo amor de God
draw_line(fp, 0, 255, 255, 255, 200, 0, 200); 

//  vertical
draw_line(fp, 0, 128, 0, 255, 200, 0, 255);  
draw_line(fp, 255, 128,255, 255, 200, 0, 255);
//porta linha horizontal
draw_line(fp, 64, 150, 192, 150, 0, 0, 0);
//porta linha vertical
draw_line(fp, 64, 150,64, 255, 0, 0, 0);
draw_line(fp, 192, 150,192, 255, 0, 0, 0);


// Diagonal
draw_line(fp, 0, 128, 128, 0, 0, 0,0);
draw_line(fp, 255, 128, 128, 0, 0, 0, 0);

    for (y = 0; y < i; y++) {
        for (x = 0; x < j; x++) {
            fprintf(fp, "%d %d %d ", img[y][x][0], img[y][x][1], img[y][x][2]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}
