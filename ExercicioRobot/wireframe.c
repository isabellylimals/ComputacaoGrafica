/**
 * \file wireframe.c
 *
 * \brief Implementação do arquivo principal de renderização do modelo 3D.
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

 int main() {
     Vertex vertices[MAX_VERTICES];
     Face faces[MAX_FACES];
     int vcount, fcount;
    printf("teste\n");
     clr();
 
     
     if (!load_obj("robot.obj", vertices, &vcount, faces, &fcount)) {
         return 1;
     }
    // printf("teste1\n");
     cisalhamentoShear(vertices, vcount, 0.01, 1, 1);
   //  printf("teste1\n");
     scale(vertices, vcount, 0.3, 0.3, 0.3);
    // printf("teste1\n");
     translate(vertices, vcount, 0.2, 0, 0);
     //printf("teste1\n");
     scale(vertices, vcount, 0.5, 0.5, 0.5);
    // printf("teste1\n");
     translate(vertices, vcount, 0.56, 0.56, 0);
    // printf("teste1\n");
     reflection(vertices, &vcount);
    // printf("teste1\n");
     translate(vertices, vcount, 1, 0, 0);
     // printf("teste2\n");
     
    rotation(vertices, vcount, 'y', 45);
  printf("teste2.1\n");
     render_faces(vertices, faces, vcount, fcount);
     printf("teste2.1\n");
     draw_points(vertices, vcount);
    // printf("teste3\n");
     save();
    // printf("teste4\n");
     return 0;
 }
 