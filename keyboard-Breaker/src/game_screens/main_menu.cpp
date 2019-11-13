#include "main_menu.h"

#include "gameplay.h"
#include "game_manager.h"

namespace Keyboard_Breaker
{
	namespace Main_Menu
	{
		Button play;
		Button exit;

		static bool menuActive = true;

		static int fontTittle = 40;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawButtons();

		void UpdateMenu()
		{
			CheckCollitionButtonsMouse();
			DrawButtons();
			DrawTittle();
		}

		//-----------------------------
		// functions for this cpp
		void CheckCollitionButtonsMouse()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), 0, play.genButton))
			{
				play.actuallColor = play.overState;
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::gameplay;
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

		void DrawTittle()
		{
			DrawText("KEYBOARD BREAKER", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("KEYBOARD BREAKER", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, WHITE);
			DrawText("v0.1", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);
		}

		void DrawButtons()
		{
			play.genButton = { static_cast<float>(GetScreenWidth() - 80) / 2, static_cast<float>(GetScreenHeight() - 30) / 2.5f, 80, 30 };
			DrawRectangleRec(play.genButton, play.actuallColor);
			DrawText("play", static_cast<int>(play.genButton.x + play.genButton.width / 2) - (MeasureText("play", 24) / 2), static_cast<int>(play.genButton.y), 24, BLACK);

			exit.genButton = { static_cast<float>(GetScreenWidth() - 80) / 2, static_cast<float>(GetScreenHeight() - 30) / 2, 80, 30 };
			DrawRectangleRec(exit.genButton, exit.actuallColor);
			DrawText("exit", static_cast<int>(exit.genButton.x + exit.genButton.width / 2) - (MeasureText("exit", 24) / 2), static_cast<int>(exit.genButton.y), 24, BLACK);
		}
	}
}