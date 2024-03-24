#include <iostream>

#include "include/physics.h"
#include "include/figure.h"

Center Physics::CollideBounds(Figure* pfigure) { // Returns desired velocity
    Center pcenter;
    pcenter.x = pfigure->velX;
    pcenter.y = pfigure->velY;
    if (pfigure->center.x > SCREEN_W - pfigure->width/2 || pfigure->center.x < 0 + pfigure->width/2) {
        pcenter.x = -pfigure->velX;
    }
    if (pfigure->center.y > SCREEN_H - pfigure->width/2 || pfigure->center.y < 0 + pfigure->width/2) {
        pcenter.y = -pfigure->velY;
    }
    return pcenter;
}
Center Physics::CollideFigure(Figure* pfigure1, Figure* pfigure2) {
    Center pcenter;
    if (pfigure1->center.x == pfigure2->center.x) {
        std::cout << "collision";
    }
    return pcenter;
}

