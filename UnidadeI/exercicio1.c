#include <stdio.h>

#define w 100
#define h 100

unsigned char image[w][h][3];

void px(int x, int y, unsigned char r, unsigned char g, unsigned char b){

    if ((x>=0 && x <= w) && (y >= 0 && y <=h)){
        image[x][y][0] = r;
        image[x][y][1] = g;
        image[x][y][2] = b;
    }
}

void paintImg(){
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h ; y++){
            px(x, y, 0, 0, 0);
        }
    }
}

void svImg(){
    printf("P3 \n %d \t %d \n 255 \n", w, h);
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h; y++){
            for (int c = 0; c < 3; c++){
                printf("%d \t", image[x][y][c]);
            }
            printf("\n");
        }
    }
}

int main(){
    paintImg();
    px(50, 50, 255, 0, 0);
    svImg();
    return 0;
}