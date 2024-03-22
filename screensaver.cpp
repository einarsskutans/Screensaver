#include "include/screensaver.h"
#include "include/physics.h"

void Screensaver::Add(Figure* figure, int element) {
    if (n < Screensaver::n) {
        PFigures[element] = figure;
    }
}
void Screensaver::Next() {
    for (int i = 0; i < Screensaver::n+1; i++) {
        PFigures[i]->Move();
    }
}
void Screensaver::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (int i = 0; i < Screensaver::n+1; i++) {
        PFigures[i]->Draw();
    }
}