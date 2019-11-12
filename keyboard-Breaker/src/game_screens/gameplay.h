#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Keyboard_Breaker
{
	namespace Gameplay
	{
		enum gameModes {
			normal, fight
		};

		extern gameModes modes;

		void SetGameplayActive();
		bool GetGameplay();
		void InitGameMode();
		void UpdateGameplay();
	}
}

#endif
