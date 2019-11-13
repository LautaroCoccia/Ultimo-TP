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
				Keys::PowersUps();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				break;
			case fight:

				Player::Input();
				Keys::PowersUps();
				Keys::EarnPoint();
				Player::DrawPoints();
				Keys::Draw();

				break;
			}


		}
	}
}