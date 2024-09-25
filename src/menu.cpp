#include <raylib.h>
#include "menu.h"

Menu::Menu(int windowWidth, int height, Color bg) {
    this->size = { (float) windowWidth, (float) height };
    this->bg = bg;

    this->select = new Button(10, 10, 100, 50);
    this->select->SetName("Select");

    this->draw = new Button(120, 10, 100, 50);
    this->draw->SetName("Draw");

    this->nColors = 10;

    this->btnColors = new ButtonColor*[10];

    this->btnColors[0] = new ButtonColor(300, 10, 50, 50, GRAY, 0.9),
    this->btnColors[1] = new ButtonColor(360, 10, 50, 50, GREEN, 0.9);
    this->btnColors[2] = new ButtonColor(420, 10, 50, 50, RED, 0.9);
    this->btnColors[3] = new ButtonColor(480, 10, 50, 50, PINK, 0.9);
    this->btnColors[4] = new ButtonColor(540, 10, 50, 50, BLUE, 0.9);
    this->btnColors[5] = new ButtonColor(600, 10, 50, 50, PURPLE, 0.9);
    this->btnColors[6] = new ButtonColor(660, 10, 50, 50, BROWN, 0.9);
    this->btnColors[7] = new ButtonColor(720, 10, 50, 50, GOLD, 0.9);
    this->btnColors[8] = new ButtonColor(780, 10, 50, 50, VIOLET, 0.9);
    this->btnColors[9] = new ButtonColor(840, 10, 50, 50, MAGENTA, 0.9);
}

void Menu::Print() {
    DrawRectangle(0, 0, this->size.x, this->size.y, this->bg);
    DrawLine(0, this->size.y, this->size.x, this->size.y, Color{60, 60, 60, 255});
    this->select->Print();
    this->draw->Print();
    for(int i = 0; i < this->nColors; i++) this->btnColors[i]->Print();
}

bool Menu::Click(Vector2 pos) {
    return ((pos.x >= 0) && (pos.y >= 0) && (pos.x <= size.x) && (pos.y <= size.y));
}