#include <raylib.h>
#include "buttons.h"

Button::Button(int x, int y, int width, int height) {
    this->points = {
        (float) x, (float) y, (float) width, (float) height
    };

    this->bg = Color{200,200,200, 100};
    this->selectedColor = BLUE;
}

void Button::Print(Vector2 pos) {
    DrawRectangleRec(this->points, this->Hover(pos));

    DrawRectangleLinesEx(this->points, (select) ? 1 : 3 , this->selectedColor);

    if(this->name != nullptr) {
        int textWidht = MeasureText(this->name, 2);
        DrawText(TextFormat("%s", this->name), ((this->points.width - textWidht) / 2) + this->points.x, (this->points.height / 2) + this->points.y, 2, WHITE);
    }
}

void Button::SetName(char *name) {
    this->name = name;
}

void Button::SetSelectedColor(Color color) {
    this->selectedColor = color;
}

void Button::SetSelect(bool select) {
    this->select = select;
}

Color Button::Hover(Vector2 pos) {
    return ((Click(pos)) ? this->bg : Color{0,0,0,0});
}

bool Button::Click(Vector2 pos) {
    return ((pos.x >= points.x) && (pos.y >= points.y) && (pos.x <= (points.x + points.width)) && (pos.y <= (points.y + points.height)));
}