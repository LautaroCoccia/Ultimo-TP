#include "main_menu.h"

#include "raylib.h"

#include "gameplay.h"

struct Button
{
	bool cursorOver = false;
	Rectangle genButton = { 0,0,0,0 };
	Color normalState = WHITE;
	Color overState = BLUE;
	Color actuallColor = normalState;
};
Button play;
Button exit; 
static bool menuActive = true;
static void DrawMainMenu();
static void DrawTittle();
static void CheckCollitionButtonsMouse();
static void DrawButtons();

void UpdateMenu()
{
	DrawMainMenu();
}
void SetMenuActive()
{
	menuActive = !menuActive;
}
bool GetMenuActive()
{
	return menuActive;
}
static void DrawMainMenu()
{
	CheckCollitionButtonsMouse();
	DrawButtons();
	DrawTittle();
}

static void DrawTittle()
{
	DrawText("KEYBOARD BREAKER ", static_cast<int>(GetScreenWidth() / 3.8), GetScreenHeight() / 5, 30, WHITE);
	DrawText("v0.1", 600, 380, 20, RAYWHITE);
}
static void CheckCollitionButtonsMouse()
{
	if(CheckCollisionCircleRec(GetMousePosition(), 0, play.genButton))
	{
		play.actuallColor = play.overState;
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			SetMenuActive();
			SetGameplayActive();
		}
	}
	else
	{
		play.actuallColor = play.normalState;
	}
	if (CheckCollisionCircleRec(GetMousePosition(), 0, exit.genButton))
	{
		exit.actuallColor = exit.overState;
	}
	else
	{
		exit.actuallColor = exit.normalState;
	}
	
}
static void DrawButtons()
{
	play.genButton = { 280, 170, 80, 30 };
	DrawRectangleRec(play.genButton, play.actuallColor);
	DrawText("play", 295, 173, 24,BLACK );
	exit.genButton = { 280, 340, 80, 30 };
	DrawRectangleRec(exit.genButton, exit.actuallColor);
	DrawText("exit", 298, 345, 24, BLACK);
}
