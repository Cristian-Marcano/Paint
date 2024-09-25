#pragma once

class Line {
  private:
    Vector2 posInit, posEnd;
  public:
    Line(Vector2);
    Line(Vector2, Vector2);
    ~Line() { }

    Color color;
    Vector2 GetPosInit();
    Vector2 GetPosEnd();
    void SetPosInit(int, int);
    void SetPosEnd(int, int);
};