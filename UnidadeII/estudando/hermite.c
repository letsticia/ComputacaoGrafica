#include <stdio.h>

#define width 400
#define height 400

unsigned char image[width][height][3];

typedef struct
{
    float x, y;
} Point;


void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    image[x][y][0] = r;
    image[x][y][1] = g;
    image[x][y][2] = b;

}

void clrImg(){
    for (int i = 0; i < width; i++){
        for (int j = 0; j <height; j++){
            putPixel(i, j, 255, 255, 255);
        }
    }
}

void saveImg(){
    printf("P3\n%d \t%d\n255\n", width, height);
    for (int i = 0; i < width; i++){
        for (int j = 0; j <height; j++){
            for(int c = 0; c < 3; c++){
                printf("%d \t", image[i][j][c]);
            }
            printf("\n");
        }
    }
}


float h1(float t){
    return ( (2 * t * t *t) - (3 * t * t) + 1);
}

float h2(float t){
    return ((-2 * t *t *t) + (3 * t* t));
}

float h3(float t){
    return ((t * t* t) - (2 * t * t) + t);
}

float h4(float t){
    return ((t * t * t) - (t * t)); 
}


Point hermite(float t, Point P1, Point P2, Point T1, Point T2){

    Point result;

    result.x = (h1(t) * P1.x) + (h2(t) * P2.x) + (h3(t) * T1.x) + (h4(t) * T2.x);
    result.y = (h1(t) * P1.y) + (h2(t) * P2.y) + (h3(t) * T1.y) + (h4(t) * T2.y);

    return result;
}

int main(){
    clrImg();
    Point p1 = {100, 100};
    Point p2 = {300, 300};
    Point t1 = {200, 0};
    Point t2 = {0, 200};

    for(float t = 0; t <= 1; t= t + 0.001){
        Point h = hermite(t, p1, p2, t1, t2);
        putPixel(h.x, h.y, 255, 0, 0);
    }

    saveImg();
    return 0;
}