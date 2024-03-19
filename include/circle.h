#ifndef CIRCLE_H
#define CIRCLE_H

#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "util.h"
#include "figure.h"

class Circle : public Figure {
    private:
        void Reset();
    public:
        Color color;
        Circle();
        Circle(double pRadius, double pVelX, double pVelY, Color pColor);
        void Draw();
};

#endif