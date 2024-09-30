#include <raylib.h>
#include "line.h"
#include "menu.h"
#include "select.h"

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

Line *CreateLine(Vector2 posInit, Vector2 posEnd, Color color) {
	return new Line(posInit, posEnd, color);
}

Line **PushLine(Line **lines, int &n) {
	n += 1;

	Line **newLines = new Line*[n];

	for(int i = 0; i < n - 1; i++) 
		newLines[i] = CreateLine(lines[i]->GetPosInit(), lines[i]->GetPosEnd(), lines[i]->GetColor());
	
	return newLines;
}

int main() {
	static int windowWidth = 1280, windowHeight = 720, nLines = 0;

	static bool lineInserting = false, draw = true, selection = false, drag = false;

	static Color lineColor = Color{0, 0, 0, 255};

	Line **lines = new Line*[nLines], *line = nullptr;

	Menu *menu = new Menu(windowWidth, 75, DARKGRAY);
	ButtonColor *btnColor = nullptr;

	Select *select = nullptr;

	InitWindow(windowWidth, windowHeight, "Lineas 😲");

    SetWindowMinSize(854, 480);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(520);
	do {
		//* 1. Event Handling

		//** Menu
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && menu->Click(GetMousePosition())) {
			ButtonColor *btnColorPressed;
			if(menu->draw->Click(GetMousePosition())) {
				draw = true;
				selection = false;
				select = nullptr;
			} else if(menu->select->Click(GetMousePosition())) {
				draw = false;
				selection = true;
			} else if((btnColorPressed = menu->ClickColors(GetMousePosition())) != nullptr) {
				lineColor = btnColorPressed->GetColor();
				btnColorPressed->SetSelect(true);
				if(btnColor != nullptr) btnColor->SetSelect(false);
				btnColor = btnColorPressed;
			}
			menu->draw->SetSelect(draw);
			menu->select->SetSelect(selection);
		}

		//** Drag
		if(select != nullptr && select->Hover(GetMousePosition())) {
			SetMouseCursor(9);
			if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && select->Hover(GetMousePosition()) && !menu->Click(GetMousePosition())) {
				drag = true;
				Vector2 newMouse = GetMousePosition();
				Rectangle rec = select->GetPoints();
				int cx = (rec.x + (rec.x + rec.width)) /2, cy = (rec.y + (rec.y + rec.height)) / 2;
				for(int i = 0; i < nLines; i++) if(lines[i]->GetSelected()) {
					Vector2 posInitLine = lines[i]->GetPosInit(), posEndLine = lines[i]->GetPosEnd();
					Vector2 offset = { newMouse.x - cx, newMouse.y - cy };
					posInitLine.x += offset.x;
					posInitLine.y += offset.y;
					posEndLine.x  += offset.x;
					posEndLine.y += offset.y;
					lines[i]->SetPosInit(posInitLine);
					lines[i]->SetPosEnd(posEndLine);
					select->SetInitPoints(Vector2{rec.x + offset.x , rec.y + offset.y});
					select->SetEndPoints(Vector2{rec.x + rec.width + offset.x, rec.y + rec.height + offset.y});
				}
			} else drag = false;
		} else if(!menu->Click(GetMousePosition())) SetMouseCursor(3);
		else SetMouseCursor(1);

		//** Selection
		if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !menu->Click(GetMousePosition()) && selection && !drag) {
			if(select == nullptr) {
				select = new Select(LIGHTGRAY);
				select->SetInitPoints(GetMousePosition());
			} else select->SetEndPoints(GetMousePosition());
		} else if(IsMouseButtonUp(MOUSE_BUTTON_LEFT) && !menu->Click(GetMousePosition()) && selection && !drag) {
			if(select != nullptr) for(int i = 0; i < nLines; i++) {
				if(select->SelectLine(lines[i]->GetPosInit(), lines[i]->GetPosEnd())) lines[i]->SetSelected(true);
				else lines[i]->SetSelected(false);
				// select = nullptr;

			}
		}

		//** Draw
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !menu->Click(GetMousePosition()) && draw) {
			if(!lineInserting) {
				line = new Line(GetMousePosition(), lineColor);
				lineInserting = true;
			} else {
				line->SetPosEnd(GetMousePosition());
				lineInserting = false;
			}
		}

		menu->select->Hover(GetMousePosition());
		menu->draw->Hover(GetMousePosition());
		
		//** Add Line in queue
		if(line != nullptr && !lineInserting) {
			lines = PushLine(lines, nLines);

			lines[nLines-1] = line;

			line = nullptr;
		}

		//* 2. Updating Position
		if(lineInserting && !menu->Click(GetMousePosition())) 
			line->SetPosEnd(GetMousePosition());
		
		//* 3. Drawing
		BeginDrawing();
			ClearBackground(RAYWHITE);
			menu->Print();
			if(select != nullptr) select->Print();
			for(int i = 0; i < nLines; i++) 
				AlgorithmDDA(lines[i]->GetPosInit(), lines[i]->GetPosEnd(), (lines[i]->GetSelected()) ? Color{50, 50, 255, 255} : lines[i]->GetColor());
			if(line != nullptr) AlgorithmDDA(line->GetPosInit(), line->GetPosEnd(), line->GetColor());
		EndDrawing();

	} while (!WindowShouldClose());

	for(int i = 0; i < nLines; i++ ) delete lines[i];

	delete line;

	return 0;
}