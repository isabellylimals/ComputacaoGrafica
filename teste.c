#include <stdio.h>
#include <math.h>

#define LARGURA 3000
#define ALTURA 3000
#define PI 3.14159265

void multiplicarMatrizVetor(float matriz[3][3], float vetor[3], float resultado[3]) {
    for (int i = 0; i < 3; i++) {
        resultado[i] = 0;
        for (int j = 0; j < 3; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
}

void desenhar_ponto(unsigned char imagem[ALTURA][LARGURA][3], int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA) {
        imagem[ALTURA - 1 - y][x][0] = r;  // Red
        imagem[ALTURA - 1 - y][x][1] = g;  // Green
        imagem[ALTURA - 1 - y][x][2] = b;  // Blue
    }
}

int main() {
    float ponto[3] = {1, 0, 1};  // ponto homogêneo

    // Matriz de rotação de 90 graus no sentido anti-horário
    float rotacao[3][3] = {
        {0, -1, 0},
        {1,  0, 0},
        {0,  0, 1}
    };

    // Matriz de translação: +2 no eixo X
    float translacao[3][3] = {
        {1, 0, 2},
        {0, 1, 0},
        {0, 0, 1}
    };

    float temp[3];
    float resultadoA[3];  // Rotação depois translação
    float resultadoB[3];  // Translação depois rotação

    // Caso A: rotaciona depois translada
    multiplicarMatrizVetor(rotacao, ponto, temp);           // temp = R * ponto
    multiplicarMatrizVetor(translacao, temp, resultadoA);   // resultadoA = T * temp

    // Caso B: translada depois rotaciona
    multiplicarMatrizVetor(translacao, ponto, temp);        // temp = T * ponto
    multiplicarMatrizVetor(rotacao, temp, resultadoB);      // resultadoB = R * temp

    // Inicializar imagem com fundo branco
    unsigned char imagem[ALTURA][LARGURA][3];
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            imagem[y][x][0] = 255;
            imagem[y][x][1] = 255;
            imagem[y][x][2] = 255;
        }
    }

    // Escala para melhor visualização
    int escala = 100;

    // Desenhar pontos
    desenhar_ponto(imagem, ponto[0] * escala + 500, ponto[1] * escala + 500, 0, 0, 255);             // Azul: original
    desenhar_ponto(imagem, resultadoA[0] * escala + 500, resultadoA[1] * escala + 500, 255, 0, 0);   // Vermelho: Caso A
    desenhar_ponto(imagem, resultadoB[0] * escala + 500, resultadoB[1] * escala + 500, 0, 255, 0);   // Verde: Caso B

    // Salvar como PPM
    FILE *fp = fopen("transformacoes.ppm", "wb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return 1;
    }
    fprintf(fp, "P6\n%d %d\n255\n", LARGURA, ALTURA);
    fwrite(imagem, 1, LARGURA * ALTURA * 3, fp);
    fclose(fp);

    printf("Imagem salva como 'transformacoes.ppm'\n");

    return 0;
}
