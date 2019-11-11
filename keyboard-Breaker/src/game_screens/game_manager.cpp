//#include <stdlib.h>
//#include <time.h>
#include "game_manager.h"

#include "raylib.h"

#include "main_menu.h"
#include "gameplay.h"
#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"

namespace Keyboard_Breaker
{
	const int screenBaseWidth = 1200;
	const int screenBaseHeight = 700;

	static void InitializeWindowNMainLoop();

	static void InitializeWindowNMainLoop()
	{
		InitWindow(screenBaseWidth, screenBaseHeight, "Keyboard Breaker.exe");
		//srand(time(NULL));
	}

	void MainGameLoop()
	{
		InitializeWindowNMainLoop();
		Player::Initialice();
		Keys::Initialice();
		
		while (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
		{
			ClearBackground(BLACK);
			BeginDrawing();

			if (GetMenuActive())
			{
				UpdateMenu();
			}
			else if (GetGameplay())
			{
				UpdateGameplay();
			}
			/*else if (GetGameOver())
			{
				RunGameOver();
			}*/

			EndDrawing();
		}
	}
}