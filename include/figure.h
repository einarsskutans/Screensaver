#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "util.h"

class Figure {
    public:
        ~Figure();

        virtual void Draw() = 0;
        void Move(std::vector <Figure*> PFigures);
        Center center;
        int velX;
        int velY;
        int width;
        int height;
    private:
        Center centerVel;
};

#endif