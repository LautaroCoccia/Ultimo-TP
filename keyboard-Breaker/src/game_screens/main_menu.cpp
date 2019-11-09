#include "main_menu.h"

#include "gameplay.h"

namespace Keyboard_Breaker
{
	Button play;
	Button exit;

	static bool menuActive = true;

	void SetMenuActive();
	void DrawMainMenu();
	void DrawTittle();
	void CheckCollitionButtonsMouse();
	void DrawButtons();

	void UpdateMenu()
	{
		DrawMainMenu();
	}

	bool GetMenuActive()
	{
		return menuActive;
	}


	void SetMenuActive()
	{
		menuActive = !menuActive;
	}

	void DrawMainMenu()
	{
		CheckCollitionButtonsMouse();
		DrawButtons();
		DrawTittle();
	}

	void DrawTittle()
	{
		DrawText("KEYBOARD BREAKER ", static_cast<int>(GetScreenWidth() / 3.8), GetScreenHeight() / 5, 30, WHITE);
		DrawText("v0.1", 600, 380, 20, RAYWHITE);
	}

	void CheckCollitionButtonsMouse()
	{
		if (CheckCollisionCircleRec(GetMousePosition(), 0, play.genButton))
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

	void DrawButtons()
	{
		play.genButton = { 280, 170, 80, 30 };
		DrawRectangleRec(play.genButton, play.actuallColor);
		DrawText("play", 295, 173, 24, BLACK);
		exit.genButton = { 280, 340, 80, 30 };
		DrawRectangleRec(exit.genButton, exit.actuallColor);
		DrawText("exit", 298, 345, 24, BLACK);
	}
}