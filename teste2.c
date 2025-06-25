#include <stdio.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define WHITE 255
#define BLACK 0
#define M_PI 3.14159265
typedef struct {
    float x, y;
} Point;

typedef float Matrix[3][3];

// Função para multiplicar matriz 3x3 por ponto homogêneo
Point transform(Point p, Matrix m) {
    Point r;
    float x = p.x, y = p.y;
    r.x = m[0][0]*x + m[0][1]*y + m[0][2];
    r.y = m[1][0]*x + m[1][1]*y + m[1][2];
    return r;
}

// Inicializa uma matriz identidade
void identity(Matrix m) {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            m[i][j] = (i == j) ? 1 : 0;
}

// Cria matriz de translação
void translation(Matrix m, float tx, float ty) {
    identity(m);
    m[0][2] = tx;
    m[1][2] = ty;
}

// Cria matriz de rotação
void rotation(Matrix m, float angle) {
    identity(m);
    float rad = angle * M_PI / 180;
    m[0][0] = cos(rad); m[0][1] = -sin(rad);
    m[1][0] = sin(rad); m[1][1] = cos(rad);
}

// Cria matriz de escala
void scale(Matrix m, float sx, float sy) {
    identity(m);
    m[0][0] = sx;
    m[1][1] = sy;
}

// Cria matriz de cisalhamento
void shear(Matrix m, float shx, float shy, float shz) {
    identity(m);
    m[0][1] = shx;
    m[1][0] = shy;
    m[2][2] = 1;
}

// Cria matriz de espelhamento no eixo Y
void mirrorY(Matrix m) {
    identity(m);
    m[0][0] = -1;
}

// Desenha ponto no buffer da imagem
void plot(unsigned char image[HEIGHT][WIDTH][3], int x, int y, int r, int g, int b) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        image[y][x][0] = r;
        image[y][x][1] = g;
        image[y][x][2] = b;
    }
}

// Gera imagem PPM
void save_ppm(unsigned char image[HEIGHT][WIDTH][3], const char* filename) {
    FILE* f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);
    fclose(f);
}

int main() {
    unsigned char image[HEIGHT][WIDTH][3];
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            for (int c = 0; c < 3; c++)
                image[y][x][c] = WHITE;

    // Quadrado original (centro 250,250)
    Point square[5] = {
        {200, 200}, {300, 200}, {300, 300}, {200, 300}, {200, 200}
    };

    // Desenha quadrado original (preto)
    for (int i = 0; i < 4; i++) {
        Point a = square[i];
        Point b = square[i + 1];
        for (float t = 0; t < 1; t += 0.001) {
            int x = (int)(a.x * (1 - t) + b.x * t);
            int y = (int)(a.y * (1 - t) + b.y * t);
            plot(image, x, y, BLACK, 0, 0);
        }
    }

    // Matriz de transformação: rotação + translação
    Matrix rot, trans, final;
    rotation(rot, 45);          // gira 45 graus
    translation(trans, 100, 0); // depois desloca
    // Combina as duas multiplicando: final = trans * rot
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            final[i][j] = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                final[i][j] += trans[i][k] * rot[k][j];

    // Transforma e desenha novo quadrado (vermelho)
    for (int i = 0; i < 4; i++) {
        Point a = transform(square[i], final);
        Point b = transform(square[i + 1], final);
        for (float t = 0; t < 1; t += 0.001) {
            int x = (int)(a.x * (1 - t) + b.x * t);
            int y = (int)(a.y * (1 - t) + b.y * t);
            plot(image, x, y, 255, 0, 0); // vermelho
        }
    }

    save_ppm(image, "transform.ppm");
    printf("Imagem gerada: transform.ppm\n");

    return 0;
}
