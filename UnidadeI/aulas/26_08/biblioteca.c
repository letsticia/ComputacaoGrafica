#include <stdio.h>
#include <math.h>
#include "biblioteca.h"

unsigned char image[WIDTH][HEIGHT][3];

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    if ((x >= 0 && x <= WIDTH) && (y>=0 && y <= HEIGHT)){
        image[x][y][0] = r;
        image[x][y][1] = g;
        image[x][y][2] = b;
    }
}

void clr(){
    for(int x = 0; x < WIDTH; x++){
        for(int y=0; y < HEIGHT; y++){
                set_pixel(x, y, 255, 255, 255);
        }
    }
}

void save(){
    printf("P3 \n%d\t%d\n255\n", WIDTH, HEIGHT);

    for(int x = 0; x < WIDTH; x++){
        for(int y=0; y < HEIGHT; y++){
            for(int c =0; c < 3; c++){
                printf("%d\t", image[x][y][c]);
            }
            printf("\n");
        }
    }
}

void draw_line(int x0, int y0, int x1, int y1){
    for (float t =0; t < 1; t = t+ 0.0001){
        int x = x0 + t * (x1 - x0);
        int y = y0 + t * (y1 - y0);
        set_pixel(x, y, 255, 0, 0);
    }
}

void draw_rotatation(int x, int y, float theta){
    int x_r = (x * cos(theta)) - (y * sin(theta));
    int y_r = (y * cos(theta)) + (x * sin(theta));

    set_pixel(x_r, y_r, 255, 0, 0);
}
