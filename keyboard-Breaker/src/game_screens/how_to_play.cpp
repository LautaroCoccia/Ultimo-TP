#include "how_to_play.h"

#include "raylib.h"

#include "game_manager.h"

namespace Keyboard_Breaker
{
	namespace How_to_play
	{
		BUTTON how_to_play;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawInstruction();
		void DrawButtons();

		static int fontTittle = 60;
		static int fontSubTittle = 45;
		static int fontText = 20;
		static int fontButtons = 24;
		static float widthRec = 200;
		static float heightRec = 50;
		static int distanceTittle = 60;

		void InitHowToPlay()
		{
			how_to_play.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			how_to_play.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 2 + static_cast<float>(GetScreenHeight() - heightRec) / 3;
			how_to_play.genButton.width = widthRec;
			how_to_play.genButton.height = heightRec;
		}

		void UpdateHowToPlay()
		{
			CheckCollitionButtonsMouse();
			DrawTittle();
			DrawInstruction();
			DrawButtons();
		}

		//-----------------------------
		// functions for this cpp
		void CheckCollitionButtonsMouse()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), 0, how_to_play.genButton))
			{
				how_to_play.actuallColor = how_to_play.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::menu;
				}
			}
			else
			{
				how_to_play.actuallColor = how_to_play.normalState;
			}
		}

		void DrawTittle()
		{
			DrawText("KEYBOARD BREAKER", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("KEYBOARD BREAKER", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
			DrawText("How to Play", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("How to Play", fontSubTittle) / 2)), GetScreenHeight() / 5 + distanceTittle, fontSubTittle, WHITE);
		}

		void DrawInstruction()
		{
			DrawText("This is a speed game, the fastest player to press the button with its color will win the game.\nWin the best of 30 (common mode) or the one that can fill the upper bar with its color (fight mode)", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("This is a speed game, the fastest player to press the button with its color will win the game.\nWin the best of 30 (common mode) or the one that can fill the upper bar with its color (fight mode)", fontText) / 2)), GetScreenHeight() / 2, fontText, WHITE);

			DrawText("MINES: when it appears, the first player to touch it loses 5 points", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("MINES: when it appears, the first player to touch it loses 5 points", fontText) / 2)), GetScreenHeight() / 2 + fontText * 4, fontText, GREEN);

			DrawText("KEYBOARD BREAKER: press your last key quickly to earn more points", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("KEYBOARD BREAKER: press your last key quickly to earn more points", fontText) / 2)), GetScreenHeight() / 2 + fontText * 5, fontText, GRAY);

			DrawText("BLOCK KEY: press the 1 or 0 key to lock the key to your opponent for 10 touches. Wait for it to appear!", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("BLOCK KEY: press the 1 or 0 key to lock the key to your opponent for 10 touches. Wait for it to appear!", fontText) / 2)), GetScreenHeight() / 2 + fontText * 6, fontText, SKYBLUE);
		}

		void DrawButtons()
		{
			DrawRectangleRec(how_to_play.genButton, how_to_play.actuallColor);
			DrawText("Return menu", static_cast<int>(how_to_play.genButton.x + how_to_play.genButton.width / 2) - (MeasureText("Return Menu", 24) / 2), static_cast<int>(how_to_play.genButton.y + heightRec / 3), fontButtons, BLACK);
		}
	}
}