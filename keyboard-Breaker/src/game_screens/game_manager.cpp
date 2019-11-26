#include "game_manager.h"

#include "raylib.h"

#include "main_menu.h"
#include "gameplay.h"
#include "win_screen.h"
#include "how_to_play.h"
#include "game_objets/players.h"
#include "game_objets/keys_in_screen.h"
#include "game_objets/power_ups.h"
#include "assets_code/sounds.h"

namespace Keyboard_Breaker
{
	namespace Game_Manager
	{
		STATE state;

		const int SCREEN_BASE_WIDTH = 1200;
		const int SCREEN_BASE_HEIGHT = 700;
		
		
		void InitializeWindowNMainLoop();
		void InitializeValues();

		void InitializeWindowNMainLoop()
		{
			InitWindow(SCREEN_BASE_WIDTH, SCREEN_BASE_HEIGHT, "Keyboard Breaker.exe");
			SetExitKey(0);
			state = menu;

			Sounds::LoadMusic();

			InitializeValues();
		}

		void InitializeValues()
		{
			Main_Menu::InitMenu();

			Gameplay::InitGameMode();
			How_to_play::InitHowToPlay();
			Win_Screen::InitWin();
			
			Player::Initialize();
			Keys::Initialize();
			Power_Ups::InitPowers();
		}

		void MainGameLoop()
		{
			InitializeWindowNMainLoop();

			while (!WindowShouldClose() && Main_Menu::exitGame == false)
			{
				ClearBackground(BLACK);
				BeginDrawing();

				Sounds::UpdateGameMusic();

				switch (state)
				{
				case menu:
					InitializeValues();
					Main_Menu::UpdateMenu();
					break;
				case gameplay:
					Gameplay::UpdateGameplay();
					break;
				case winScreen:
					Win_Screen::UpdateWin();
					break;
				case howToPlay:
					How_to_play::UpdateHowToPlay();
					break;
				case credits:
					break;
				}

				DrawText("v1.0", GetScreenWidth() - 40, GetScreenHeight() - 20, 20, RAYWHITE);

				EndDrawing();
			}

			Sounds::UnloadMusic_Sound();
			CloseWindow();
		}
	}
}