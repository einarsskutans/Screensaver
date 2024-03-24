#include "include/physics.h"
#include "include/figure.h"
#include "include/square.h"

Center Physics::CollideBounds(int px, int py, int pvelX, int pvelY, int pwidth, int pheight) { // Returns desired velocity
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
