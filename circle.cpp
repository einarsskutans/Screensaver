#include "include/circle.h"
#include "include/util.h"

void Circle::Reset() {
    center.x = SCREEN_W/2;
    center.y = SCREEN_H/2;
}
Circle::Circle(double pRadius, double pVelX, double pVelY, Color pColor) {
    Reset();
    width = pRadius;
    velX = pVelX;
    velY = pVelY;
    color = pColor;
}
void Circle::Draw() {
    al_draw_filled_circle(center.x, center.y, width, al_map_rgb(color.r, color.g, color.b));
}