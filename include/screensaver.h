#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "util.h"
#include "figure.h"
#include "circle.h"
#include "square.h"

class Screensaver {
    public:
        void Add(Figure* figure);
        void Next();
        void Draw();
        void fps();
        void draw();
        int Init();

        std::vector <Figure*> PFigures;
        void Print();
};

#endif