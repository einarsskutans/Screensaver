#include <iostream>
#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;

struct Center {
    double x;
    double y;
};

struct Color {
    Color(unsigned char pR = 255, unsigned char pG = 255, unsigned char pB = 255) {
        r = pR;
        g = pG;
        b = pB;
    };
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
struct Physics {
    static Center CollideBounds(double px, double py, double pvelX, double pvelY, double pwidth, double pheight) { // Returns desirable velocity
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
};
class Figure {
    public:
        virtual void Draw() = 0;
        virtual void Move() {
            centerVel = Physics::CollideBounds(center.x, center.y, velX, velY, width, height);

            velX = centerVel.x, velY = centerVel.y; // Unpack centerVel into 2 vel axis
            center.x += centerVel.x;
            center.y += centerVel.y;
        }
    protected:
        Center center;
        double velX;
        double velY;
        double width;
        double height;
    private:
        Center centerVel;
};
class Circle : public Figure {
    private:
        void Reset() {
            center.x = SCREEN_W/2;
            center.y = SCREEN_H/2;
        }
    public:
        Color color;
        Circle(double pRadius, double pVelX, double pVelY, Color pColor) {
            Reset();
            width = pRadius;
            velX = pVelX;
            velY = pVelY;
            color = pColor;
        }
        void Draw() {
            al_draw_filled_circle(center.x, center.y, width, al_map_rgb(color.r, color.g, color.b) );
        }
};
class Square : public Figure {
    private:
        void Reset() {
            center.x = SCREEN_W / 2;
            center.y = SCREEN_H / 2;
        }
    public:
        Square(double pwidth, double pheight, double pvelX, double pvelY) {
            Reset();
            width = pwidth;
            height = pheight;
            velX = pvelX;
            velY = pvelY;
        }
        void Draw() {
            al_draw_filled_rectangle(center.x - (width/2), center.y - (height/2), center.x + (width/2), center.y + (height/2), al_map_rgb( 0, 255, 0 ));
        }
};
class Screensaver {
    public:
        void Add(Figure* f) {
            
        }
        void Next() {
            for (int i = 0; i < 6; i++) {
                PFigures[i]->Move();
            }
        }
        void Draw() {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            for (int i = 0; i < 6; i++) {
                PFigures[i]->Draw();
            }
        }
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
Screensaver screensaver;
void fps() {
    screensaver.Next();
}

void draw() {
    screensaver.Draw();
}

int main(int argc, char **argv) {
    srand(time(0));
    if(!InitAllegro(SCREEN_W, SCREEN_H, FPS)) {
        DestroyAllegro();
        return 1;
    }

    RunAllegro(&fps, &draw);
    DestroyAllegro();
    return 0;
}