#pragma once

class Select {
  private:
    int segment = 10;
    bool show = false;
    Color color;
    Vector2 initPoints;
    Rectangle points;
  public:
    Select(Color);
    ~Select() {  }

    void SetInitPoints(Vector2);
    void SetEndPoints(Vector2);
    Rectangle GetPoints();
    bool SelectLine(Vector2, Vector2);
    bool Hover(Vector2);
    void Print();
};
