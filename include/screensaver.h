#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "util.h"
#include "figure.h"
#include "circle.h"
#include "square.h"

class Screensaver {
    public:
        void Next();
        void Draw();
    private:
        Color newColor{0, 0, 255};
        Square square1{50, 50, 5, 5};
        Square square2{50, 50, 10, 5};
        Square square3{50, 50, 10, 20};
        Circle circle1{25, 5, 10, newColor};
        Circle circle2{25, 25, 10, newColor};
        Circle circle3{25, 10, 50, newColor};

        typedef Figure* PFigure;    
        PFigure PFigures[6] = {&square1, &square2, &square3, &circle1, &circle2, &circle3};
};

#endif