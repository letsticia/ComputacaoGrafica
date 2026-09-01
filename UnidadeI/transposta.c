#include <stdio.h>

int matriz2D[2][2];
int vetor2x1[2][1];
int vetor1x3[1][3];



void preenche2D(int a11, int a12, int a21, int a22){
    matriz2D[0][0] = a11;
    matriz2D[0][1] = a12;
    matriz2D[1][0] = a21;
    matriz2D[1][1] = a22;
}


void transposta2D(){
    int transposta[2][2];
    printf("Resultado da transposta da matriz 2x2\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            transposta[i][j] = matriz2D[j][i];
            printf("%d\t", transposta[i][j]);
        }
        printf("\n");
    }
}

void preenche2x1(int a11, int a21){
    vetor2x1[0][0] = a11;
    vetor2x1[1][0] = a21;
}

void transposta2x1(){
    int transposta[1][2];

    transposta[0][0] = vetor2x1[0][0];
    transposta[0][1] = vetor2x1[1][0];

    printf("Resultado 2x1 -> 1x2 \n");
    for(int i = 0; i < 2; i++){
        printf("%d \t", transposta[0][i]);
    }
    printf("\n");
}

void preenche1x3(int a11, int a12, int a13){

    vetor1x3[0][0] = a11;
    vetor1x3[0][1] = a12;
    vetor1x3[0][2] = a13;
}

void transposta1x3(){
    int transposta[3][1];

    transposta[0][0] = vetor1x3[0][0];
    transposta[1][0] = vetor1x3[0][1];
    transposta[2][0] = vetor1x3[0][2];
    printf("Resultado 1x3 -> 3x1 \n");
    for(int i = 0; i < 3; i++){
        printf("%d \n", transposta[i][0]);
    }
}

void produto_interno1x3(int a11, int a12, int a13){
    int vetorb1x3[1][3];

    vetorb1x3[0][0] = a11;
    vetorb1x3[0][1] = a12;
    vetorb1x3[0][2] = a13;

    int transposta[3][1];

    transposta[0][0] = vetor1x3[0][0];
    transposta[1][0] = vetor1x3[0][1];
    transposta[2][0] = vetor1x3[0][2];
    
    int produto_interno = (transposta[0][0] * vetorb1x3[0][0]) + (transposta[1][0] * vetorb1x3[0][1]) + (transposta[2][0] * vetorb1x3[0][2]);
    printf("Produto interno: %d \n", produto_interno);


}


int main(){
    preenche2D(3, 5, 6, 7);
    transposta2D();

    preenche2x1(7, -2);
    transposta2x1();

    preenche1x3(3, -1, 1);
    transposta1x3();

    preenche1x3(3, -2, 1);
    produto_interno1x3(5, 2, 6);
    return 0;
}
