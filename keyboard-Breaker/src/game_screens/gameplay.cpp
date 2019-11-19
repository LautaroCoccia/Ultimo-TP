#include <iostream>
#include "gameplay.h"

#include "raylib.h"

#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"

namespace Keyboard_Breaker
{
	namespace Gameplay
	{
		gameModes modes;

		void InitGameMode()
		{
			modes = fight;
		}

		void UpdateGameplay()
		{
			switch (modes)
			{
			case normal:

				Player::Input();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				DrawText("v0.2", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);

				break;
			case fight:

				Player::Input();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				DrawText("v0.2", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);

				break;
			}


		}
	}
}