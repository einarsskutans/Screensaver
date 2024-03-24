#ifndef SQUARE_H
#define SQUARE_H

#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "util.h"
#include "figure.h"

class Square : public Figure {
    private:
        void Reset();
    public:
        Color color;
        Square();
        Square(int pWidth, int pHeight, int pVelX, int pVelY, Color pColor);
        void Draw();
};

#endif