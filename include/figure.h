#ifndef FIGURE_H
#define FIGURE_H

#include "util.h"

class Figure {
    public:
        virtual void Draw() = 0;
        void Move();
        Center center;
        double velX;
        double velY;
        double width;
        double height;
    private:
        Center centerVel;
};

#endif