#include <stdio.h>
#include <stdlib.h> // para usar o abs (valor do módulo)

#define w 400
#define h 400

unsigned char img[w][h][3];

void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    if ( (x >= 0) && (x <= w) && (y >= 0) && (y <= h)){
        img[x][y][0] = r;
        img[x][y][1] = g;
        img[x][y][2] = b;
    }
}

void clearImg(){
    for (int y =0; y < h; y++){
        for (int x=0; x < w; x++){
            putPixel(x, y, 255, 255, 255);
        }
    }
}

void saveImg(){
    printf("P3\n %d \t %d \n 255 \n", w, h);
    for (int y=0; y < h; y++){
        for (int x=0; x < w; x++){
            for (int c=0; c < 3; c++){
                printf("%d \t", img[x][y][c]);
            }
            printf("\n");
        }
    }
}

void drawDDA( int x0, int y0, int x1, int y1 ){
  // calcula a variacao
  int dx = x1 - x0;
  int dy = y1 - y0;

  // calcula o número de passos de incremento
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  // define o incremento em cada eixo
  float x_inc = (float) dx / steps;
  float y_inc = (float) dy / steps;

  float x = x0;
  float y = y0;

  for (int i = 0; i <= steps; i++){
    putPixel((int)x, (int)y, 255, 0, 0);
    x += x_inc;
    y += y_inc;
  }
}

void bresenham(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;

    int D = 2 * dy - dx;

    int x = x0;
    int y = y0;

    putPixel(x, y, 0, 255, 0);

    while (x <x1){
        x = x + 1;

        if (D < 0){
            D = D + 2 * dy;
        }else{
            y = y + 1;
            D = D + 2 * (dy - dx);
        }
        putPixel(x, y, 0, 255, 0);
    }
}


int main(){
    clearImg();

    // drawDDA(100, 100, 100, 200);

    // drawDDA(100, 100, 200, 100);

    // drawDDA(200, 100, 200, 200);

    // drawDDA(100, 200, 200, 200);

    bresenham(0, 0, 200, 200);



    // drawDDA(100, 200, 100, 200);


    saveImg();

    return 0;
}