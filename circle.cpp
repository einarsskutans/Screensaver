#include <iostream>

#include "include/circle.h"
#include "include/util.h"

Circle::Circle(double pRadius, double pVelX, double pVelY, Color pColor) {
    std::cout << "\nConstructor called " << this;
    Reset();
    width = pRadius;
    velX = pVelX;
    velY = pVelY;
    color = pColor;
}
Circle::~Circle() {
    std::cout << "\nDestructor called " << this;
}
void Circle::Reset() {
    center.x = 100 + rand()%200;
    center.y = 100 + rand()%200;
}
void Circle::Draw() {
    al_draw_filled_circle(center.x, center.y, width/2, al_map_rgb(color.r, color.g, color.b));
}