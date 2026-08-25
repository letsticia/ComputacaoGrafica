#include <stdio.h>

int vetorA[3];
int vetorB[3];
int vetor_resultante[3];

void preenche_vetorA(int x, int y, int z){
    printf("Vetor A : <%d, %d, %d>\n", x, y, z);
    vetorA[0] = x;
    vetorA[1] = y;
    vetorA[2] = z;
}

void preenche_vetorB(int x, int y, int z){
    printf("Vetor B: <%d, %d, %d>\n", x, y, z);
    vetorB[0] = x;
    vetorB[1] = y;
    vetorB[2] = z;
}

void produto_vetorial(){
    vetor_resultante[0] = (vetorA[1] * vetorB[2]) - (vetorA[2] * vetorB[1]);
    vetor_resultante[1] = (vetorA[2] * vetorB[0]) - (vetorA[0] * vetorB[2]);
    vetor_resultante[2] = (vetorA[0] * vetorB[1]) - (vetorA[1] * vetorB[0]);

    printf("Resultado produto vetorial: <%d, %d, %d>\n\n", vetor_resultante[0], vetor_resultante[1], vetor_resultante[2]);

}

int main(){
    preenche_vetorA(2, -4, 0);
    preenche_vetorB(5, 3, 0);
    produto_vetorial();

    preenche_vetorA(1, 7, 5);
    preenche_vetorB(2, 4, 5);
    produto_vetorial();
}