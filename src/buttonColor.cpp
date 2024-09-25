#include <raylib.h>
#include "buttons.h"

ButtonColor::ButtonColor(int x, int y, int width, int height, Color color, float roudness) : Button(x, y, width, height) {
    this->color = color;
    this->roudness = roudness;
}

void ButtonColor::Print() {
    DrawRectangleRounded(this->points, this->roudness, 0, this->color);

    DrawRectangleRoundedLines(this->points, this->roudness, 0, (this->select) ? 3 : 1.5, WHITE);
}

void ButtonColor::SetColor(Color color) {
    this->color = color;
}

Color ButtonColor::GetColor() {
    return this->color;
}