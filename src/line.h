#pragma once

class Line {
  private:
    Color color;
    bool selected = false;
    Vector2 posInit, posEnd;
  public:
    Line(Vector2, Color);
    Line(Vector2, Vector2, Color);
    ~Line() { }

    Color GetColor();
    bool GetSelected();
    Vector2 GetPosInit();
    Vector2 GetPosEnd();
    void SetSelected(bool);
    void SetPosInit(Vector2);
    void SetPosEnd(Vector2);
};