#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define i 256
#define j 256

unsigned char img[i][j][3];

typedef struct {
    float x, y;
} Ponto;

#define PI 3.14159265358979323846

Ponto rotacao(Ponto p, Ponto centro, int angulo) {
    Ponto result;
    float rad = angulo * PI / 180.0;

    // Translada para origem
    float x = p.x - centro.x;
    float y = p.y - centro.y;

    // Aplica a rotação
    float x1 = cos(rad) * x - sin(rad) * y;
    float y1 = sin(rad) * x + cos(rad) * y;

    // Translada de volta
    result.x = x1 + centro.x;
    result.y = y1 + centro.y;

    return result;
}

void localizar_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int y_invertido = 255 - y;  
    if (x >= 0 && x < j && y_invertido >= 0 && y_invertido < i) {
        img[y_invertido][x][0] = r;
        img[y_invertido][x][1] = g;
        img[y_invertido][x][2] = b;
    }
}

void desenhaLinha(int x_inicial, int y_inicial, int x_final, int y_final, unsigned char vermelho, unsigned char verde, unsigned char azul) {
    int delta_x = abs(x_final - x_inicial);
    int delta_y = abs(y_final - y_inicial);
    int passo_x = (x_inicial < x_final) ? 1 : -1;
    int passo_y = (y_inicial < y_final) ? 1 : -1;
    int erro = delta_x - delta_y;
    int erro2;

    while (1) {
        localizar_pixel(x_inicial, y_inicial, vermelho, verde, azul);
        if (x_inicial == x_final && y_inicial == y_final) break;
        erro2 = 2 * erro;
        if (erro2 > -delta_y) {
            erro -= delta_y;
            x_inicial += passo_x;
        }
        if (erro2 < delta_x) {
            erro += delta_x;
            y_inicial += passo_y;
        }
    }
}

void escalaPonto2d(int *x, int *y, float sx, float sy) {
    *x = (int)(*x * sx);
    *y = (int)(*y * sy);
}

void escala_Retangulo(int *x1, int *y1, int *x2, int *y2, float sx, float sy) {
    escalaPonto2d(x1, y1, sx, sy);
    escalaPonto2d(x2, y2, sx, sy);
}

int main() {
    FILE *fp = fopen("imagem.ppm", "w");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(fp, "P3\n%d %d\n255\n", j, i);

    for (int y = 0; y < i; y++) {
        for (int x = 0; x < j; x++) {
            img[y][x][0] = 0;
            img[y][x][1] = 0;
            img[y][x][2] = 0;
        }
    }

    // Coordenadas iniciais
    int base_x1 = 64, base_y1 = 0;
    int base_x2 = 192, base_y2 = 127;

    int porta_x1 = base_x1 + 32;
    int porta_x2 = base_x1 + 96;
    int porta_y1 = 0;
    int porta_y2 = 105;

    int telhado_x1 = base_x1;
    int telhado_y1 = base_y2;
    int telhado_x2 = base_x2;
    int telhado_y2 = base_y2;
    int telhado_x3 = 128;
    int telhado_y3 = 255;

    // Escalando
    float escala = 0.4f;
    escala_Retangulo(&base_x1, &base_y1, &base_x2, &base_y2, escala, escala);
    escala_Retangulo(&porta_x1, &porta_y1, &porta_x2, &porta_y2, escala, escala);
    escalaPonto2d(&telhado_x1, &telhado_y1, escala, escala);
    escalaPonto2d(&telhado_x2, &telhado_y2, escala, escala);
    escalaPonto2d(&telhado_x3, &telhado_y3, escala, escala);

    Ponto centro = {128 * escala, 128 * escala};
    int angulo = 45;

 
    Ponto p1 = rotacao((Ponto){base_x1, base_y1}, centro, angulo);
    Ponto p2 = rotacao((Ponto){base_x2, base_y1}, centro, angulo);
    Ponto p3 = rotacao((Ponto){base_x1, base_y2}, centro, angulo);
    Ponto p4 = rotacao((Ponto){base_x2, base_y2}, centro, angulo);


    Ponto porta1 = rotacao((Ponto){porta_x1, porta_y1}, centro, angulo);
    Ponto porta2 = rotacao((Ponto){porta_x2, porta_y1}, centro, angulo);
    Ponto porta3 = rotacao((Ponto){porta_x1, porta_y2}, centro, angulo);
    Ponto porta4 = rotacao((Ponto){porta_x2, porta_y2}, centro, angulo);

   
    Ponto t1 = rotacao((Ponto){telhado_x1, telhado_y1}, centro, angulo);
    Ponto t2 = rotacao((Ponto){telhado_x2, telhado_y2}, centro, angulo);
    Ponto t3 = rotacao((Ponto){telhado_x3, telhado_y3}, centro, angulo);

    
    desenhaLinha((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, 200, 0, 240);
    desenhaLinha((int)p3.x, (int)p3.y, (int)p4.x, (int)p4.y, 200, 0, 240);
    desenhaLinha((int)p1.x, (int)p1.y, (int)p3.x, (int)p3.y, 200, 0, 240);
    desenhaLinha((int)p2.x, (int)p2.y, (int)p4.x, (int)p4.y, 200, 0, 240);

    desenhaLinha((int)porta1.x, (int)porta1.y, (int)porta2.x, (int)porta2.y, 255, 255, 255);
    desenhaLinha((int)porta3.x, (int)porta3.y, (int)porta4.x, (int)porta4.y, 255, 255, 255);
    desenhaLinha((int)porta1.x, (int)porta1.y, (int)porta3.x, (int)porta3.y, 255, 255, 255);
    desenhaLinha((int)porta2.x, (int)porta2.y, (int)porta4.x, (int)porta4.y, 255, 255, 255);

    desenhaLinha((int)t1.x, (int)t1.y, (int)t3.x, (int)t3.y, 255, 255, 255);
    desenhaLinha((int)t2.x, (int)t2.y, (int)t3.x, (int)t3.y, 255, 255, 255);


    for (int y = 0; y < i; y++) {
        for (int x = 0; x < j; x++) {
            fprintf(fp, "%d %d %d ", img[y][x][0], img[y][x][1], img[y][x][2]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;

    
}
