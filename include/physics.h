#ifndef PHYSICS_H
#define PHYSICS_H

#include "util.h"
#include "physics.h"
#include "figure.h"

struct Physics {
    static Center CollideBounds(Figure* pfigure);
    static Center CollideFigure(Figure* pfigure1, Figure* pfigure2);
};

#endif