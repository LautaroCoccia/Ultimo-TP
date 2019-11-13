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
	namespace Game_Manager
	{
		STATE state;

		const int screenBaseWidth = 1200;
		const int screenBaseHeight = 700;

		static void InitializeWindowNMainLoop();
		static void InitializeWindowNMainLoop()
		{
			InitWindow(screenBaseWidth, screenBaseHeight, "Keyboard Breaker.exe");

			state = menu;

			Gameplay::InitGameMode();
			Player::Initialice();
			Keys::Initialice();
		}

		void MainGameLoop()
		{
			InitializeWindowNMainLoop();

			while (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
			{
				ClearBackground(BLACK);
				BeginDrawing();

				switch (state)
				{
				case menu:
					Main_Menu::UpdateMenu();
					break;
				case gameplay:
					Gameplay::UpdateGameplay();
					break;
				case gameOver:
					break;
				case credits:
					break;
				}

				EndDrawing();
			}
		}
	}
}