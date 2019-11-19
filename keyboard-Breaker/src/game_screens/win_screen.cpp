#include "win_screen.h"

#include "game_manager.h"

#include "main_menu.h"

namespace Keyboard_Breaker
{
	namespace Win_Screen
	{
		BUTTON returnMenu;
		BUTTON exit;

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

			exit.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			exit.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 1.5f;
			exit.genButton.width = widthRec;
			exit.genButton.height = heightRec;
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
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::menu;
				}
			}
			else
			{
				returnMenu.actuallColor = returnMenu.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), 0, exit.genButton))
			{
				exit.actuallColor = exit.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Main_Menu::exitGame = true;
				}
			}
			else
			{
				exit.actuallColor = exit.normalState;
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
			DrawText("Return menu", static_cast<int>(returnMenu.genButton.x + returnMenu.genButton.width / 2) - (MeasureText("Return Menu", 24) / 2), static_cast<int>(returnMenu.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(exit.genButton, exit.actuallColor);
			DrawText("Exit", static_cast<int>(exit.genButton.x + exit.genButton.width / 2) - (MeasureText("Exit", 24) / 2), static_cast<int>(exit.genButton.y + heightRec / 3), fontButtons, BLACK);
		}
	}
}