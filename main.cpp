#include <iostream>
#include "include/AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

#include "include/util.h"
#include "include/figure.h"
#include "include/square.h"
#include "include/screensaver.h"

using namespace std;

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
    // Figures are added with rand velocity & rand starting position in "square.cpp"
    for (int i = 1; i < 15; i++) {  // For some reason everything breaks over 30 (60 objects)
        Color* color1 = new Color(rand()%255, rand()%255, rand()%255);
        Color* color2 = new Color(rand()%255, rand()%255, rand()%255);
        Square* square = new Square(50, 50, 1 + rand()%10, 1 + rand()%10, *color1);
        Circle* circle = new Circle(25, 1 + rand()%10, 1 + rand()%10, *color2);
        screensaver.Add(square);
        screensaver.Add(circle);
    }

    screensaver.Print();

    al_set_window_title(alDisplay, "Screensaver");
    RunAllegro(&fps, &draw);
    DestroyAllegro();

    return 0;
}