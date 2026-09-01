#include "biblioteca.h"

int main(){
    clr();
    set_pixel(200, 200, 0, 255, 255);
    // draw_line(0, 0, 200, 200);
    draw_rotatation(200, 200, 0.78);
    save();
    return 0;
}