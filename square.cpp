#include "include/square.h"
#include "include/util.h"

void Square::Reset() {
    center.x = width + (rand() % SCREEN_W - width);
    center.y = height + (rand() % SCREEN_H - height);
}
Square::Square(int pwidth, int pheight, int pvelX, int pvelY) {
    Reset();
    width = pwidth;
    height = pheight;
    velX = pvelX;
    velY = pvelY;
}
void Square::Draw() {
    al_draw_filled_rectangle(center.x - (width/2), center.y - (height/2), center.x + (width/2), center.y + (height/2), al_map_rgb( 0, 255, 0 ));
}