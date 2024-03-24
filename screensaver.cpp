#include "include/screensaver.h"
#include "include/physics.h"

void Screensaver::Add(Figure* figure) {
    PFigures.push_back(figure);
}
void Screensaver::Next() {
    for (int i = 0; i < PFigures.size(); i++) {
        PFigures[i]->Move();
    }
}
void Screensaver::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (int i = 0; i < PFigures.size(); i++) {
        PFigures[i]->Draw();
    }
}