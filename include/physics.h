#ifndef PHYSICS_H
#define PHYSICS_H

#include "util.h"
#include "physics.h"
#include "figure.h"

struct Physics {
    static Center CollideBounds(Figure* pfigure);
};

#endif