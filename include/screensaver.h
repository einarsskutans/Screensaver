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
        void Add(Figure* figure, int element);
        void Next();
        void Draw();

        const static int n = 50;
        typedef Figure* PFigure;  
        PFigure PFigures[n] = {};
};

#endif