#include <raylib.h>
#include "select.h"

Select::Select(Color color) {
    this->color = color;
}

void Select::SetInitPoints(Vector2 pos) {
    this->initPoints = pos;
    this->points.x = pos.x;
    this->points.y = pos.y;
}

void Select::SetEndPoints(Vector2 pos) {
    if( this->initPoints.x > pos.x ) {
        this->points.x = pos.x;
        this->points.width = this->initPoints.x  - this->points.x;
    } else 
        this->points.width = pos.x - this->points.x;

    if( this->initPoints.y > pos.y ) {
        this->points.y = pos.y;
        this->points.height = this->initPoints.y  - this->points.y;
    } else 
        this->points.height = pos.y - this->points.y;
}

Rectangle Select::GetPoints() {
    return this->points;
}

bool Select::SelectLine(Vector2 posInit, Vector2 posEnd) {
    return (((posInit.x >= points.x) && (posInit.y >= points.y) && (posInit.x <= (points.x + points.width)) && (posInit.y <= (points.y + points.height))) || 
    ((posInit.x >= points.x) && (posInit.y >= points.y) && (posEnd.x <= (points.x + points.width)) && (posEnd.y <= (points.y + points.height))));
}

bool Select::Hover(Vector2 pos) {
    return (((pos.x > points.x) && (pos.y > points.y)) && ((pos.x < (points.x + points.width)) && (pos.y < (points.y + points.height))));
}

void Select::Print() {
    DrawRectangleRoundedLines(this->points, 0, this->segment, 1, this->color);
}