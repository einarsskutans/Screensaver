#include <iostream>
#include <vector>

#include "include/figure.h"
#include "include/util.h"
#include "include/physics.h"
#include "include/screensaver.h"

Figure::~Figure() {
    std::cout << "\nDestructor called " << this;
}

void Figure::Draw() {}
void Figure::Move(std::vector <Figure*> PFigures) {
    Physics::CollideBounds(this);

    for (int i = 0; i < PFigures.size(); i++) {
        for (Figure* pfigure : PFigures) {
            if (pfigure != PFigures[i]) {
                Physics::CollideFigure(pfigure, PFigures[i]);
            }
        }
    }

    //Physics::CollideFigure(PFigures[2], PFigures[0]);
    //Physics::CollideFigure(PFigures[0], PFigures[2]);

    center.x += velX;
    center.y += velY;
}