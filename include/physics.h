#ifndef PHYSICS_H
#define PHYSICS_H

#include "util.h"
#include "square.h"
#include "physics.h"

struct Physics {
    static Center CollideBounds(double px, double py, double pvelX, double pvelY, double pwidth, double pheight);
};

#endif