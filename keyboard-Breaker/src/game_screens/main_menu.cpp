#include "main_menu.h"

#include "gameplay.h"

namespace Keyboard_Breaker
{
	Button play;
	Button exit;

	static bool menuActive = true;

	static int fontTittle = 40;

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
		DrawText("KEYBOARD BREAKER", static_cast<int>(GetScreenWidth()/2 - (MeasureText("KEYBOARD BREAKER", fontTittle)/2)), GetScreenHeight() / 5, fontTittle, WHITE);
		DrawText("v0.1", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);
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
		play.genButton = { static_cast<float>(GetScreenWidth()-80)/2, static_cast<float>(GetScreenHeight()- 30)/2.5f, 80, 30 };
		DrawRectangleRec(play.genButton, play.actuallColor);
		DrawText("play", static_cast<int>(play.genButton.x + play.genButton.width/2) - (MeasureText("play",24)/2), static_cast<int>(play.genButton.y), 24, BLACK);
		
		exit.genButton = { static_cast<float>(GetScreenWidth() - 80) / 2, static_cast<float>(GetScreenHeight() - 30) / 2, 80, 30 };
		DrawRectangleRec(exit.genButton, exit.actuallColor);
		DrawText("exit", static_cast<int>(exit.genButton.x + exit.genButton.width / 2) - (MeasureText("exit", 24) / 2), static_cast<int>(exit.genButton.y), 24, BLACK);
	}
}