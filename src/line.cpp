#include <raylib.h>
#include "line.h"

Line::Line(Vector2 pos) {
    this->posInit = pos;
}

Line::Line(Vector2 pos1, Vector2 pos2) {
    this->posInit = pos1;
    this->posEnd = pos2;
}

Vector2 Line::GetPosInit() {
    return this->posInit;
}

Vector2 Line::GetPosEnd() {
    return this->posEnd;
}

void Line::SetPosInit(int x, int y) {
    this->posInit = { (float) x, (float) y };
}

void Line::SetPosEnd(int x, int y) {
    this->posEnd = { (float) x, (float) y };
}