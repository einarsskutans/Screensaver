#ifndef UTIL_H
#define UTIL_H

struct Center {
    double x;
    double y;
};

struct Color {
    Color();
    Color(unsigned char pR, unsigned char pG, unsigned char pB);
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif