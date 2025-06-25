#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALTURA 256
#define LARGURA 256

unsigned char img[ALTURA][LARGURA][3];

typedef struct {
    float x, y;
} Ponto;

Ponto reflexaoX(Ponto p) {
    p.y = -p.y;
    return p;
}

Ponto reflexaoY(Ponto p) {
    p.x = -p.x;
    return p;
}

Ponto reflexaoXY(Ponto p) {
    p.x = -p.x;
    p.y = -p.y;
    return p;
}

Ponto translada(Ponto p, float dx, float dy) {
    p.x += dx;
    p.y += dy;
    return p;
}

void marcarPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int y_invertido = ALTURA - 1 - y;
    if (x >= 0 && x < LARGURA && y_invertido >= 0 && y_invertido < ALTURA) {
        img[y_invertido][x][0] = r;
        img[y_invertido][x][1] = g;
        img[y_invertido][x][2] = b;
    }
}

void desenhaLinha(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    int delta_x = abs(x2 - x1);
    int delta_y = abs(y2 - y1);
    int passo_x = (x1 < x2) ? 1 : -1;
    int passo_y = (y1 < y2) ? 1 : -1;
    int erro = delta_x - delta_y;

    while (1) {
        marcarPixel(x1, y1, r, g, b);
        if (x1 == x2 && y1 == y2) break;
        int erro2 = 2 * erro;
        if (erro2 > -delta_y) {
            erro -= delta_y;
            x1 += passo_x;
        }
        if (erro2 < delta_x) {
            erro += delta_x;
            y1 += passo_y;
        }
    }
}

void desenhaRetangulo(Ponto p1, Ponto p2, unsigned char r, unsigned char g, unsigned char b) {
    desenhaLinha(p1.x, p1.y, p2.x, p1.y, r, g, b);
    desenhaLinha(p2.x, p1.y, p2.x, p2.y, r, g, b);
    desenhaLinha(p2.x, p2.y, p1.x, p2.y, r, g, b);
    desenhaLinha(p1.x, p2.y, p1.x, p1.y, r, g, b);
}

void desenhaTriangulo(Ponto a, Ponto b, Ponto c, unsigned char r, unsigned char g, unsigned char b_col) {
    desenhaLinha(a.x, a.y, b.x, b.y, r, g, b_col);
    desenhaLinha(b.x, b.y, c.x, c.y, r, g, b_col);
    desenhaLinha(c.x, c.y, a.x, a.y, r, g, b_col);
}

void desenhaCasaRefletida(Ponto base1, Ponto base2, Ponto topo, float centroX, float centroY, unsigned char r, unsigned char g, unsigned char b) {
  
    Ponto b1 = translada(base1, centroX, centroY);
    Ponto b2 = translada(base2, centroX, centroY);
    Ponto t  = translada(topo, centroX, centroY);
    desenhaRetangulo(b1, b2, r, g, b);
    desenhaTriangulo((Ponto){b1.x, b2.y}, t, (Ponto){b2.x, b2.y}, r, g, b);

   
    Ponto porta1 = {b1.x + (b2.x - b1.x) / 3, b1.y};
    Ponto porta2 = {b1.x + 2 * (b2.x - b1.x) / 3, b1.y + (b2.y - b1.y) / 2};
    desenhaRetangulo(porta1, porta2, 139, 69, 40); 

    b1 = translada(reflexaoX(base1), centroX, centroY);
    b2 = translada(reflexaoX(base2), centroX, centroY);
    t  = translada(reflexaoX(topo), centroX, centroY);
    desenhaRetangulo(b1, b2, r, g, b);
    desenhaTriangulo((Ponto){b1.x, b2.y}, t, (Ponto){b2.x, b2.y}, r, g, b);


    porta1 = (Ponto){b1.x + (b2.x - b1.x) / 3, b1.y};
    porta2 = (Ponto){b1.x + 2 * (b2.x - b1.x) / 3, b1.y + (b2.y - b1.y) / 2};
    desenhaRetangulo(porta1, porta2, 139, 69, 19);

   
    b1 = translada(reflexaoY(base1), centroX, centroY);
    b2 = translada(reflexaoY(base2), centroX, centroY);
    t  = translada(reflexaoY(topo), centroX, centroY);
    desenhaRetangulo(b1, b2, r, g, b);
    desenhaTriangulo((Ponto){b1.x, b2.y}, t, (Ponto){b2.x, b2.y}, r, g, b);

  
    porta1 = (Ponto){b1.x + (b2.x - b1.x) / 3, b1.y};
    porta2 = (Ponto){b1.x + 2 * (b2.x - b1.x) / 3, b1.y + (b2.y - b1.y) / 2};
    desenhaRetangulo(porta1, porta2, 139, 69, 19);


    b1 = translada(reflexaoXY(base1), centroX, centroY);
    b2 = translada(reflexaoXY(base2), centroX, centroY);
    t  = translada(reflexaoXY(topo), centroX, centroY);
    desenhaRetangulo(b1, b2, r, g, b);
    desenhaTriangulo((Ponto){b1.x, b2.y}, t, (Ponto){b2.x, b2.y}, r, g, b);

  
    porta1 = (Ponto){b1.x + (b2.x - b1.x) / 3, b1.y};
    porta2 = (Ponto){b1.x + 2 * (b2.x - b1.x) / 3, b1.y + (b2.y - b1.y) / 2};
    desenhaRetangulo(porta1, porta2, 139, 69, 19);
}


int main() {
    FILE *fp = fopen("imagemEspelhada.ppm", "w");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            img[y][x][0] = 255;
            img[y][x][1] = 255;
            img[y][x][2] = 255;
        }
    }

    float centroX = LARGURA / 2.0;
    float centroY = ALTURA / 2.0;

 
    Ponto base1 = {10, 10};
    Ponto base2 = {40, 40};
    Ponto topo = {25, 55};

    desenhaCasaRefletida(base1, base2, topo, centroX, centroY, 220, 0, 255);  

    fprintf(fp, "P3\n%d %d\n255\n", LARGURA, ALTURA);
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            fprintf(fp, "%d %d %d ", img[y][x][0], img[y][x][1], img[y][x][2]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
} 