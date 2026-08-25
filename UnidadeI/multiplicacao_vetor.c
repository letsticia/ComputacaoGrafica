#include <stdio.h>

int vetorA[3];
int vetor_resultante[3];

void preenche_vetorA(int x, int y, int z){
    printf("Vetor: <%d, %d, %d>\n", x, y, z);
    vetorA[0] = x;
    vetorA[1] = y;
    vetorA[2] = z;
}

void multiplica_escalar(int escalar){
    vetor_resultante[0] = vetorA[0] * escalar;
    vetor_resultante[1] = vetorA[1] * escalar;
    vetor_resultante[2] = vetorA[2] * escalar;

    printf("Multiplicacao por escalar %d: <%d, %d, %d>\n\n", escalar, vetor_resultante[0], vetor_resultante[1], vetor_resultante[2]);
}

int main(){
    preenche_vetorA(2, 4, 0);
    multiplica_escalar(3);

    preenche_vetorA(1, 7, 5);
    multiplica_escalar(-5);
}