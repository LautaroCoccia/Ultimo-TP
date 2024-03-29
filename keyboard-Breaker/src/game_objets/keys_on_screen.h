#ifndef KEY_IN_SCREEN_H
#define KEY_IN_SCREEN_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Keys
	{
		const int MAX_KEYS = 26;

		struct KEYS
		{
			Rectangle rec[MAX_KEYS];
			char drawKey[MAX_KEYS];
			int ascii[MAX_KEYS];
			int pj1_Point;
			int pj2_Point;
			Image none_player;
			Image player1_skin;
			Image player2_skin;
		};

		struct FIGHT_BAR
		{
			Rectangle rec;
		};

		extern FIGHT_BAR fightBar;
		extern KEYS keys;

		void Initialize();
		void GetPoints();
		void Draw();
	}
}

#endif //KEY_IN_SCREEN_H