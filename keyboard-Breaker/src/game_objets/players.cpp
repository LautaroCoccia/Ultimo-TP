#include "players.h"

#include "game_screens/gameplay.h"
#include "game_screens/game_manager.h"

namespace Keyboard_Breaker
{
	using namespace Gameplay;

	namespace Player
	{
		PLAYER players;
		POINTS_BAR pointsBar; // fight mode only

		const int FONT_POINT = 100;

		void Initialice()
		{
			players.keyPress = 0;
			players.pointsPj1 = 0;
			players.pointsPj2 = 0;
			players.winPj1 = false;
			players.winPj2 = false;

			// fight mode
			pointsBar.rec.height = 30.0f;
			pointsBar.rec.width = 300.0f;
			pointsBar.rec.x = (GetScreenWidth()/2 - pointsBar.rec.width/2);
			pointsBar.rec.y = 20;
			pointsBar.movement = 50;
		}

		void Win()
		{
			switch (Gameplay::modes)
			{
			case normal:

				if (players.pointsPj1 >= 30 || players.pointsPj2 >= 30)
				{
					Game_Manager::state = Game_Manager::winScreen;
				}
				else
				{
					Game_Manager::state = Game_Manager::winScreen;
				}
				break;

			case fight:

				if (pointsBar.rec.x <= 0 || pointsBar.rec.x >= GetScreenWidth())
				{
					Game_Manager::state = Game_Manager::winScreen;
				}
				break;
			}
		}

		void DrawPoints()
		{
			switch (modes)
			{
			case normal:
				DrawText(FormatText("%i", players.pointsPj1), 80, 20, FONT_POINT, BLUE);
				DrawText(FormatText("%i", players.pointsPj2), GetScreenWidth() - 140, 20, FONT_POINT, RED);
				break;

			case fight:
				DrawRectangleRec(pointsBar.rec, WHITE);
				break;
			}
		}

		void Input()
		{
			if (IsKeyPressed(KEY_ESCAPE)) 
			{
				Game_Manager::state = Game_Manager::menu;
			}

			if (IsKeyPressed(KEY_ZERO))
			{
				players.keyPress = KEY_ZERO;
			}
			else if (IsKeyPressed(KEY_ONE))
			{
				players.keyPress = KEY_ONE;
			}
			else if (IsKeyPressed(KEY_Q))
			{
				players.keyPress = KEY_Q;
			}
			else if (IsKeyPressed(KEY_W))
			{
				players.keyPress = KEY_W;
			}
			else if (IsKeyPressed(KEY_E))
			{
				players.keyPress = KEY_E;
			}
			else if (IsKeyPressed(KEY_R))
			{
				players.keyPress = KEY_R;
			}
			else if (IsKeyPressed(KEY_T))
			{
				players.keyPress = KEY_T;
			}
			else if (IsKeyPressed(KEY_Y))
			{
				players.keyPress = KEY_Y;
			}
			else if (IsKeyPressed(KEY_U))
			{
				players.keyPress = KEY_U;
			}
			else if (IsKeyPressed(KEY_I))
			{
				players.keyPress = KEY_I;
			}
			else if (IsKeyPressed(KEY_O))
			{
				players.keyPress = KEY_O;
			}
			else if (IsKeyPressed(KEY_P))
			{
				players.keyPress = KEY_P;
			}
			else if (IsKeyPressed(KEY_A))
			{
				players.keyPress = KEY_A;
			}
			else if (IsKeyPressed(KEY_S))
			{
				players.keyPress = KEY_S;
			}
			else if (IsKeyPressed(KEY_D))
			{
				players.keyPress = KEY_D;
			}
			else if (IsKeyPressed(KEY_F))
			{
				players.keyPress = KEY_F;
			}
			else if (IsKeyPressed(KEY_G))
			{
				players.keyPress = KEY_G;
			}
			else if (IsKeyPressed(KEY_H))
			{
				players.keyPress = KEY_H;
			}
			else if (IsKeyPressed(KEY_J))
			{
				players.keyPress = KEY_J;
			}
			else if (IsKeyPressed(KEY_K))
			{
				players.keyPress = KEY_K;
			}
			else if (IsKeyPressed(KEY_L))
			{
				players.keyPress = KEY_L;
			}
			else if (IsKeyPressed(KEY_Z))
			{
				players.keyPress = KEY_Z;
			}
			else if (IsKeyPressed(KEY_X))
			{
				players.keyPress = KEY_X;
			}
			else if (IsKeyPressed(KEY_C))
			{
				players.keyPress = KEY_C;
			}
			else if (IsKeyPressed(KEY_V))
			{
				players.keyPress = KEY_V;
			}
			else if (IsKeyPressed(KEY_B))
			{
				players.keyPress = KEY_B;
			}
			else if (IsKeyPressed(KEY_N))
			{
				players.keyPress = KEY_N;
			}
			else if (IsKeyPressed(KEY_M))
			{
				players.keyPress = KEY_M;
			}
			else
			{
				players.keyPress = 0;
			}
		}
	}
}