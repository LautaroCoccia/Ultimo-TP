#include "game_manager.h"

#include "raylib.h"

#include "main_menu.h"
#include "gameplay.h"
#include "win_screen.h"
#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"
#include "game_objets/power_ups.h"

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
			SetExitKey(0);
			state = menu;

			Main_Menu::InitMenu();
			Win_Screen::InitWin();
			Gameplay::InitGameMode();
			Player::Initialice();
			Keys::Initialice();
			Power_Ups::InitPowers();
		}

		void MainGameLoop()
		{
			InitializeWindowNMainLoop();

			while (!WindowShouldClose() && Main_Menu::exitGame == false)
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
				case winScreen:
					Win_Screen::UpdateWin();
					break;
				case credits:
					break;
				}

				EndDrawing();
			}
		}
	}
}