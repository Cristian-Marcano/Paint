#pragma once

class Menu {
  private:
    Vector2 size;
    Color bg;
  public:
    Menu(int, int, Color);
    ~Menu() { }

    void Print();
};