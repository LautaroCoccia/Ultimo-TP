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
			Color actuallColor = normalState;
		};
		extern BUTTON common_mode;
		extern BUTTON fight_mode;
		extern BUTTON exit;

		extern bool exitGame;

		void InitMenu();
		void UpdateMenu();
	}
}

#endif