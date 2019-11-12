#ifndef PLAYERS_H
#define PLAYERS_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Player
	{
		struct PLAYER
		{
			int keyPress;
			int pointsPj1;
			int pointsPj2;
			bool win;
		};

		struct POINTS_BAR
		{
			Rectangle rec;
			int movement;
		};

		extern PLAYER players;
		extern POINTS_BAR pointsBar; // fight mode only

		void Initialice();
		void DrawPoints();
		void Input();
	}
}

#endif


