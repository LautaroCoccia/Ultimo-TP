#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Main_Menu
	{
		struct Button
		{
			bool cursorOver = false;
			Rectangle genButton = { 0,0,0,0 };
			Color normalState = WHITE;
			Color overState = BLUE;
			Color actuallColor = normalState;
		};
		extern Button play;
		extern Button exit;

		void UpdateMenu();
	}
}

#endif