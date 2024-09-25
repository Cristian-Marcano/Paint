#pragma once

class Button {
  protected:
    char *name = nullptr;
    Rectangle points;
    bool select = false;
    Color bg, selectedColor;
  public:
    Button(int,int,int,int);
    ~Button() { }

    void SetName(char*);
    void SetSelectedColor(Color);
    void SetSelect(bool);
    virtual void Print();
    void Hover(Vector2);
    bool Click(Vector2);
};

class ButtonColor : public Button {
  private:
    float roudness;
    Color color;
  public:
    ButtonColor(int,int,int,int, Color, float);
    ~ButtonColor() { }

    void SetColor(Color);
    Color GetColor();
    void Print() override;
};