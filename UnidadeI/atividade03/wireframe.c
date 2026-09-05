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

#include <stdio.h>
#include "model.h"
Vertex vertices[MAX_VERTICES];
Face faces[MAX_FACES];

int vcount, fcount;
int main() {

    // printf("teste");

    clr();

    // Lê o arquivo OBJ enviado
    if (!load_obj("models/robot.obj", vertices, &vcount, faces, &fcount)) {
        printf("falha");
        return 1;
    }

    // Renderiza as faces no framebuffer
    render_faces(vertices, faces, vcount, fcount);
    //render_faces_rotation(vertices, faces, vcount, fcount, 0.26);
    //render_faces_escala(vertices, faces, vcount, fcount, 1, 2);
    //render_faces_cisalhamento(vertices, faces, vcount, fcount, 1, 1.15);
    render_faces_translacao(vertices, faces, vcount, fcount, 20, 20);

    save();
    
    return 0;
}