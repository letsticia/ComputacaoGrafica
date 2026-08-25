#include <stdio.h>
#include <math.h>

int vetor_normalizado[2];

void normaliza_vetor(int x, int y, int z){

    printf("Vetor: <%d, %d, %d>\n", x, y, z);

    float norma = sqrt((x*x)+(y*y)+(z*z));

    vetor_normalizado[0] = x/norma;
    vetor_normalizado[1] = y/norma;
    vetor_normalizado[2] = z/norma;

    printf("Norma: %.2f\n", norma);

    printf("Vetor normalizado <%d, %d, %d>\n\n", vetor_normalizado[0], vetor_normalizado[1], vetor_normalizado[2]);
}

int main(){
    normaliza_vetor(12, 3, 0);

    normaliza_vetor(-3, 4, -5);
}