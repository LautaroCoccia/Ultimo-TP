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
			
			//power ups
			bool mine;
		};
		
		extern KEYS keys;

		void Initialice();
		void MovePoint();
		void PowersUps();
		void EarnPoint();
		void Draw();
	}
}

#endif //KEY_IN_SCREEN_H