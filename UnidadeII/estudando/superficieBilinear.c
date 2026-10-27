#include <stdio.h>

# define width 400
# define height 400

unsigned char image[width][height][3];

typedef struct{
    float x, y, z;
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
    result.z = (1-t) * a.z + (t * b.z);
    return result;
}

Point projecao(float d, Point a){
    Point result;

    result.x = (a.x * d)/ (d + a.z);
    result.y = (a.y * d)/ (d + a.z);
    result.z = 0;

    return result;
}

int main(){
    clearImage();
    Point a = {100, 100, 100};
    Point b = {100, 0, 100};
    Point c = {100, 100, 0};
    Point d = {0, 100, 100};
    float distancia = 150.0;

    for(float u = 0; u <= 1; u = u + 0.001){
        for(float v = 0; v <= 1; v = v + 0.001){
            Point e = interpolacao(v, a, d);
            Point f = interpolacao(v, b, c);
            Point r = interpolacao(u, e, f);
            Point result = projecao(distancia, r);
            putPixel(result.x + 150, result.y+150, 255, 0, 0);
        }
    }

    saveImage();
    return 0;
}