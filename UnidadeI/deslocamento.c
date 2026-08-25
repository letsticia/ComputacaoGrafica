#include <stdio.h>

int ponto[3];
int ponto_resultante[3];

void preenche_ponto(int x, int y, int z){

    printf("Ponto: <%d, %d, %d>\n", x, y, z);
    
    ponto[0] = x;
    ponto[1] = y;
    ponto[2] = z;
}

void vetor_deslocamento(int x, int y, int z){

    printf("Vetor: <%d, %d, %d>\n", x, y, z);

    ponto_resultante[0] = ponto[0] + x;
    ponto_resultante[1] = ponto[1] + y;
    ponto_resultante[2] = ponto[2] + z;

    printf("ponto deslocamento de soma: <%d, %d, %d>\n", ponto_resultante[0], ponto_resultante[1], ponto_resultante[2]);

    ponto_resultante[0] = ponto[0] - x;
    ponto_resultante[1] = ponto[1] - y;
    ponto_resultante[2] = ponto[2] - z;

    printf("ponto deslocamento de subtracao: <%d, %d, %d>\n\n", ponto_resultante[0], ponto_resultante[1], ponto_resultante[2]);

}

int main(){

    preenche_ponto(2, -5, 0);
    vetor_deslocamento(2, 4, 0);

    preenche_ponto(3, 5, -6);
    vetor_deslocamento(-3, 2, -3);

    return 0;
}


