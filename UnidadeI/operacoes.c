#include <stdio.h>

int matrizA[2][2];
int matrizB[2][2];
int escalar = -1;

void preenche_matrizA(int a11, int a12, int a21, int a22){
    matrizA[0][0] = a11;
    matrizA[0][1] = a12;
    matrizA[1][0] = a21;
    matrizA[1][1] = a22;
}

void preenche_matrizB(int a11, int a12, int a21, int a22){
    matrizB[0][0] = a11;
    matrizB[0][1] = a12;
    matrizB[1][0] = a21;
    matrizB[1][1] = a22;
}


void multiplica_escalar(){
    printf("Resultado da multiplicacao por escalar -1:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrizA[i][j] = matrizA[i][j] * escalar;
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }
}

void subtracao_matrizes(){
    printf("Resultado da subtracao das matrizes A e B:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrizA[i][j] = matrizA[i][j] - matrizB[i][j];
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }
}

int main(){
    preenche_matrizA(9, -7, -3, 5);
    multiplica_escalar();

    preenche_matrizA(9, -7, -3, 5);
    preenche_matrizB(-7, 3, -5, 8);
    subtracao_matrizes();

    return 0;
}