#include "win_screen.h"

#include "game_manager.h"
#include "game_objets/players.h"

namespace Keyboard_Breaker
{
	namespace Win_Screen
	{
		BUTTON returnMenu;

		static int fontTittle = 60;
		static int fontButtons = 24;
		static float widthRec = 200;
		static float heightRec = 50;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawButtons();

		void InitWin()
		{
			returnMenu.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			returnMenu.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 2;
			returnMenu.genButton.width = widthRec;
			returnMenu.genButton.height = heightRec;
		}

		void UpdateWin()
		{
			CheckCollitionButtonsMouse();
			DrawButtons();
			DrawTittle();
			Player::DrawPoints();
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
		}

		void DrawTittle()
		{
			if (Player::players.pointsPj1 >= Player::MAX_POINTS||Player::pointsBar.rec.x + Player::pointsBar.rec.width >= GetScreenWidth())
			{
				DrawText("PLAYER 1 WINS", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("PLAYER 1 WINS", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
			}
			else
			{
				DrawText("PLAYER 2 WINS", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("PLAYER 2 WINS", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, RED);

			}
		}

		void DrawButtons()
		{
			DrawRectangleRec(returnMenu.genButton, returnMenu.actuallColor);
			DrawText("Return menu", static_cast<int>(returnMenu.genButton.x + returnMenu.genButton.width / 2) - (MeasureText("Return Menu", 24) / 2), static_cast<int>(returnMenu.genButton.y + heightRec / 3), fontButtons, BLACK);
		}
	}
}