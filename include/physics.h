#ifndef PHYSICS_H
#define PHYSICS_H

#include "util.h"
#include "physics.h"
#include "figure.h"

struct Physics {
    static void CollideBounds(Figure* pfigure);
    static void CollideFigure(Figure* pfigure1, Figure* pfigure2);
};

#endif