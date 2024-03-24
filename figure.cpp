#include <iostream>

#include "include/figure.h"
#include "include/util.h"
#include "include/physics.h"
#include "include/screensaver.h"

Figure::~Figure() {
    std::cout << "\nDestructor called " << this;
}

void Figure::Draw() {}
void Figure::Move() {
    centerVel = Physics::CollideBounds(this);
    centerVel = Physics::CollideFigure(this, );

    velX = centerVel.x, velY = centerVel.y; // Unpack centerVel into 2 vel axis
    center.x += centerVel.x;
    center.y += centerVel.y;
}