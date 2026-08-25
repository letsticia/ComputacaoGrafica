#include <stdio.h>

int vetor[2];

void calcula_vetor(int x_a, int y_a, int z_a, int x_b, int y_b, int z_b){
    
    printf("Ponto A: (%d, %d, %d)\n", x_a, y_a, z_a);
    printf("Ponto B: (%d, %d, %d)\n", x_b, y_b, z_b);

    vetor[0] = x_b - x_a;
    vetor[1] = y_b - y_a;
    vetor[2] = z_b - z_a;


    printf("Vetor: <%d, %d, %d>\n\n", vetor[0], vetor[1], vetor[2]);
}

int main(){
    calcula_vetor(2, 4, 0, 6, 2, 0);
    calcula_vetor(6, 7, 0, -1, -2, 0);
    calcula_vetor(2, 2, 4, 1, 1, 1);
    calcula_vetor(-2, 4, -5, 5, 2, -5);

    return 0;
}

