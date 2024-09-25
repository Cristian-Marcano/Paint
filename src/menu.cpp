#include <raylib.h>
#include "menu.h"

Menu::Menu(int windowWidth, int height, Color bg) {
    this->size = { (float) windowWidth, (float) height };
    this->bg = bg;
}

void Menu::Print() {
    DrawRectangle(0, 0, this->size.x, this->size.y, this->bg);
    DrawLine(0, this->size.y, this->size.x, this->size.y, Color{60, 60, 60, 255});
}