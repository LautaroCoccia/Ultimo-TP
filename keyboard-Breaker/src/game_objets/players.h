#ifndef PLAYERS_H
#define PLAYERS_H

namespace Keyboard_Breaker
{
	namespace Player
	{
		struct PLAYER {
			int keyPress;
			int pointsPj1;
			int pointsPj2;
			bool win;
		};

		extern PLAYER players;

		void Initialice();
		void DrawPoints();
		void Input();
	}
}

#endif


