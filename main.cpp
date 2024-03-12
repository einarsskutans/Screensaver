#include <iostream>
#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;

class Figure {
    public:
        virtual void Draw() = 0;
        virtual void Move() = 0;
};
struct Center {
    double x;
    double y;
};
struct Color {
    Color(unsigned char pR = 255, unsigned char pG = 255, unsigned char pB = 255) { // Default color = white
        r = pR;
        g = pG;
        b = pB;
    };
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Circle : public Figure {
    public:
        Center center;
        Color color;
        Circle(double pRadius, double pVelX, double pVelY, Color pColor) {
            Reset();
            radius = pRadius;
            velX = pVelX;
            velY = pVelY;
            color = pColor;
        }
        void Reset() {
            center.x = SCREEN_W/2;
            center.y = SCREEN_H/2;
        }
        void Draw() {
            al_draw_filled_circle(center.x, center.y, radius, al_map_rgb(color.r, color.g, color.b) );
        }
        void Move() {
            if (center.x > SCREEN_W-radius) {
                velX = -velX;
            }
            if (center.y > SCREEN_H-radius) {
                velY = -velY;
            }
            if (center.x < 0+radius) {
                velX = -velX;
            }
            if (center.y < 0+radius) {
                velY = -velY;
            }
            center.x = center.x + velX;
            center.y = center.y + velY;
        }

    private:
        double velX;
        double velY;
        double radius;
};
class Square : public Figure {
    public:
        Center center;
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
        void Move() {
            if (center.x > SCREEN_W - width/2) {
                velX = -velX;
            }
            if (center.y > SCREEN_H - height/2) {
                velY = -velY;
            }
            if (center.x < 0 + width/2) {
                velX = -velX;
            }
            if (center.y < 0 + height/2) {
                velY = -velY;
            }
            center.x = center.x + velX;
            center.y = center.y + velY;
        }
    private:
        double velX;
        double velY;
        double width;
        double height;
        void Reset() {
            center.x = SCREEN_W / 2;
            center.y = SCREEN_H / 2;
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
    al_clear_to_color(al_map_rgb(0, 0, 0));
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
