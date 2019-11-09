#ifndef KEY_IN_SCREEN_H
#define KEY_IN_SCREEN_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Keys
	{
		const int MAX_KEYS = 27;

		struct KEYS
		{
			Rectangle rec[MAX_KEYS];
			Image none_player;
			Image player1_skin;
			Image player2_skin;
		};

		extern KEYS keys;

		void Initialice();
		void Draw();
	}
}

#endif //KEY_IN_SCREEN_H