#include <raylib.h>
#include "line.h"

Line::Line(Vector2 pos, Color color) {
    this->posInit = pos;
    this->color = color;
}

Line::Line(Vector2 pos1, Vector2 pos2, Color color) {
    this->posInit = pos1;
    this->posEnd = pos2;
    this->color = color;
}

Color Line::GetColor() {
    return this->color;
}

bool Line::GetSelected() {
    return this->selected;
}

Vector2 Line::GetPosInit() {
    return this->posInit;
}

Vector2 Line::GetPosEnd() {
    return this->posEnd;
}

void Line::SetSelected(bool select) {
    this->selected = select;
}

void Line::SetPosInit(Vector2 pos) {
    this->posInit = pos;
}

void Line::SetPosEnd(Vector2 pos) {
    this->posEnd = pos;
}