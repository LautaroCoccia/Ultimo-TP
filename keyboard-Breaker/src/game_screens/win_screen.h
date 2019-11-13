#ifndef WIN_SCREEN_H
#define WIN_SCREEN_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Win_Screen
	{
		struct BUTTON
		{
			bool cursorOver = false;
			Rectangle genButton;
			Color normalState = WHITE;
			Color overState = BLUE;
			Color actuallColor = normalState;
		};

		void InitWin();
		void UpdateWin();
	}
}

#endif // WIN_SCREEN_H