#include "gameplay.h"

#include "raylib.h"

#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"

namespace Keyboard_Breaker
{
	namespace Gameplay
	{
		gameModes modes;

		static int fontTimer = 70;
		static int fontPlayer = 40;
		static int fontBlock = 30;

		int num;
		float contTime;
		bool start;

		static int distancePos0 = 20;

		void Timer();

		void InitGameMode()
		{
			modes = normal;

			num = 3;
			contTime = 3;
			start = false;
		}

		void UpdateGameplay()
		{
			switch (modes)
			{
			case normal:

				Timer();
				if (start)
				{
					Player::Input();
					Keys::GetPoints();
					Player::DrawPoints();
					Player::Win();
				}
				Keys::Draw();

				break;
			case fight:

				Timer();
				if (start)
				{
					Player::Input();
					Keys::GetPoints();
					Player::DrawPoints();
					Player::Win();
				}
				Keys::Draw();

				break;
			}
			DrawText("press ESCAPE to go to the main menu", distancePos0, GetScreenHeight() - 20, 20, RAYWHITE);
		}

		//-----------------------------
		// functions for this cpp
		void Timer()
		{
			if (contTime > 0)
				DrawText(FormatText("%i", num), static_cast<int>(GetScreenWidth() / 2 - (MeasureText(FormatText("%i", num), fontTimer) / 2)), GetScreenHeight() / 5, fontTimer, RED);
			else if (contTime <= 0 && contTime >= -1)
				DrawText("GO!", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("GO!", fontTimer) / 2)), GetScreenHeight() / 5, fontTimer, RED);

			if (contTime < 3 && contTime > 2)
				num = 3;
			else if (contTime < 2 && contTime > 1)
				num = 2;
			else if (contTime < 1 && contTime > 0)
				num = 1;

			if (contTime < -1)
			{
				start = true;
			}
			else
			{
				start = false;
				contTime -= GetFrameTime();

				DrawText("Blue\nPlayer", 100, GetScreenHeight() / 3, fontPlayer, BLUE);
				DrawText("Red\nPlayer", GetScreenWidth() - 225, GetScreenHeight() / 3, fontPlayer, RED);

				if (modes == normal)
				{
					DrawText("Block opponent:\n Key number 1", 50, GetScreenHeight() / 3 + 150, fontBlock, BLUE);
					DrawText("Block opponent:\n Key number 0", GetScreenWidth() - 275, GetScreenHeight() / 3 + 150, fontBlock, RED);
				}
			}
		}
	}
}