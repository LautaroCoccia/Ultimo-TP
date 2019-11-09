#include "players.h"

#include "raylib.h"

namespace Keyboard_Breaker
{
	namespace Player
	{
		PLAYER players;

		void Initialice() 
		{
			players.keyPress = 0;
			players.pointsPj1 = 0;
			players.pointsPj2 = 0;
			players.win = false;
		}

		void DrawPoints()
		{
			DrawText(FormatText("%i", players.pointsPj1), 40, 20, 40, BLUE);
			DrawText(FormatText("%i", players.pointsPj1), GetScreenWidth() - 60, 20, 40, RED);
		}

		void Input()
		{
			if (IsKeyPressed(KEY_Q))
			{
				players.keyPress = KEY_Q;
			}
			if (IsKeyPressed(KEY_W))
			{
				players.keyPress = KEY_W;
			}
			if (IsKeyPressed(KEY_E))
			{
				players.keyPress = KEY_E;
			}
			if (IsKeyPressed(KEY_R))
			{
				players.keyPress = KEY_R;
			}
			if (IsKeyPressed(KEY_T))
			{
				players.keyPress = KEY_T;
			}
			if (IsKeyPressed(KEY_Y))
			{
				players.keyPress = KEY_Y;
			}
			if (IsKeyPressed(KEY_U))
			{
				players.keyPress = KEY_U;
			}
			if (IsKeyPressed(KEY_I))
			{
				players.keyPress = KEY_I;
			}
			if (IsKeyPressed(KEY_O))
			{
				players.keyPress = KEY_O;
			}
			if (IsKeyPressed(KEY_P))
			{
				players.keyPress = KEY_P;
			}
			if (IsKeyPressed(KEY_A))
			{
				players.keyPress = KEY_A;
			}
			if (IsKeyPressed(KEY_S))
			{
				players.keyPress = KEY_S;
			}
			if (IsKeyPressed(KEY_D))
			{
				players.keyPress = KEY_D;
			}
			if (IsKeyPressed(KEY_F))
			{
				players.keyPress = KEY_F;
			}
			if (IsKeyPressed(KEY_G))
			{
				players.keyPress = KEY_G;
			}
			if (IsKeyPressed(KEY_H))
			{
				players.keyPress = KEY_H;
			}
			if (IsKeyPressed(KEY_J))
			{
				players.keyPress = KEY_J;
			}
			if (IsKeyPressed(KEY_K))
			{
				players.keyPress = KEY_K;
			}
			if (IsKeyPressed(KEY_L))
			{
				players.keyPress = KEY_L;
			}
			if (IsKeyPressed(KEY_Z))
			{
				players.keyPress = KEY_Z;
			}
			if (IsKeyPressed(KEY_X))
			{
				players.keyPress = KEY_X;
			}
			if (IsKeyPressed(KEY_C))
			{
				players.keyPress = KEY_C;
			}
			if (IsKeyPressed(KEY_V))
			{
				players.keyPress = KEY_V;
			}
			if (IsKeyPressed(KEY_B))
			{
				players.keyPress = KEY_B;
			}
			if (IsKeyPressed(KEY_N))
			{
				players.keyPress = KEY_N;
			}
			if (IsKeyPressed(KEY_M))
			{
				players.keyPress = KEY_M;
			}
		}
	}
}