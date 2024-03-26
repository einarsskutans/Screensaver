#ifndef UTIL_H
#define UTIL_H

const int FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;

struct Center {
    int x;
    int y;
};

struct Color {
    Color();
    Color(unsigned char pR, unsigned char pG, unsigned char pB);
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif