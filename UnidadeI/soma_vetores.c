#include <stdio.h>

int vetorA[2];
int vetorB[2];
int vetor_resultante[2];

void preenche_vetorA(int x, int y, int z){
    printf("Vetor: <%d, %d, %d>\n", x, y, z);
    vetorA[0] = x;
    vetorA[1] = y;
    vetorA[2] = z;
}

void preenche_vetorB(int x, int y, int z){
    printf("Vetor: <%d, %d, %d>\n", x, y, z);
    vetorB[0] = x;
    vetorB[1] = y;
    vetorB[2] = z;
}

void soma(){
    vetor_resultante[0] = vetorA[0] + vetorB[0];
    vetor_resultante[1] = vetorA[1] + vetorB[1];
    vetor_resultante[2] = vetorA[2] + vetorB[2];

    printf("vetor soma: <%d, %d, %d>\n\n", vetor_resultante[0], vetor_resultante[1], vetor_resultante[2]);
}

void subtracao(){
    vetor_resultante[0] = vetorA[0] - vetorB[0];
    vetor_resultante[1] = vetorA[1] - vetorB[1];
    vetor_resultante[2] = vetorA[2] - vetorB[2];

    printf("vetor subtracao: <%d, %d, %d>\n\n", vetor_resultante[0], vetor_resultante[1], vetor_resultante[2]);
}

int main(){
    preenche_vetorA(2, -5, 0);
    preenche_vetorB(2, 4, 0);
    soma();

    preenche_vetorA(3, 2, 0);
    preenche_vetorB(1, 7, 0);
    subtracao();

    preenche_vetorA(3, 5, -6);
    preenche_vetorB(-3, 2, -3);
    soma();

    preenche_vetorA(5, 5, 1);
    preenche_vetorB(3, 1, 7);
    subtracao();
    
    return 0;
}