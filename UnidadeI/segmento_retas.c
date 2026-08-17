#include <stdio.h>

#define w 256
#define h 256


unsigned char image[w][h][3];
// image é uma matriz onde w são as colunas, h são as linhas e 3 é o número de canais (RGB)

void px(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    // função para pintar um pixel da matrix (imagem)


    // checando se as coordenadas estão dentro da imagem
    if ((x >=0 && x <= w) && (y >= 0 && y <= h)){
        image[x][y][0] = r;
        image[x][y][1] = g;
        image[x][y][2] = b;
    }

}

void clrImg(){
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h ; y++){
            px(x, y, 255, 255, 255);
        }
    }
}

void svImg (){
    // escreve o arquivo no formato ppm

    printf("P3 \n %d \t %d \n 255 \n", w, h);
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h; y++){
            for (int c = 0; c <3; c++){
                printf("%d \t", image[x][y][c]);
            }
            printf("\n");
        }
    }
}

void seg(int x1, int y1, int x2, int y2){
    // função para segmento de reta

    for (float t = 0.0; t < 1.0; t += 0.001){
        px((int) (x2 - x1) * t + x1, (int) (y2-y1)*t + y1, 125, 125, 125);
    }

}


int main(){
    clrImg();
    seg(0, 0, 100, 100); 
    svImg();
    return -1;
}

// Compila com: 
// gcc segmento_retas.c -o s
// ./s > output.ppm
