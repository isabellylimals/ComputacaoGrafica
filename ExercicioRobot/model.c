/**
 * \file model.c
 *
 * \brief Implementação das funções de manipulação do modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

 #include "model.h"

 unsigned char image[HEIGHT][WIDTH][3];
 
 void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
   if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
     image[y][x][0] = r;
     image[y][x][1] = g;
     image[y][x][2] = b;
   }
 }
 
 void draw_line(int x0, int y0, int x1, int y1) {
   for (float t = 0.0; t < 1.0; t = t + 0.0001)
     set_pixel((int)x0+(x1-x0)*t, (int)y0+(y1-y0)*t, 240, 0, 255);
 }
 
void clr() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int c = 0; c < 3; c++) {
                image[y][x][c] = 0;  
            }
        }
    }
}

 
 void save(){
  FILE *arquivo;
  arquivo = fopen("robosaida.ppm", "w");
   fprintf(arquivo, "P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
 for (int j = 0; j < HEIGHT; j++) {
  for (int i = 0; i < WIDTH; i++) {
    for (int c = 0; c < 3; c++) {
      fprintf(arquivo, "%d\t", image[j][i][c]);
    }
    fprintf(arquivo, "\n");
  }
}
fclose(arquivo);
   }


 
 int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
              int *fcount) {

                printf("load_obj\n");
     FILE *file = fopen(filename, "r");
     if (!file) {
         perror("Erro ao abrir o arquivo");
         return 0;
     }
 printf("load_obj1\n");
     char line[512];
     *vcount = 0;
     *fcount = 0;
 
     while (fgets(line, sizeof(line), file)) {
         if (strncmp(line, "v ", 2) == 0) {
             if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x,
                        &vertices[*vcount].y, &vertices[*vcount].z) == 3) {
                 (*vcount)++;
             }
         } else if (strncmp(line, "f ", 2) == 0) {
             Face face = {.n = 0};
             char *token = strtok(line + 2, " \n");
             while (token && face.n < MAX_FACE_VERTS) {
                 int index;
                 if (sscanf(token, "%d", &index) == 1) {
                     face.verts[face.n++] = index;
                 }
                 token = strtok(NULL, " \n");
             }
             faces[(*fcount)++] = face;
         }
     }
        printf("load_obj2\n");
     fclose(file);
        printf("load_obj3\n");
     return 1;
 }


 
 void resizing( Vertex v0, Vertex v1 ){
   int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f);
   int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
   set_pixel(x0, y0, 0, 0, 0);
   int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
   int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);
   set_pixel(x1, y1, 0, 0, 0);
 
   draw_line(x0, y0, x1, y1);
}


void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount) {
    for (int i = 0; i < fcount; i++) {
        Face face = faces[i];
        for (int j = 0; j < face.n; j++) {
            Vertex v0 = vertices[face.verts[j] - 1];
            Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
            resizing(v0, v1);
        }
    }
}

void draw_points(Vertex *vertices, int vcont){

  for (int i = 0; i < vcont; i++){
    int x = (int)((vertices[i].x + 1.0f) * WIDTH / 2.0f);
    int y = (int)((1.0f - vertices[i].y) * HEIGHT / 2.0f);
    set_pixel(x, y, 0, 0, 0);
   
  }
  
}

void translate(Vertex *vertices, int vcount, float tx, float ty, float tz) {
    for (int i = 0; i < vcount; i++) {
        vertices[i].x += tx;
        vertices[i].y += ty;
        vertices[i].z += tz;
    }
}

void scale(Vertex *vertices, int vcount, float sx, float sy, float sz){
  for (int i = 0; i < vcount; i++) {
    vertices[i].x *= sx;
    vertices[i].y *= sy;
    vertices[i].z *= sz;
}
}

void rotation(Vertex *pontos, int quantidade, char eixo, float angulo){
  float radianos = (angulo * 3.14f) / 180.0f;
  for (int i = 0; i < quantidade; i++) {
    float x = pontos[i].x;
    float y = pontos[i].y;
    float z = pontos[i].z;
    
    if (eixo == 'x') {
      pontos[i].y = y * cosf(radianos) - z * sinf(radianos);
      pontos[i].z = y * sinf(radianos) + z * cosf(radianos);
    } else if (eixo == 'y') {
      pontos[i].x = x * cosf(radianos) + z * sinf(radianos);
      pontos[i].z = -x * sinf(radianos) + z * cosf(radianos);
    } else if (eixo == 'z') {
      pontos[i].x = x * cosf(radianos) - y * sinf(radianos);
      pontos[i].y = x * sinf(radianos) + y * cosf(radianos);
    }
  }
}


void reflection(Vertex *vertices, int *qtdVertices) {
  int qtdOriginal = *qtdVertices;
  for (int i = 0; i < qtdOriginal; i++) {
    vertices[*qtdVertices].y = vertices[i].y - 1;
    vertices[*qtdVertices].x = vertices[i].x - 1;
    vertices[*qtdVertices].z = vertices[i].z;
    (*qtdVertices)++;
  }
  for (int i = 0; i < qtdOriginal; i++) {
    vertices[*qtdVertices].y = vertices[i].y;
    vertices[*qtdVertices].x = vertices[i].x - 1;
    vertices[*qtdVertices].z = vertices[i].z;
    (*qtdVertices)++;
  }
  for (int i = 0; i < qtdOriginal; i++) {
    vertices[*qtdVertices].y = vertices[i].y;
    vertices[*qtdVertices].x = vertices[i].x - 1;
    vertices[*qtdVertices].z = vertices[i].z;
    (*qtdVertices)++;
  }
  for (int i = 0; i < qtdOriginal; i++) {
    vertices[*qtdVertices].y = vertices[i].y - 1;
    vertices[*qtdVertices].x = vertices[i].x;
    vertices[*qtdVertices].z = vertices[i].z;
    (*qtdVertices)++;
  }
}

void cisalhamentoShear(Vertex *vertices, int qtdVertices, float cx, float cy, float cz) {
  for (int i = 0; i < qtdVertices; i++) {
    float x = vertices[i].x;
    float y = vertices[i].y;
    float z = vertices[i].z;
    
    vertices[i].x += cx * y;
    vertices[i].y += cy * x;
    vertices[i].z += cz * x;
  }
}