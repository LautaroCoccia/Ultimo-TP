#include "main_menu.h"

#include "gameplay.h"
#include "game_manager.h"
#include "assets_code/sounds.h"

namespace Keyboard_Breaker
{
	namespace Main_Menu
	{
		BUTTON common_mode;
		BUTTON fight_mode;
		BUTTON how_to_play;
		BUTTON sound;
		BUTTON exit;
		
		bool exitGame;
		bool soundActive = true;

		static const int HALFSCREEN = 2;
		static const int MOUSERADIUS = 0;

		static int fontTittle = 60;
		static int fontButtons = 24;
		static float widthRec = 200;
		static float heightRec = 50;
		static int distanceRec = 20;

		void CheckCollitionButtonsMouse();
		void DrawTittle();
		void DrawButtons();
		void DrawCredits();

		void InitMenu()
		{
			common_mode.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / HALFSCREEN;
			common_mode.genButton.y = static_cast<float>(GetScreenHeight() - heightRec) / 2.5f;
			common_mode.genButton.width = widthRec;
			common_mode.genButton.height = heightRec;

			fight_mode.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / HALFSCREEN;
			fight_mode.genButton.y = common_mode.genButton.y + heightRec + distanceRec;
			fight_mode.genButton.width = widthRec;
			fight_mode.genButton.height = heightRec;

			how_to_play.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / HALFSCREEN;
			how_to_play.genButton.y = fight_mode.genButton.y + heightRec + distanceRec;
			how_to_play.genButton.width = widthRec;
			how_to_play.genButton.height = heightRec;

			sound.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / HALFSCREEN;
			sound.genButton.y = how_to_play.genButton.y + heightRec + distanceRec;
			sound.genButton.width = widthRec;
			sound.genButton.height = heightRec;

			exit.genButton.x = static_cast<float>(GetScreenWidth() - widthRec) / HALFSCREEN;
			exit.genButton.y = sound.genButton.y + heightRec + distanceRec;
			exit.genButton.width = widthRec;
			exit.genButton.height = heightRec;

			exitGame = false;
		}

		void UpdateMenu()
		{
			CheckCollitionButtonsMouse();
			DrawTittle();
			DrawButtons();
			DrawCredits();
		}

		//-----------------------------
		// functions for this cpp
		void CheckCollitionButtonsMouse()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, common_mode.genButton))
			{
				common_mode.actuallColor = common_mode.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::gameplay;
					Gameplay::modes = Gameplay::normal;
				}
			}
			else
			{
				common_mode.actuallColor = common_mode.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, fight_mode.genButton))
			{
				fight_mode.actuallColor = fight_mode.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::gameplay;
					Gameplay::modes = Gameplay::fight;
				}
			}
			else
			{
				fight_mode.actuallColor = fight_mode.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, how_to_play.genButton))
			{
				how_to_play.actuallColor = how_to_play.overState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					Game_Manager::state = Game_Manager::howToPlay;
				}
			}
			else
			{
				how_to_play.actuallColor = how_to_play.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, sound.genButton))
			{
				
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					soundActive = !soundActive;
				}
				if (soundActive)
				{
					SetMusicVolume(Sounds::loopMusic, 100);
					SetSoundVolume(Sounds::key_press, 100);
					SetSoundVolume(Sounds::mine_press, 100);
					SetSoundVolume(Sounds::block_press, 100);
					SetSoundVolume(Sounds::desblock_press, 100);
					sound.actuallColor = sound.overState;
				}
				else if (!soundActive)
				{
					SetMusicVolume(Sounds::loopMusic, 0);
					SetSoundVolume(Sounds::key_press, 0);
					SetSoundVolume(Sounds::mine_press, 0);
					SetSoundVolume(Sounds::block_press, 0);
					SetSoundVolume(Sounds::desblock_press, 0);
					sound.actuallColor = sound.exitState;
				}
				
			}
			else
			{
				sound.actuallColor = sound.normalState;
			}

			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, exit.genButton))
			{
				exit.actuallColor = exit.exitState;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					exitGame = true;
				}
			}
			else
			{
				exit.actuallColor = exit.normalState;
			}

			

		}

		void DrawTittle()
		{
			DrawText("KEYBOARD BREAKER", static_cast<int>(GetScreenWidth() / HALFSCREEN - (MeasureText("KEYBOARD BREAKER", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
		}

		void DrawButtons()
		{
			DrawRectangleRec(common_mode.genButton, common_mode.actuallColor);
			DrawText("Normal Mode", static_cast<int>(common_mode.genButton.x + common_mode.genButton.width / HALFSCREEN) - (MeasureText("Normal Mode", 24) / 2), static_cast<int>(common_mode.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(fight_mode.genButton, fight_mode.actuallColor);
			DrawText("Fight Mode", static_cast<int>(fight_mode.genButton.x + fight_mode.genButton.width / HALFSCREEN) - (MeasureText("Fight Mode", 24) / 2), static_cast<int>(fight_mode.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(how_to_play.genButton, how_to_play.actuallColor);
			DrawText("How To Play", static_cast<int>(how_to_play.genButton.x + how_to_play.genButton.width / HALFSCREEN) - (MeasureText("How To Play", 24) / 2), static_cast<int>(how_to_play.genButton.y + heightRec / 3), fontButtons, BLACK);

			DrawRectangleRec(sound.genButton, sound.actuallColor);
			if (soundActive)
			{
				DrawText("Sound ON", static_cast<int>(sound.genButton.x + sound.genButton.width / HALFSCREEN) - (MeasureText("Sound ON", 24) / 2), static_cast<int>(sound.genButton.y + heightRec / 3), fontButtons, BLACK);
			}
			else if (!soundActive)
			{
				DrawText("Sound OFF", static_cast<int>(sound.genButton.x + sound.genButton.width / HALFSCREEN) - (MeasureText("Sound OFF", 24) / 2), static_cast<int>(sound.genButton.y + heightRec / 3), fontButtons, BLACK);
			}
			

			DrawRectangleRec(exit.genButton, exit.actuallColor);
			DrawText("Exit", static_cast<int>(exit.genButton.x + exit.genButton.width / 2) - (MeasureText("Exit", 24) / 2), static_cast<int>(exit.genButton.y + heightRec / 3), fontButtons, BLACK);

		}

		void DrawCredits()
		{
			int font = 15;
			int distanceX = 10;
			int distanceY1 = 10;
			int distanceY2 = 45;

			DrawText("Made with RAYLIB", distanceX, distanceY1, font, WHITE);

			DrawText("Lautaro Coccia\nTomas Aquistapace", distanceX, GetScreenHeight() - distanceY2, font, WHITE);
		}
	}
}