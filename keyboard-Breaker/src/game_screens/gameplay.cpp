#include "gameplay.h"

#include "raylib.h"

#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"

#include <iostream>

namespace Keyboard_Breaker
{
	namespace Gameplay
	{
		gameModes modes;

		static bool gameplay = false;

		void SetGameplayActive()
		{
			gameplay = !gameplay;
		}

		bool GetGameplay()
		{
			return gameplay;
		}

		void InitGameMode()
		{
			modes = fight;
		}

		void UpdateGameplay()
		{
			DrawText("Playing ", static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 5, 30, WHITE);

			switch (modes)
			{
			case normal:

				Player::Input();
				Keys::PowersUps();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				break;
			case fight:

				Player::Input();
				//Keys::PowersUps();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				break;
			}


		}
	}
}