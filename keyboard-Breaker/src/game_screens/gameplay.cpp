#include "gameplay.h"

#include "raylib.h"

#include "game_objets/keys_in_screen.h"

namespace Keyboard_Breaker
{
	static bool gameplay = false;

	void SetGameplayActive()
	{
		gameplay = !gameplay;
	}

	bool GetGameplay()
	{
		return gameplay;
	}

	void UpdateGameplay()
	{
		DrawText("Playing ", static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 5, 30, WHITE);

		Keys::Draw();
	}
}