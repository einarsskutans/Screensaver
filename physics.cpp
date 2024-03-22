#include "include/physics.h"
#include "include/figure.h"

Center Physics::CollideBounds(double px, double py, double pvelX, double pvelY, double pwidth, double pheight) { // Returns desired velocity
    Center pcenter;
    pcenter.x = pvelX;
    pcenter.y = pvelY;
    if (px > SCREEN_W - pwidth/2 || px < 0 + pwidth/2) {
        pcenter.x = -pvelX;
    }
    if (py > SCREEN_H - pwidth/2 || py < 0 + pwidth/2) {
        pcenter.y = -pvelY;
    }
    return pcenter;
}
