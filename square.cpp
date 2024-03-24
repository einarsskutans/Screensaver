#include <iostream>

#include "include/square.h"
#include "include/util.h"

Square::Square(int pWidth, int pHeight, int pVelX, int pVelY, Color pColor) {
    std::cout << "\nConstructor called " << this;
    Reset();
    width = pWidth;
    height = pHeight;
    velX = pVelX;
    velY = pVelY;
    color = pColor;
}
Square::~Square() {
    std::cout << "\nDestructor called " << this;
}
void Square::Reset() {
    center.x = 100 + rand()%200;
    center.y = 100 + rand()%200;
}
void Square::Draw() {
    al_draw_filled_rectangle(center.x - (width/2), center.y - (height/2), center.x + (width/2), center.y + (height/2), al_map_rgb(color.r, color.g, color.b));
}