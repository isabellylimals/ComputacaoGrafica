/**
 * \file model.h
 *
 * \brief Header com protótipos de funções para manipulação de modelo 3D.
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

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>

 #ifndef MODEL_H
 #define MODEL_H
 
 #define WIDTH 800
 #define HEIGHT 800
 #define MAX_VERTICES 14000
 #define MAX_FACES 14000
 #define MAX_FACE_VERTS 32
 
 typedef struct {
   float x, y, z;
 } Vertex;
 
 typedef struct {
   int verts[MAX_FACE_VERTS];
   int n;
 } Face;
 
 extern unsigned char image[HEIGHT][WIDTH][3];
 
 void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
 
 void clr();
 
 void save();
 
 void draw_line(int x0, int y0, int x1, int y1);
 
 int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);
 
 void resizing( Vertex v0, Vertex v1 );
 
 void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount);

 void draw_points(Vertex *vertices, int vcont);

 void translate(Vertex *vertices, int vcount, float tx, float ty, float tz);
 
 void scale(Vertex *vertices, int vcount, float sx, float sy, float sz);

 void rotation(Vertex *vertices, int vcount, char eixo, float angulo);

 void reflection(Vertex *vertices, int *qtdVertices);

void cisalhamentoShear(Vertex *vertices, int qtdVertices, float cx, float cy, float cz);

 #endif
