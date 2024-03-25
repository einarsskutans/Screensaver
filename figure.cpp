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

    for (int j = 0; j < PFigures.size(); j++) {
        for (int i = 0; i < PFigures.size(); i++) {
            Physics::CollideFigure(PFigures[j], PFigures[i]);
        }
    }

    center.x += velX;
    center.y += velY;
}