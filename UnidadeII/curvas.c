#include <stdio.h>
#include <stdlib.h> // para usar o abs (valor do módulo)

#define w 400
#define h 400

typedef struct{
    float x, y;
} Point;


unsigned char img[w][h][3];

void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    if ( (x >= 0) && (x <= w) && (y >= 0) && (y <= h)){
        img[x][y][0] = r;
        img[x][y][1] = g;
        img[x][y][2] = b;
    }
}

void clear(){
    for (int y =0; y < h; y++){
        for (int x=0; x < w; x++){
            putPixel(x, y, 255, 255, 255);
        }
    }
}

void save(){
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

float h1(float t){
    return ((2 * t * t *t) - (3 * t* t) + 1);
}

float h2(float t){
    return ((-2 * t * t *t) + (3 * t* t));
}

float h3(float t){
    return ((t * t *t) - (2 * t* t) + t);
}

float h4(float t){
    return ((t * t *t) - (t* t));
}


Point hermite(float t, Point p1, Point p2, Point t1, Point t2){
    Point result;
    result.x = (h1(t)*p1.x) + (h2(t) * p2.x) + (h3(t) * t1.x) + (h4(t) * t2.x);
    result.y = (h1(t)*p1.y) + (h2(t) * p2.y) + (h3(t) * t1.y) + (h4(t) * t2.y);

    return result;
}


int main(){
    clear();

    Point p1 = {100, 100};
    Point p2 = {400, 200};
    Point t1 = {100, 0};
    Point t2 = {0, 100};

    for (float t = 0.0; t <= 1.0; t = t + 0.001){
        Point herm = hermite(t, p1, p2, t1, t2);
        putPixel(herm.x, herm.y, 255, 0, 0);
    }

    save();

    return 0;
}