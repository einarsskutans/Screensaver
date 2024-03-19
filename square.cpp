#include "include/square.h"
#include "include/util.h"

void Square::Reset() {
    center.x = SCREEN_W/2;
    center.y = SCREEN_H/2;
}
Square::Square(double pwidth, double pheight, double pvelX, double pvelY) {
    Reset();
    width = pwidth;
    height = pheight;
    velX = pvelX;
    velY = pvelY;
}
void Square::Draw() {
    al_draw_filled_rectangle(center.x - (width/2), center.y - (height/2), center.x + (width/2), center.y + (height/2), al_map_rgb( 0, 255, 0 ));
}