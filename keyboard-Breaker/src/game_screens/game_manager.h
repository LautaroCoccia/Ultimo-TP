#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

namespace Keyboard_Breaker
{
	namespace Game_Manager
	{
		enum STATE
		{
			menu, gameplay, winScreen, credits
		};

		extern STATE state;

		void MainGameLoop();
	}
}
#endif

