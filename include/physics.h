#ifndef PHYSICS_H
#define PHYSICS_H

#include "util.h"
#include "square.h"
#include "physics.h"

struct Physics {
    static Center CollideBounds(int px, int py, int pvelX, int pvelY, int pwidth, int pheight);
};

#endif