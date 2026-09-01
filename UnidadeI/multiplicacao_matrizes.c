#include <stdio.h>

int matrizA2D[2][2];
int matrizB2D[2][2];
int matrizR2[2][2];

int matrizA3D[3][3];
int matrizB3D[3][3];
int matrizR3[3][3];


void preenche_matrizA2D(int a11, int a12, int a21, int a22){
    matrizA2D[0][0] = a11;
    matrizA2D[0][1] = a12;
    matrizA2D[1][0] = a21;
    matrizA2D[1][1] = a22;
}

void preenche_matrizB2D(int a11, int a12, int a21, int a22){
    matrizB2D[0][0] = a11;
    matrizB2D[0][1] = a12;
    matrizB2D[1][0] = a21;
    matrizB2D[1][1] = a22;
}


void multiplica_2D(){
    printf("Resultado da multiplicacao das matrizes 2D:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrizR2[i][j] = matrizA2D[i][j] * matrizB2D[i][j];
            printf("%d\t", matrizA2D[i][j]);
        }
        printf("\n");
    }
}


void preenche_matrizA2D(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33){
    matrizA2D[0][0] = a11;
    matrizA2D[0][1] = a12;
    matrizA2D[1][0] = a21;
    matrizA2D[1][1] = a22;
}

void preenche_matrizB2D(int a11, int a12, int a21, int a22){
    matrizB2D[0][0] = a11;
    matrizB2D[0][1] = a12;
    matrizB2D[1][0] = a21;
    matrizB2D[1][1] = a22;
}
