#ifndef HOW_TO_PLAY
#define HOW_TO_PLAY

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace How_to_play
	{
		struct BUTTON
		{
			bool cursorOver = false;
			Rectangle genButton;
			Color normalState = WHITE;
			Color overState = BLUE;
			Color actuallColor = normalState;
		};

		void InitHowToPlay();
		void UpdateHowToPlay();
	}
}

#endif //HOW_TO_PLAY