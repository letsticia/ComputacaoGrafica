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

#ifndef MODEL_H
#define MODEL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_VERTICES 50000
#define MAX_FACES 50000
#define MAX_FACE_VERTS 32

typedef struct {
  float x, y, z;
} Vertex;

typedef struct {
  int verts[MAX_FACE_VERTS];
  int n;
} Face;

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr();

void save();

void draw_line(int x0, int y0, int x1, int y1);

void draw_line_rotation(int x0, int y0, int x1, int y1);

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);

void resizing( Vertex v0, Vertex v1 );

void resizing_rotation( Vertex v0, Vertex v1, float thetha);

void resizing_escala( Vertex v0, Vertex v1, int x, int y);

void resizing_cisalhamento( Vertex v0, Vertex v1, float a, float b);

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount);

void render_faces_rotation(Vertex *vertices, Face *faces, int vcount, int fcount, float theta);

void render_faces_escala(Vertex *vertices, Face *faces, int vcount, int fcount, int x, int y);

void render_faces_cisalhamento(Vertex *vertices, Face *faces, int vcount, int fcount, float a, float b);

void draw_rotatation(int x, int y, float theta);

void resizing_translacao( Vertex v0, Vertex v1, int x, int y);

void render_faces_translacao(Vertex *vertices, Face *faces, int vcount, int fcount, int x, int y);



#endif