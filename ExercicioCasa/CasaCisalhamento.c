#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
unsigned char img[HEIGHT][WIDTH][3];

typedef struct { float x, y, z; } Ponto3D;
typedef struct { float x, y; } Ponto2D;

Ponto2D projeta(Ponto3D p) {
    Ponto2D p2d;
    p2d.x = p.x - p.z * 0.5;
    p2d.y = p.y - p.z * 0.5;
    return p2d;
}

Ponto3D translada3D(Ponto3D p, float dx, float dy, float dz) {
    p.x += dx; p.y += dy; p.z += dz; return p;
}

void localizar_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int yi = HEIGHT - 1 - y;
    if (x < 0 || x >= WIDTH || yi < 0 || yi >= HEIGHT) return;
    img[yi][x][0] = r;
    img[yi][x][1] = g;
    img[yi][x][2] = b;
}

void desenhaLinha(int xInicial, int yInicial, int xFinal, int yFinal,
                 unsigned char vermelho, unsigned char verde, unsigned char azul) {
    int deltaX = abs(xFinal - xInicial), deltaY = abs(yFinal - yInicial);
    int passoX = (xInicial < xFinal ? 1 : -1), passoY = (yInicial < yFinal ? 1 : -1);
    int erro = deltaX - deltaY;

    while (1) {
        localizar_pixel(xInicial, yInicial, vermelho, verde, azul);
        if (xInicial == xFinal && yInicial == yFinal) break;
        int erro2 = 2 * erro;
        if (erro2 > -deltaY) { erro -= deltaY; xInicial += passoX; }
        if (erro2 < deltaX) { erro += deltaX; yInicial += passoY; }
    }
}

void desenhaCasa3D(Ponto2D centro, unsigned char vermelho, unsigned char verde, unsigned char azul) {
    float larguraBase = 40, alturaBase = 40;
    float alturaTelhado = 30;
    float profundidade = 20;

    Ponto3D base[] = {
        {0, 0, 0}, {larguraBase, 0, 0}, {larguraBase, alturaBase, 0}, {0, alturaBase, 0},
        {0, 0, profundidade}, {larguraBase, 0, profundidade}, {larguraBase, alturaBase, profundidade}, {0, alturaBase, profundidade}
    };
    int arestasBase[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};
    int numArestasBase = sizeof(arestasBase) / sizeof(arestasBase[0]);

    Ponto3D telhado[] = {
        {0, alturaBase, 0}, {larguraBase, alturaBase, 0}, {larguraBase / 2, alturaBase + alturaTelhado, 0},
        {0, alturaBase, profundidade}, {larguraBase, alturaBase, profundidade}, {larguraBase / 2, alturaBase + alturaTelhado, profundidade}
    };
    int arestasTelhado[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}, {0, 3}, {1, 4}, {2, 5}};
    int numArestasTelhado = sizeof(arestasTelhado) / sizeof(arestasTelhado[0]);
    Ponto3D topoTelhado[] = {{larguraBase / 2, alturaBase + alturaTelhado, 0}, {larguraBase / 2, alturaBase + alturaTelhado, profundidade}};

    Ponto3D centroBase = {larguraBase / 2.0f, alturaBase / 2.0f, profundidade / 2.0f};

    for (int i = 0; i < numArestasBase; i++) {
        Ponto2D p1 = projeta(translada3D(base[arestasBase[i][0]], -centroBase.x, -centroBase.y, -centroBase.z));
        Ponto2D p2 = projeta(translada3D(base[arestasBase[i][1]], -centroBase.x, -centroBase.y, -centroBase.z));
        desenhaLinha(round(p1.x + centro.x), round(p1.y + centro.y),
                     round(p2.x + centro.x), round(p2.y + centro.y),
                     vermelho, verde, azul);
    }

    for (int i = 0; i < numArestasTelhado; i++) {
        Ponto2D p1 = projeta(translada3D(telhado[arestasTelhado[i][0]], -centroBase.x, -centroBase.y, -centroBase.z));
        Ponto2D p2 = projeta(translada3D(telhado[arestasTelhado[i][1]], -centroBase.x, -centroBase.y, -centroBase.z));
        desenhaLinha(round(p1.x + centro.x), round(p1.y + centro.y),
                     round(p2.x + centro.x), round(p2.y + centro.y),
                     vermelho, verde, azul);
    }

    Ponto2D p1_topo = projeta(translada3D(topoTelhado[0], -centroBase.x, -centroBase.y, -centroBase.z));
    Ponto2D p2_topo = projeta(translada3D(topoTelhado[1], -centroBase.x, -centroBase.y, -centroBase.z));
    desenhaLinha(round(p1_topo.x + centro.x), round(p1_topo.y + centro.y),
                 round(p2_topo.x + centro.x), round(p2_topo.y + centro.y),
                 vermelho, verde, azul);
                 float larguraPorta = 12;
float alturaPorta = 20;


Ponto3D porta3D[4] = {
    { (larguraBase - larguraPorta) / 2, 0, 0 },                          
    { (larguraBase + larguraPorta) / 2, 0, 0 },                          
    { (larguraBase + larguraPorta) / 2, alturaPorta, 0 },               
    { (larguraBase - larguraPorta) / 2, alturaPorta, 0 }                
};


for (int i = 0; i < 4; i++) {
    Ponto3D p1_3d = translada3D(porta3D[i], -centroBase.x, -centroBase.y, -centroBase.z);
    Ponto3D p2_3d = translada3D(porta3D[(i+1)%4], -centroBase.x, -centroBase.y, -centroBase.z);
    Ponto2D p1_2d = projeta(p1_3d);
    Ponto2D p2_2d = projeta(p2_3d);
    desenhaLinha(round(p1_2d.x + centro.x), round(p1_2d.y + centro.y),
                 round(p2_2d.x + centro.x), round(p2_2d.y + centro.y),
                 220, 0, 255); 
}
}

int main() {
    FILE *fp = fopen("imagemCisalhamento.ppm", "w");
    if (!fp) { perror("Erro"); return 1; }

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            img[y][x][0] = img[y][x][1] = img[y][x][2] = 0;

    Ponto2D centroCasa = { WIDTH / 2.0f, HEIGHT / 2.0f };

    desenhaCasa3D(centroCasa, 220, 0, 255);

    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            fprintf(fp, "%d %d %d ", img[y][x][0], img[y][x][1], img[y][x][2]);
    fclose(fp);
    printf("arquivo ppp deu certo\n");
    return 0;
}
