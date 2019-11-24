#include "main_menu.h"

#include "gameplay.h"
#include "game_manager.h"

namespace Keyboard_Breaker
{
	namespace Main_Menu
	{
		BUTTON common_mode;
		BUTTON fight_mode;
		BUTTON how_to_play;
		BUTTON exit;

		bool exitGame;

		static int fontTittle = 60;
		static int fontButtons = 24;
		static float widthRec = 200;
		static float heightRec = 50;
		static int distanceRec = 20;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawButtons();

		void InitMenu()
		{
			common_mode.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			common_mode.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 2.5f;
			common_mode.genButton.width = widthRec;
			common_mode.genButton.height = heightRec;

			fight_mode.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			fight_mode.genButton.y = common_mode.genButton.y + heightRec + distanceRec;
			fight_mode.genButton.width = widthRec;
			fight_mode.genButton.height = heightRec;

			how_to_play.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			how_to_play.genButton.y = fight_mode.genButton.y + heightRec + distanceRec;
			how_to_play.genButton.width = widthRec;
			how_to_play.genButton.height = heightRec;

			exit.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
			exit.genButton.y = how_to_play.genButton.y + heightRec + distanceRec;
			exit.genButton.width = widthRec;
			exit.genButton.height = heightRec;

			exitGame = false;
		}

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
			if (CheckCollisionCircleRec(GetMousePosition(), 0, common_mode.genButton))
			{
				common_mode.actuallColor = common_mode.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::gameplay;
					Gameplay::modes = Gameplay::normal;
				}
			}
			else
			{
				common_mode.actuallColor = common_mode.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), 0, fight_mode.genButton))
			{
				fight_mode.actuallColor = fight_mode.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::gameplay;
					Gameplay::modes = Gameplay::fight;
				}
			}
			else
			{
				fight_mode.actuallColor = fight_mode.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), 0, how_to_play.genButton))
			{
				how_to_play.actuallColor = how_to_play.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::howToPlay;
				}
			}
			else
			{
				how_to_play.actuallColor = how_to_play.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), 0, exit.genButton))
			{
				exit.actuallColor = exit.exitState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					exitGame = true;
				}
			}
			else
			{
				exit.actuallColor = exit.normalState;
			}

		}

		void DrawTittle()
		{
			DrawText("KEYBOARD BREAKER", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("KEYBOARD BREAKER", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
		}

		void DrawButtons()
		{
			DrawRectangleRec(common_mode.genButton, common_mode.actuallColor);
			DrawText("Common Mode", static_cast<int>(common_mode.genButton.x + common_mode.genButton.width / 2) - (MeasureText("Common Mode", 24) / 2), static_cast<int>(common_mode.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(fight_mode.genButton, fight_mode.actuallColor);
			DrawText("Fight Mode", static_cast<int>(fight_mode.genButton.x + fight_mode.genButton.width / 2) - (MeasureText("Fight Mode", 24) / 2), static_cast<int>(fight_mode.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(how_to_play.genButton, how_to_play.actuallColor);
			DrawText("How To Play", static_cast<int>(how_to_play.genButton.x + how_to_play.genButton.width / 2) - (MeasureText("How To Play", 24) / 2), static_cast<int>(how_to_play.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(exit.genButton, exit.actuallColor);
			DrawText("Exit", static_cast<int>(exit.genButton.x + exit.genButton.width / 2) - (MeasureText("Exit", 24) / 2), static_cast<int>(exit.genButton.y + heightRec / 3), fontButtons, BLACK);
		}
	}
}