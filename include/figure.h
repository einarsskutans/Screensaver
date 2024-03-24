#ifndef FIGURE_H
#define FIGURE_H

#include "util.h"

class Figure {
    public:
        virtual void Draw() = 0;
        void Move();
        Center center;
        int velX;
        int velY;
        int width;
        int height;
    private:
        Center centerVel;
};

#endif