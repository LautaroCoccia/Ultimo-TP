#ifndef SOUNDS_H
#define SOUNDS_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Sounds
	{
		extern Music loopMusic;
		extern Sound key_press;
		extern Sound mine_press;

		extern bool muteSound;

		void LoadMusic();
		void UpdateGameMusic();
		void UnloadMusic_Sound();
	}
}

#endif //SOUNDS_H