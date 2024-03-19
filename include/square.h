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
        Square(double pwidth, double pheight, double pvelX, double pvelY);
        void Draw();
};

#endif