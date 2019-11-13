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

		void Initialice()
		{
			players.keyPress = 0;
			players.pointsPj1 = 0;
			players.pointsPj2 = 0;

			// fight mode
			pointsBar.rec.height = 30.0f;
			pointsBar.rec.width = 300.0f;
			pointsBar.rec.x = (GetScreenWidth()/2 - pointsBar.rec.width/2);
			pointsBar.rec.y = 20;
			pointsBar.movement = 50;
		}

		void DrawPoints()
		{
			switch (modes)
			{
			case normal:
				DrawText(FormatText("%i", players.pointsPj1), 40, 20, 40, BLUE);
				DrawText(FormatText("%i", players.pointsPj2), GetScreenWidth() - 60, 20, 40, RED);
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

			if (IsKeyDown(KEY_Q))
			{
				players.keyPress = KEY_Q;
			}
			else if (IsKeyDown(KEY_W))
			{
				players.keyPress = KEY_W;
			}
			else if (IsKeyDown(KEY_E))
			{
				players.keyPress = KEY_E;
			}
			else if (IsKeyDown(KEY_R))
			{
				players.keyPress = KEY_R;
			}
			else if (IsKeyDown(KEY_T))
			{
				players.keyPress = KEY_T;
			}
			else if (IsKeyDown(KEY_Y))
			{
				players.keyPress = KEY_Y;
			}
			else if (IsKeyDown(KEY_U))
			{
				players.keyPress = KEY_U;
			}
			else if (IsKeyDown(KEY_I))
			{
				players.keyPress = KEY_I;
			}
			else if (IsKeyDown(KEY_O))
			{
				players.keyPress = KEY_O;
			}
			else if (IsKeyDown(KEY_P))
			{
				players.keyPress = KEY_P;
			}
			else if (IsKeyDown(KEY_A))
			{
				players.keyPress = KEY_A;
			}
			else if (IsKeyDown(KEY_S))
			{
				players.keyPress = KEY_S;
			}
			else if (IsKeyDown(KEY_D))
			{
				players.keyPress = KEY_D;
			}
			else if (IsKeyDown(KEY_F))
			{
				players.keyPress = KEY_F;
			}
			else if (IsKeyDown(KEY_G))
			{
				players.keyPress = KEY_G;
			}
			else if (IsKeyDown(KEY_H))
			{
				players.keyPress = KEY_H;
			}
			else if (IsKeyDown(KEY_J))
			{
				players.keyPress = KEY_J;
			}
			else if (IsKeyDown(KEY_K))
			{
				players.keyPress = KEY_K;
			}
			else if (IsKeyDown(KEY_L))
			{
				players.keyPress = KEY_L;
			}
			else if (IsKeyDown(KEY_Z))
			{
				players.keyPress = KEY_Z;
			}
			else if (IsKeyDown(KEY_X))
			{
				players.keyPress = KEY_X;
			}
			else if (IsKeyDown(KEY_C))
			{
				players.keyPress = KEY_C;
			}
			else if (IsKeyDown(KEY_V))
			{
				players.keyPress = KEY_V;
			}
			else if (IsKeyDown(KEY_B))
			{
				players.keyPress = KEY_B;
			}
			else if (IsKeyDown(KEY_N))
			{
				players.keyPress = KEY_N;
			}
			else if (IsKeyDown(KEY_M))
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