#include <stdio.h>
#include <math.h>

int vetor[3];

void calcula_norma_vetor(int x, int y, int z){

    vetor[0] = x;
    vetor[1] = y;
    vetor[2] = z;

    printf("Vetor: <%d, %d, %d>\n", x, y, z);

    float norma = sqrt((x*x)+(y*y)+(z*z));

    printf("Norma: %.2f\n\n", norma);
}

void main(){
    calcula_norma_vetor(2, -5, 0);
    calcula_norma_vetor(4, 2, 0);
    calcula_norma_vetor(3, 5, -6);
    calcula_norma_vetor(6, -2, 1);
}