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
Square square{10, 10, 10, 10};
Square *psquare = &square;

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

    screensaver.Add(psquare, 0);
    cout << screensaver.PFigures;

    RunAllegro(&fps, &draw);
    DestroyAllegro();
    return 0;
}