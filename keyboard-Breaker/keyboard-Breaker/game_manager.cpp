#include "game_manager.h"

#include "raylib.h"

#include "main_menu.h"
#include "gameplay.h"

const int screenBaseWidth = 1200;
const int screenBaseHeight = 700;

static void MainGameLoop();

void InitializeWindowNMainLoop()
{
	InitWindow(screenBaseWidth, screenBaseHeight, "Keyboard Breaker.exe");
	MainGameLoop();
}

static void MainGameLoop()
{
	/*srand(time(NULL));*/
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

