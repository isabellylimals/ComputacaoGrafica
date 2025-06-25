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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "image.h"
#include "model.h"

static Vertex vec_cross (Vertex a, Vertex b){
return (Vertex) {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

static float vec_dot(Vertex a, Vertex b){
return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static Vertex vec_normalize(Vertex a){
float length = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
return  (Vertex) {a.x / length, a.y / length, a.z / length};
}

static Vertex vec_sub(Vertex a, Vertex b){
 return (Vertex) {a.x - b.x, a.y - b.y, a.z - b.z};
}

void applly_camera(Vertex *vertices, int vcount, Camera cam){
 Vertex n = vec_normalize(vec_sub(cam.target, cam.position));
Vertex u =  vec_normalize (vec_cross(cam.up, n));
Vertex v = vec_cross(n,u);
for (int i = 0; i < vcount; i++){
 Vertex p = {	
		vertices[i].x - cam.position.x,
		vertices[i].y - cam.position.y,
		vertices[i].z - cam.position.z
};
    vertices[i].x = vec_dot(p,u);
    vertices[i].y = vec_dot(p,v);
    vertices[i].z = vec_dot(p, n);

 }

}

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
	     int *fcount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

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

    fclose(file);
    return 1;
}

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount) {
    for (int i = 0; i < fcount; i++) {
        Face face = faces[i];
        for (int j = 0; j < face.n; j++) {
            Vertex v0 = vertices[face.verts[j] - 1];
            Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
	    resizing(v0.x, v0.y, v1.x, v1.y);
        }
    }
}

