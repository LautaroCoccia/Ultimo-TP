#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Main_Menu
	{
		struct BUTTON
		{
			bool cursorOver = false;
			Rectangle genButton;
			Color normalState = WHITE;
			Color overState = BLUE;
			Color exitState = RED;
			Color actuallColor = normalState;
		};

		extern bool exitGame;

		void InitMenu();
		void UpdateMenu();
	}
}

#endif