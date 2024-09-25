#include <raylib.h>
#include "line.h"
// #include "buttons.h"

int Absolute(int number) {
	return (number < 0) ? -number : number;
}

void PrintPoint(Vector2 pos, Color color) {
	DrawPixelV(pos, color);
}

void AlgorithmDDA(Vector2 posInit, Vector2 posEnd, Color color) {
	Vector2 dPos = { posEnd.x - posInit.x, posEnd.y - posInit.y };

	int steps = (Absolute(dPos.x) < Absolute(dPos.y)) ? Absolute(dPos.y): Absolute(dPos.x);

	Vector2 posIncrement = { dPos.x/steps, dPos.y/steps };

	Vector2 pos = posInit;

	for(int i = 0; i < steps + 1; i++) {
		PrintPoint(pos, color);
		pos.x += posIncrement.x;
		pos.y += posIncrement.y;
	}
}

Line *CreateLine(Vector2 posInit, Vector2 posEnd) {
	return new Line(posInit, posEnd);
}

Line **PushLine(Line **lines, int &n) {
	n += 1;

	Line **newLines = new Line*[n];

	for(int i = 0; i < n - 1; i++) 
		newLines[i] = CreateLine(lines[i]->GetPosInit(), lines[i]->GetPosEnd());
	
	return newLines;
}

int main() {
	static int windowWidth = 1280, windowHeight = 720, nLines = 0;

	static bool lineInserting = false;

	// char *btnNameSelect = "Select";

	Line **lines = new Line*[nLines], *line = nullptr;

	// Button *btn = new Button(30, 30, 100, 50);
	// btn->SetName(btnNameSelect);

	InitWindow(windowWidth, windowHeight, "Lineas 😲");

    SetWindowMinSize(854, 480);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);
	do {
		//* 1. Event Handling
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !lineInserting) {
			line = new Line(GetMousePosition());
			lineInserting = true;
		} else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && lineInserting) {
			line->SetPosEnd(GetMouseX(), GetMouseY());
			lineInserting = false;
		}

		if(line != nullptr && !lineInserting) {
			lines = PushLine(lines, nLines);

			lines[nLines-1] = line;

			line = nullptr;
		}

		//* 2. Updating Position
		if(lineInserting) 
			line->SetPosEnd(GetMouseX(), GetMouseY());
		
		//* 3. Drawing
		BeginDrawing();
			ClearBackground(GRAY);
			// btn->Print(GetMousePosition());
			for(int i = 0; i < nLines; i++) AlgorithmDDA(lines[i]->GetPosInit(), lines[i]->GetPosEnd(), WHITE);
			if(line != nullptr) AlgorithmDDA(line->GetPosInit(), line->GetPosEnd(), WHITE);
		EndDrawing();

	} while (!WindowShouldClose());

	for(int i = 0; i < nLines; i++ ) delete lines[i];

	delete line;

	return 0;
}