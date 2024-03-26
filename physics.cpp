#include <iostream>

#include "include/physics.h"
#include "include/figure.h"

void Physics::CollideBounds(Figure* pfigure) {
    if (pfigure->center.x > SCREEN_W - pfigure->width/2 || pfigure->center.x < 0 + pfigure->width/2) {
        pfigure->velX = -pfigure->velX;
    }
    if (pfigure->center.y > SCREEN_H - pfigure->width/2 || pfigure->center.y < 0 + pfigure->width/2) {
        pfigure->velY = -pfigure->velY;
    }
}
void Physics::CollideFigure(Figure* pfigure1, Figure* pfigure2) { // This is tragic
    if ( // Some conditionals for collision
        (pfigure1->center.x + pfigure1->width/2 >= pfigure2->center.x - pfigure2->width/2) &&
        (pfigure1->center.x - pfigure1->width/2 <= pfigure2->center.x + pfigure2->width/2) &&
        (pfigure1->center.y + pfigure1->height/2 >= pfigure2->center.y - pfigure2->height/2) &&
        (pfigure1->center.y - pfigure1->height/2 <= pfigure2->center.y + pfigure2->height/2)
    ) {
        pfigure1->velX = -pfigure1->velX;
        pfigure1->velY = -pfigure1->velY;
    }
}
