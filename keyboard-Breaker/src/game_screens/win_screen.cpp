#include "win_screen.h"

#include "game_manager.h"

namespace Keyboard_Breaker
{
	namespace Win_Screen
	{
		BUTTON returnMenu;

		static int fontTittle = 40;
		static int fontButtons = 24;
		static float widthRec = 200;
		static float heightRec = 50;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawButtons();

		void InitWin()
		{
			returnMenu.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			returnMenu.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 2.5f;
			returnMenu.genButton.width = widthRec;
			returnMenu.genButton.height = heightRec;
		}

		void UpdateWin()
		{
			CheckCollitionButtonsMouse();
			DrawButtons();
			DrawTittle();
		}

		//-----------------------------
		// functions for this cpp
		void CheckCollitionButtonsMouse()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), 0, returnMenu.genButton))
			{
				returnMenu.actuallColor = returnMenu.overState;
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::menu;
				}
			}
			else
			{
				returnMenu.actuallColor = returnMenu.normalState;
			}
		}

		void DrawTittle()
		{
			DrawText("YOU WIN", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("YOU WIN", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, WHITE);
			DrawText("v0.1", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);
		}

		void DrawButtons()
		{
			DrawRectangleRec(returnMenu.genButton, returnMenu.actuallColor);
			DrawText("Common Mode", static_cast<int>(returnMenu.genButton.x + returnMenu.genButton.width / 2) - (MeasureText("Common Mode", 24) / 2), static_cast<int>(returnMenu.genButton.y + heightRec / 3), fontButtons, BLACK);
		}
	}
}