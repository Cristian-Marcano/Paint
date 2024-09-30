#pragma once
#include "buttons.h"

class Menu {
  private:
    int nColors = 10; 
    Vector2 size;
    Color bg;
  public:
    Menu(int, int, Color);
    ~Menu() { }
    
    ButtonColor **btnColors;
    Button *select, *draw;
    void Print();
    bool Click(Vector2);
    ButtonColor *ClickColors(Vector2);
};