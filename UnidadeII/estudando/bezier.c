#include <stdio.h>

# define width 400
# define height 400

unsigned char image[width][height][3];

typedef struct{
    float x, y;
} Point;

void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    image[x][y][0] = r;
    image[x][y][1] = g;
    image[x][y][2] = b;
}

void clearImage(){
    for(int i = 0; i < width; i ++){
        for(int j = 0; j < height; j++){
            putPixel(i, j, 255, 255, 255);
        }
    }
}

void saveImage(){
    printf("P3\n%d\t%d\n255\n", width, height);

    for(int i=0; i < width; i++){
        for(int j=0;j <height; j++){
            for(int c=0; c<3; c++){
                printf("%d\t", image[i][j][c]);
            }
            printf("\n");
        }
    }
}

Point interpolacao(float t, Point a, Point b){
    Point result;
    result.x = (1-t) * a.x + (t * b.x);
    result.y = (1-t) * a.y + (t * b.y);
    return result;
}

Point Bezier(float t, Point p1, Point p2, Point p3){
    Point result, r1, r2;

    r1 = interpolacao(t, p1, p2);
    r2 = interpolacao(t, p2, p3);
    result = interpolacao(t, r1, r2);

    return result;
}

int main(){
    clearImage();

    Point a = {200,200};
    Point b = {300,150};
    Point c = {300,200};


    for (float t = 0; t <= 1; t = t + 0.001){
        Point bez = Bezier(t, a, b, c);
        putPixel(bez.x, bez.y, 255, 0, 0);
    }

    saveImage();
    return 0;
}