#include "include/figure.h"
#include "include/util.h"
#include "include/physics.h"

void Figure::Draw() {}
void Figure::Move() {
    centerVel = Physics::CollideBounds(center.x, center.y, velX, velY, width, height);

    velX = centerVel.x, velY = centerVel.y; // Unpack centerVel into 2 vel axis
    center.x += centerVel.x;
    center.y += centerVel.y;
}